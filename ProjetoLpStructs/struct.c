//
//  struct.c
//  ProjetoLpStructs
//
//  Created by Pedro Coutinho on 20/12/17.
//  Copyright © 2017 Pedro Coutinho. All rights reserved.
//

#include "struct.h"


int main_structs(){
    int freq=0;
    //char file1[]= "/Users/antonioferreira/Documents/LP/ProjetoLP1/libs/conversa1.txt", "r");
    char file1[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/conversa1.txt";
    
    //char file2[]= "/Users/antonioferreira/Documents/LP/ProjetoLP1/libs/conversa2.txt", "r");
    char file2[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/conversa2.txt";
    
    //char file3[]= "/Users/antonioferreira/Documents/LP/ProjetoLP1/libs/conversa3.txt", "r");
    char file3[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/conversa3.txt";
    
    /*char file_write[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/corpus.txt";
     char file_bin[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/corpus_bin.txt";
     */
    
    
    
    CORPUS cp1 = {NULL, 0, 0, NULL,NULL, 0,0};
    add_user(&cp1, "Joaquim");
    add_user(&cp1, "Pedro");
    add_user(&cp1, "Antonio");
    add_user(&cp1, "Manuel");
    add_user(&cp1, "Jorge");
    
    if(!read_file(&cp1, file1)){
        printf("Error\n");
    }
    /*
    if(!read_file(&cp1, file2)){
        printf("Error\n");
    }
    if(!read_file(&cp1, file3)){
        printf("Error\n");
    }
    */
    print_conversa(cp1);
    //remover_conversa(&cp1,0);
    //conversas_utilizador(cp1,3);
    // print_conversa(cp1);
    
    //freq=ferquencia_termo(cp1, "Ola");
    //printf("A palavra Ola aparece %d vezes no corpus!\n", freq);
    //write_corpus_file(cp1, file_write);
    //write_corpus_bin(cp1, file_bin);
    //palavras_comuns(cp1,"surf");
    //printf("Bag_of_word Corpus\n\n");
    //printMatrix(cp1.bag_of_word_corpus, cp1.n_insercoes_bag_of_word_corpus);
    return 0;
}

void add_user(CORPUS * cp1, char* name){
    UTILIZADOR * newUser = (UTILIZADOR*)malloc(sizeof(UTILIZADOR));
    newUser->nome = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(newUser->nome, name);
    newUser->id_utilizador = cp1->number_of_users;
    
    if (cp1->users_size == 0){
        cp1->pUtilizador = (UTILIZADOR*)malloc(sizeof(UTILIZADOR) * 10);
        cp1->users_size = 10;
    }
    
    *(cp1->pUtilizador + (cp1->number_of_users++)) = *newUser;
}

CONVERSA * insert_conversa_to_corpus(CORPUS * cp1){
    CONVERSA * conversa = (CONVERSA*)malloc(sizeof(CONVERSA));
    conversa->tamanho = 0;
    conversa->n_insercoes = 0;
    conversa->pfirst_menssagem = NULL;
    conversa->bag_of_word_conversa = NULL;
    conversa->tamanho_bag_of_word_conversa = 0;
    conversa->n_insercoes_bag_of_word_conversa = 0;
    conversa->pnext = NULL;
    
    if (cp1->pfirst_conversa == NULL){
        conversa->id = 0;
        cp1->pfirst_conversa = conversa;
        return conversa;
    }
    
    CONVERSA * aux = cp1->pfirst_conversa;
    int i = 1;
    
    while(aux->pnext != NULL){
        i++;
        aux = aux->pnext;
    }
    
    conversa->id = i;
    aux->pnext = conversa;
    return conversa;
}

void insert_message(CONVERSA * conversa, int user, char * message, char * time){
    MENSAGEM * msg = (MENSAGEM*)malloc(sizeof(MENSAGEM));
    
    msg->utilizador = user;
    
    if (time == NULL){
        time = get_current_time();
    }
    
    msg->timestamp = (char*)malloc(sizeof(char) * strlen(time));
    strcpy(msg->timestamp, time);
    
    msg->text = (char*)malloc(sizeof(char) * strlen(message));
    strcpy(msg->text, message);
    
    if (conversa->tamanho == conversa->n_insercoes){
        conversa->pfirst_menssagem = (MENSAGEM*)realloc(conversa->pfirst_menssagem, sizeof(MENSAGEM) * (conversa->tamanho + 10));
        conversa->tamanho+=10;
    }
    
    *(conversa->pfirst_menssagem + (conversa->n_insercoes++)) = *msg;
}

char * get_current_time(){
    time_t rawtime;
    struct tm * timeinfo;
    
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    return asctime (timeinfo);
}

int read_file(CORPUS * corpus, char file[]){
    FILE *fp=NULL;
    char ch[100];
    int id;
    char * text;
    char * time = NULL;
    
    CONVERSA * conversa = insert_conversa_to_corpus(corpus);
    
    fp = fopen(file, "r");
    
    if(fp == NULL){
        return 0;
    }
    
    int size = 0;
    char ** aux_matrix = NULL;
    
    while(fgets(ch, 100, fp)){
        id = atoi(strtok(ch, ":"));
        text = strtok(NULL, "|");
        time = strtok(NULL, "\n");
        if (text != NULL && time != NULL){
            insert_message(conversa, id, text, time);
            
            aux_matrix = string_to_matrix(text, &size);
           
            conversa->bag_of_word_conversa = bag_of_words(aux_matrix, size, conversa->bag_of_word_conversa, &conversa->tamanho_bag_of_word_conversa, &conversa->n_insercoes_bag_of_word_conversa);


            //so preencher corpus quando tiver todas as conversas
           // corpus->bag_of_word_corpus=bag_of_words(aux_matrix, size, corpus->bag_of_word_corpus, &corpus->tamanho_bag_of_word_corpus, &corpus->n_insercoes_bag_of_word_corpus);
        }
        
    }
    
    fclose(fp);
    return 1;
}

void print_conversa(CORPUS corpus){
    CONVERSA * conversa = corpus.pfirst_conversa;
    MENSAGEM * mensagem = NULL;
    while (conversa != NULL){
        printf("\n\tconversa %d\n",conversa->id);
        printf("\tBag of word:\n");
        printMatrix(conversa->bag_of_word_conversa, conversa->n_insercoes_bag_of_word_conversa);
        
        printf("\tMensagens:\n");
        
        for (int i = 0; i < conversa->n_insercoes; i++){
            mensagem = (conversa->pfirst_menssagem + i);
            printf("%d  %s   %s\n", mensagem->utilizador,mensagem->text, mensagem->timestamp);
        }
        conversa = conversa->pnext;
    }
}

void remover_conversa(CORPUS *cp, int remove){
    CONVERSA *ptr, *antes;
    if (cp->pfirst_conversa==NULL)
    {
        printf("Nao existem conversas.\n");  // Lista vazia !!!
        return;
    }
    else
    {   // Caso a lista nao esteja vazia
        ptr = cp->pfirst_conversa;
        antes = cp->pfirst_conversa;
        while (ptr !=NULL)
        {
            if (ptr->id == remove) // achou !!
            {
                if (ptr == cp->pfirst_conversa) // se esta removendo o primeiro da lista
                {
                    cp->pfirst_conversa = ptr->pnext;
                    free(ptr);
                    printf("Removeu a conversa %d da lista\n", remove);// removeu !!
                    return;
                }
                else  // esta removendo do meio da lista
                {
                    antes->pnext = ptr->pnext;  // Refaz o encadeamento
                    //free(ptr);                // Libera a area do nodo
                    printf("Removeu a conversa %d da lista\n", remove);// removeu !!
                    return;
                }
            }
            else  // continua procurando no prox. nodo
            {
                antes = ptr;
                ptr = ptr->pnext;
            }
        }
        return; // Nao achou !!!
    }
}


void conversas_utilizador(CORPUS corpus, int id){
    CONVERSA * conversa = corpus.pfirst_conversa;
    MENSAGEM * mensagem = NULL;
    
    while (conversa != NULL){
        for (int i = 0; i < conversa->n_insercoes; i++){
            mensagem = (conversa->pfirst_menssagem + i);
            if(id==mensagem->utilizador){
                printf("O utilizador %d participa na conversa %d\n", id, conversa->id);
                break;
            }
        }
        conversa = conversa->pnext;
    }
}

void palavras_comuns(CORPUS cp, char word[]){
    for(int i=0;i<cp.n_insercoes_bag_of_word_corpus;i++){
        if(strstr(cp.bag_of_word_corpus[i], word)!=0){
            printf("%s   ->   %s\n", word, cp.bag_of_word_corpus[i]);
        }
    }
}

int ferquencia_termo(CORPUS cp, char termo[]){
    int freq=0;
    
    return freq;
}

//copia uma string para outra dinamica
char* create_copy_dyn_string(char str[]){
    char *paux= NULL;
    paux=(char*)malloc(sizeof(char)*(strlen(str)+1));
    strcpy(paux,str);//copia de str para paux
    return paux;
}

char ** string_to_matrix(char * string, int * matrix_size){
    *matrix_size = 0;
    int stringMatrixSize = 10;
    char ** stringMatrix = create_dynamic_matrix(&stringMatrixSize, stringMatrixSize);
    
    char * stringClone = (char*)malloc(sizeof(char) * strlen(string));
    strcpy(stringClone, string);
    
    int removedNewLineFlag = 0;
    char * token = strtok(stringClone, "\n");
    
    if (strlen(token) != strlen(string))
        removedNewLineFlag = 1;
    
    char specialCaracters[] = ",.!?";
    char * aux = NULL;
    
    token = strtok(token, " ");
    while (token!=NULL) {
        if ((aux = verify_delimiter(token, specialCaracters)) != NULL){
            
            if (strlen(strstr(token, aux)) == 1){
                remove_delimiter(token, aux);
                insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, token);
                insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, token);
                
                insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, aux);
            }else{
                remove_delimiter(token, aux);
                insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, aux);
                insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, token);
            }
        }else{
            insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, token);
        }
        
        token = strtok(NULL, " ");
        if (token != NULL){
            insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, " ");
        }
    }
    
    if (removedNewLineFlag){
        insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, "\n");
    }
    return stringMatrix;
}

void insert_string_into_matriz(char ** matrix, int * insertionsNumber, int * matrixSize, char * string){
    if (*insertionsNumber >= *matrixSize)
        add_more_lines(matrix, matrixSize, 10);
    
    *(matrix + (*insertionsNumber)) = (char*)malloc(sizeof(char) * strlen(string));
    strcpy(*(matrix + ((*insertionsNumber)++)), string);
}

/**
 *@brief remove_delimiter remover o delimitador encontrado
 *@param remove_delimiter delimitador
 *@param string string onde esta o delimitador que queremos remover
 */
void remove_delimiter(char* string, char* remove_delimiter){
    char * newString = (char*)malloc(sizeof(char));
    char * aux = NULL;
    long initialPos, finalPos;
    int currentSize = 1;
    while((aux = strstr(string, remove_delimiter)) != NULL){
        initialPos = strlen(string) - strlen(aux);
        finalPos = initialPos + strlen(aux);
        
        for (long i = initialPos; i<finalPos; i++){
            string[i] = '\0';
        }
    }
    
    for (int i = 0, j=0; i<strlen(string); i++){
        if (string[i] != '\0'){
            newString = (char*)realloc(newString, sizeof(char) * (currentSize++));
            newString[j++] = string[i];
        }
    }
    
    string = (char*)realloc(newString, strlen(string) * sizeof(char));
}

/**
 *@brief verify_delimiter verifica se existe um delimitador
 *@param delimiter conjunto de caracteres que podem ser um delimitador
 *@param string onde queremos procurar o delimitador
 */
char* verify_delimiter(char delimiter[], char *string){
    char *pChar = malloc(sizeof(char));
    
    for (int i = 0; i<strlen(delimiter); i++){
        *pChar = delimiter[i];
        if (strstr(string, pChar) != NULL){
            return pChar;
        }
    }
    return NULL;
}

char ** bag_of_words(char ** matrix, int size, char ** bag_of_word, int *size_bw, int *inserted_size){
    if (bag_of_word == NULL){
        bag_of_word = create_dynamic_matrix(size_bw, 100);
        *inserted_size = 0;
    }
    
    int exist = 0;
    for (int i=0;i<size;i++){
        for (int j=0;j<(*inserted_size);j++){
            if (strcmp(*(bag_of_word+j), *(matrix+i))==0){
                exist=1;
                break;
            }
        }
        if (exist == 0){
            insert_string_into_matriz(bag_of_word,inserted_size,size_bw,*(matrix+i));
        }
        exist=0;
    }
    return bag_of_word;
}


char ** create_dynamic_matrix(int * number_of_lines, int number_lines){
    char ** aux = NULL;
    //cria n linhas
    /*aux = (char**)malloc(sizeof(char**));
     *aux = (char*)malloc(sizeof(char*) * number_lines);
     */
    aux=(char**)calloc(number_lines, sizeof(char*));
    
    //guarda o numero de linhas
    *number_of_lines = number_lines;
    return aux;
}



char ** add_more_lines(char ** matrix, int * number_of_lines, int number_to_add){
    *matrix = (char*)realloc(*matrix, sizeof(char*) * ((*number_of_lines) + number_to_add));
    for (int i = (*number_of_lines); i<((*number_of_lines) + number_to_add); i++)
        *(matrix + i) = NULL;
    *number_of_lines = (*number_of_lines) + number_to_add;
    return matrix;
}




void write_corpus_file(CORPUS cp, char file[]){
    FILE *fp=NULL;
    
    fp = fopen(file, "w");
    
    CONVERSA * conversa = cp.pfirst_conversa;
    MENSAGEM * mensagem = NULL;
    while (conversa != NULL){
        fprintf(fp,"\n\tconversa %d\n",conversa->id);
        fprintf(fp,"\tBag of word:\n");
        //printMatrix(conversa->bag_of_word_conversa, conversa->n_insercoes_bag_of_word_conversa);
        fprintf(fp,"\tMensagens:\n");
        
        for (int i = 0; i < conversa->n_insercoes; i++){
            mensagem = (conversa->pfirst_menssagem + i);
            fprintf(fp,"%d   %s   %s\n", mensagem->utilizador, mensagem->text, mensagem->timestamp);
        }
        conversa = conversa->pnext;
    }
}

void write_corpus_bin(CORPUS cp, char file[]){
    FILE * fp = NULL;
    CONVERSA * conversa = cp.pfirst_conversa;
    MENSAGEM * mensagem = NULL;
    //int len=0;
    if((fp=fopen(file, "wb"))==NULL){
        fprintf(stdout, "...Erro Abrir ficheiro");
        return;
    }
    //fwrite("teste", strlen("teste"), 1, fp);
    while (conversa != NULL){
        //printMatrix(conversa->bag_of_word_conversa, conversa->n_insercoes_bag_of_word_conversa);
        
        //fwrite(conversa->n_insercoes,sizeof(int),1, fp);
        for (int i = 0; i < conversa->n_insercoes; i++){
            mensagem = (conversa->pfirst_menssagem + i);
            //fprintf(fp,"%d   %s   %s\n", mensagem->utilizador, mensagem->text, mensagem->timestamp);
            
            
        }
        conversa = conversa->pnext;
    }
    
}

void printMatrix(char ** matrix, int number_of_lines_used){
    if (matrix != NULL){
        for (int i = 0; i<number_of_lines_used; i++){
            printf("%s\n", *(matrix+i));
        }
    }
    printf("-----------\n");
}







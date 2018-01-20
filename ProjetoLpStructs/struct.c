//
//  struct.c
//  ProjetoLpStructs
//
//  Created by Pedro Coutinho on 20/12/17.
//  Copyright © 2017 Pedro Coutinho. All rights reserved.
//

#include "struct.h"


int main_structs(){
   char file1[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/conversa1.txt";
    char file2[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/conversa2.txt";
    char file3[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/conversa3.txt";
    
    char file4[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/corpus.txt";
    
   char file_write[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/corpus.txt";
    //char file_bin[]="/Users/pedrocoutinho/Documents/ProjetoLpStructs/ProjetoLpStructs/corpus_bin.txt";
    
    CORPUS cp1 = {NULL, 0, 0, NULL,NULL, 0};
    
    add_user(&cp1, "Toze");
    add_user(&cp1, "Pedro");
    add_user(&cp1, "Antonio");
    add_user(&cp1, "Adolfo");
    add_user(&cp1, "Tina");
    
    cp1=*read_corpus(&cp1, file4);
    
   
    /*printf("Read corpus\n\n\n\n\n\n");
    print_conversa(cp1);
    printf("\n\n\n\n\n\n");
   
    if(!read_file(&cp1, file1)){
     printf("Error\n");
     }
     if(!read_file(&cp1, file2)){
     printf("Error\n");
     }
     if(!read_file(&cp1, file3)){
     printf("Error\n");
     }
   */
    print_conversa(cp1);
    
    /*while(cp2.pfirst_conversa!=NULL){
    
        for(int i=0;i<cp2.pfirst_conversa->n_insercoes; i++){
            merge_sort_td((cp2.pfirst_conversa->pfirst_menssagem+i), (cp2.pfirst_conversa->pfirst_menssagem), 0, cp2.pfirst_conversa->n_insercoes);
            
            //printf("---------%s\n", (cp2.pfirst_conversa->pfirst_menssagem+i)->timestamp);

        }
        cp2.pfirst_conversa=cp2.pfirst_conversa->pnext;
    }
    */
   //print_conversa(cp2);
    /*
    MergeSort(&cp1.bag_of_word_corpus, cp1.n_insercoes_bag_of_word_corpus);
     CONVERSA * c = cp1.pfirst_conversa;
     while(c->pnext!=NULL){
     MergeSort(&c->bag_of_word_conversa, c->n_insercoes_bag_of_word_conversa);
     c=c->pnext;
     }
     MergeSort(&c->bag_of_word_conversa, c->n_insercoes_bag_of_word_conversa);
    */
   /* print_conversa(cp1);
     printf("\n\n");
     print_bag_of_word_corpus(cp1);
     printf("\n\n");
     */
     /*printf("Bag_of_word Corpus\n\n");
     PALAVRA *p = cp1.bag_of_word_corpus;
     for(int i=0;i<cp1.n_insercoes_bag_of_word_corpus;i++){
     
     //printf("%s->%d\n", p->palavra, p->freq_abs); p->pos->indice_mensagem, p->pos->pos
     // while(p->pos->pospnext!=NULL){
     
     //printf("%s\t\t\t|%d\t\t\t|\n",p->palavra, p->freq_abs);
     printf("|%s|\n", p->palavra);
     //  p->pos=p->pos->pospnext;
     //}
     p=p->pnext;
     }*/
    
    
    /*
    remover_conversa(&cp1,0);
    print_conversa(cp1);
    printf("\n\n");
    
    
    printf("\n\n");
    int id_mensagem=2;
    int id_conversa=0
    remover_mensagem(id_mensagem, id_conversa, &cp1);
    print_conversa(cp1);
    printf("\n\n");
    
     print_bag_of_word_corpus(cp1);
     */
     //int freq=0;
     //int nt=0;
    // char termo[]="Sim";
     //freq=tf(cp1, termo);
     //nt=idf_aux(cp1, termo);
     //printf("\n\n");
     //printf("A palavra %s aparece %d vezes no corpus! E aparecem em %d conversas\n",termo, freq, nt);
     //printf("\n\n");
     
     /*int nConversas = 0;
     nConversas = numero_conversas(cp1);
     
    tfIdf(cp1, termo);
     */
     /*
     palavras_comuns(cp1,"Va");
     printf("\n\n");
     
     
     
     printf("\n\n");
     conversas_utilizador(cp1,1);
     printf("\n\n");
    */
    
    
   // write_corpus_file(cp1, file_write);
    /* write_corpus_bin(cp1, file_bin);
     */
   /*
    char pal[]= "sim";
    int co = dicionario(pal);
    */
    return 0;
}


/**
 *@briefprint_bag_of_word_corpus função auxiliar que imprime a bag of word do corpus
 *@param cp1 CORPUS que se pretende imprimir
 */
void print_bag_of_word_corpus(CORPUS cp1){
    printf("Bag_of_word Corpus\n\n");
    PALAVRA *p = cp1.bag_of_word_corpus;
    for(int i=0;i<cp1.n_insercoes_bag_of_word_corpus;i++){
        
        //printf("%s->%d\n", p->palavra, p->freq_abs); p->pos->indice_mensagem, p->pos->pos
        // while(p->pos->pospnext!=NULL){
        
        //printf("%s\t\t\t|%d\t\t\t|\n",p->palavra, p->freq_abs);
        printf("|  %s  |   %d  | \n ", p->palavra, p->freq_abs);
        
    
        //  p->pos=p->pos->pospnext;
        //}
        p=p->pnext;
    }
}

/**
 *@brief add_user função para adicionar os utilizadores
 *@param cp1 corpus onde vai ser adicionado o utilizador
 *@param name nome do utilizador
 */
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

/**
 *@brief insert_conversa_to_corpus inserir cada conversa no corpus alocando memoria para cada uma antes de a inserir
 *@param cp1 corpus onde é inserida a conversa
 */
CONVERSA * insert_conversa_to_corpus(CORPUS * cp1){
    CONVERSA * conversa = (CONVERSA*)malloc(sizeof(CONVERSA));
    conversa->tamanho = 0;
    conversa->n_insercoes = 0;
    conversa->pfirst_menssagem = NULL;
    conversa->bag_of_word_conversa = NULL;
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


/**
 *@brief insert_message inserir uma mensagem numa conversa depois de alocar espaço em memória para cada mensagem
 *@param conversa conversa onde vai ser inserida a mensagem
 *@param user id do utilizador que enviou a mensagem
 *@param message mensagem propriamente dita
 *@param time hora a que a mensagem foi enviada
 */
CONVERSA * insert_message(CONVERSA * conversa, int user, char * message, char * time){
    /*
     void insert_message(CONVERSA * conversa, int user, char * message, char * time){

     MENSAGEM * msg = (MENSAGEM*)malloc(sizeof(MENSAGEM));
    msg->utilizador = user;
    
    if(time == NULL){
        time = get_current_time();
    }
    
    msg->timestamp = (char*)malloc(sizeof(char) * strlen(time)+1);
    strcpy(msg->timestamp, time);
    
    msg->text = (char*)malloc(sizeof(char) * strlen(message)+1);
    strcpy(msg->text, message);
    
    msg->id=conversa->n_insercoes;
    //printf("-----------------------%d\n",conversa->n_insercoes);
    if (conversa->tamanho == conversa->n_insercoes){
        conversa->pfirst_menssagem = (MENSAGEM*)realloc(conversa->pfirst_menssagem, sizeof(MENSAGEM) * (conversa->tamanho + 10));
        conversa->tamanho+=10;
    }
   *(conversa->pfirst_menssagem + (conversa->n_insercoes++)) = *msg;
*/
    
    if (conversa->tamanho == conversa->n_insercoes){
        
        conversa->pfirst_menssagem = (MENSAGEM*)realloc(conversa->pfirst_menssagem, sizeof(MENSAGEM) * (conversa->tamanho + 10));
        conversa->tamanho+=10;
    }

    MENSAGEM * msg = conversa->pfirst_menssagem;
    
    (msg+conversa->n_insercoes)->id = conversa->n_insercoes;
    (msg+conversa->n_insercoes)->utilizador=user;
    (msg+conversa->n_insercoes)->timestamp = (char*)malloc(sizeof(char) * strlen(time)+1);
    strcpy((msg+conversa->n_insercoes)->timestamp, time);
    
    (msg+conversa->n_insercoes)->text = (char*)malloc(sizeof(char) * strlen(message)+1);
    strcpy((msg+conversa->n_insercoes)->text, message);
    //printf("------>>%s\n", message);
    
    conversa->n_insercoes++;

    
    return conversa;
}


char * get_current_time(){
    time_t rawtime;
    struct tm * timeinfo;
    
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    return asctime (timeinfo);
}


CORPUS* read_corpus(CORPUS * corpus, char file[]){
    FILE *fp=NULL;
    int id_utilizador = 0;
    char *text, aux[50];
    char *time = NULL;
    int n_conversas=0;
    int n_mensagens=0;
    int id_conversa=0;
    int size = 0;
    char **aux_matrix=NULL;
    
    CONVERSA * conversa = insert_conversa_to_corpus(corpus);
    
    fp = fopen(file, "r");
    
    if(fp == NULL){
        return 0;
    }else{
        fscanf(fp,"%*s %*s %*s %d",&n_conversas);
        for(int j=0;j<n_conversas;j++){
        fscanf(fp,"%*s %d %*s %*s %*s %d",&id_conversa, &n_mensagens);
           // printf("Numero conversas : %d Conversa: %d, numeroMensagens %d\n", n_conversas, id_conversa, n_mensagens);
            conversa->id=id_conversa;
            printf("CID()_%d\n",id_conversa);
            for(int i=0;i<n_mensagens;i++){
                conversa->n_insercoes=i;
                printf("i=%d\n", i);
                fscanf(fp,"%d %[^\n]s",&id_utilizador, aux);
                text=strtok(aux, "|");
                time=strtok(NULL, "\n");
                if(text != NULL && time != NULL){
                printf("%d     %s    %s\n", id_utilizador, text, time);
                    conversa = insert_message(conversa, id_utilizador, text, time);
                    aux_matrix = string_to_matrix(text, &size);
                }
                bag_of_words(aux_matrix, size, conversa, conversa->n_insercoes, corpus);
                preencher_bag_of_word_corpus(aux_matrix, size, conversa, corpus->pfirst_conversa->n_insercoes_bag_of_word_conversa, corpus);
            }
           // print_conversa(*corpus);
        }
    }
    fclose(fp);
    return corpus;
}


/**
 *@brief read_file lê as várias conversas e parte o seu texto com o auxilio do strtok na forma das estruturas
 *@param corpus corpus onde vão ser inseridas as conversas
 *@param file ficheiro de texto de onde vão ser lidas as conversas
 */
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
            
            conversa = insert_message(conversa, id, text, time);
            aux_matrix = string_to_matrix(text, &size);
            // int co = dicionario(aux_matrix);
            
            /*for(int i=0;i<size;i++){
                printf("->%s \t", aux_matrix[i]);
            int co = dicionario(aux_matrix[i]);
                aux_matrix[i]=create_copy_dyn_string(dicionario1(aux_matrix[i]));
            }*/
            
            bag_of_words(aux_matrix, size, conversa, conversa->n_insercoes, corpus);
            
            preencher_bag_of_word_corpus(aux_matrix, size, conversa, corpus->pfirst_conversa->n_insercoes_bag_of_word_conversa, corpus);
        }
    }
    fclose(fp);
    return 1;
}


/**
 *@brief print_conversa imprime as conversas
 *@param corpus de onde vão ser imprimidas as conversas
 */
void print_conversa(CORPUS corpus){
    CONVERSA * conversa = corpus.pfirst_conversa;
    MENSAGEM * mensagem = NULL;

    while (conversa!=NULL){
        printf("\n\tBag of word:\n");
        printMatrix(conversa->bag_of_word_conversa, conversa->n_insercoes_bag_of_word_conversa);
        printf("\n\tconversa %d\n",conversa->id);
        printf("\tMensagens:\n");
        for (int i = 0; i < conversa->n_insercoes; i++){
            mensagem = (conversa->pfirst_menssagem + i);
            
            printf("mens id: %d utilizador: %d  mensagem: %s data: %s\n", mensagem->id, mensagem->utilizador,mensagem->text, mensagem->timestamp);
            }
        conversa = conversa->pnext;
    }
}

/**
 *@brief remover_mensagem remove uma determinada mensagem
 *@param id_mensagem id da mensagem a remover
 *@param id_conversa id da conversa onde se encontra a mensagem
 *@param cp corpus onde está a conversa
 */
void remover_mensagem(int id_mensagem, int id_conversa,CORPUS *cp){
    CONVERSA * conversa = cp->pfirst_conversa;
    while(conversa!=NULL){
        if(conversa->id==id_conversa){
            MENSAGEM * mens = conversa->pfirst_menssagem;
            
            for(int i=0;i<conversa->n_insercoes;i++){
                
                if((mens+i)->id==id_mensagem){
                    /*printf("Apaga mensagem\n");
                     printf("Conversa dado: %d- conversa atual: %d Mensagem dada: %d- mens at: %d\n",id_conversa, conversa->id, id_mensagem, (mens+i)->id);
                     */
                    for(int j=i+1;j<conversa->n_insercoes;j++){
                        
                        (mens+i)->id=(mens+j)->id;
                        (mens+i)->utilizador=(mens+j)->utilizador;
                        (mens+i)->text=create_copy_dyn_string((mens+j)->text);
                        (mens+i)->timestamp=create_copy_dyn_string((mens+j)->timestamp);
                        i++;
                    }
                    
                    conversa->n_insercoes--;
                    
                    return;
                }else{
                    
                    printf("Mensagem nao existente\n");
                    
                    
                }
            }
        }else{
            conversa=conversa->pnext;
            
        }
    }
}

/**
 *@brief remover_conversa remove uma conversa do corpus
 *@param cp corpus onde está inserida a aconversa
 *@param remove id da conversa a remover
 */
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
        while (ptr !=NULL){
            if (ptr->id == remove){ // achou !!
                
                if (ptr == cp->pfirst_conversa){ // se esta removendo o primeiro da lista
                    
                    cp->pfirst_conversa = ptr->pnext;
                    free(ptr);
                    printf("Removeu a conversa %d da lista\n", remove);// removeu !!
                    return;
                }
                else{  // esta removendo do meio da lista
                    antes->pnext = ptr->pnext;  // Refaz o encadeamento
                    //free(ptr);                // Libera a area do nodo
                    printf("Removeu a conversa %d da lista\n", remove);// removeu !!
                    return;
                }
            }
            else{  // continua procurando no prox. nodo
                
                antes = ptr;
                ptr = ptr->pnext;
            }
        }
        return; // Nao achou !!!
    }
}

/**
 *@brief conversas_utilizador mostra as conversas de um utilizador
 *@param corpus onde é procurado o utilizador
 *@param id do utilizador que ze pretende encontrar
 */
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

/**
 *@brief palavras_comuns encontrar uma palavra que tenha como sub palavra "word"
 *@param cp corpus onde se vai procurar
 *@param word palavra que vai ser a sub palavra
 */
void palavras_comuns(CORPUS cp, char word[]){
    
    printf("Palavras comuns a %s:\n", word);
    int i=0;
    while(cp.bag_of_word_corpus->pnext!=NULL){
        if(strstr(cp.bag_of_word_corpus->palavra, word)!=NULL){
            printf("%d: %s\n", i, cp.bag_of_word_corpus->palavra);
            i++;
        }
        cp.bag_of_word_corpus=cp.bag_of_word_corpus->pnext;
    }
    
}


/**
 *@brief ferquencia_termo numero de vezes que aparece uma palavra
 *@param cp corpus
 *@param termo palavra que queremos saber a frequencia
 */
int tf(CORPUS cp, char termo[]){// tf
    int freq=0;
    while(cp.bag_of_word_corpus!=NULL){
        if(strcmp(cp.bag_of_word_corpus->palavra,termo)==0){
            freq=cp.bag_of_word_corpus->freq_abs;
        }
        cp.bag_of_word_corpus=cp.bag_of_word_corpus->pnext;
    }
    return freq;
}


float idf(CORPUS cp, char pal[], int nConversas){
    CONVERSA * conversa = cp.pfirst_conversa;
    int nt=0;
    float result=0;
    while (conversa != NULL){
        while(conversa->bag_of_word_conversa!=NULL){
            
            if(strcmp(pal, conversa->bag_of_word_conversa->palavra)==0){
                nt++;
            }
            conversa->bag_of_word_conversa=conversa->bag_of_word_conversa->pnext;
        }
        
        conversa=conversa->pnext;
        
    }
    
    float d = 1+nt;
    float x = nConversas/d;

    result = log10(x);
    return result;
    
}

int numero_conversas(CORPUS cp){
    int n = 0;
    CONVERSA * conversa = cp.pfirst_conversa;
    while (conversa != NULL){
        n++;
        conversa=conversa->pnext;
    }
    return n;
}

void tfIdf(CORPUS cp, char pal[]){
    int nConversas = numero_conversas(cp);
    printf("Numero de Conversas = %d\n", nConversas);
    int tf =0;
    int aux;
    float idf1 = idf1= idf(cp, pal, nConversas);
    printf("idf(%s)=%f\n", pal, idf1);
    CONVERSA * conversa = cp.pfirst_conversa;
        while(conversa!=NULL){
            tf=0;
            MENSAGEM * mensagem = conversa->pfirst_menssagem;
            for(int i=0; i<conversa->n_insercoes;i++){
                
                if((aux = strstr( (mensagem+i)->text, pal) != NULL)){
                    tf++;
                }
            }
            printf("%d\n", tf);
            printf("tfidf(%s, %d, %d)=%f\n", pal, conversa->id, nConversas, tf*idf1);
            
            conversa=conversa->pnext;
    }
}

/**
 *@brief create_copy_dyn_string copia uma string para outra
 *@param str o que desejamos copiar
 */
char* create_copy_dyn_string(char str[]){
    char *paux= NULL;
    paux=(char*)malloc(sizeof(char)*(strlen(str)+2));
    strcpy(paux,str);//copia de str para paux
    return paux;
}

/**
 *@brief string_to_matrix criar uma lista com todas a sºpalavras existentes na mensagem (bag of word)
 *@param string string que contem uma frase da mensagem
 *@param matrix_size tamanhao da mensagem
 */
char ** string_to_matrix(char * string, int * matrix_size){
    *matrix_size = 0;
    int stringMatrixSize = 10;
    char ** stringMatrix = create_dynamic_matrix(&stringMatrixSize, stringMatrixSize);
    
    char * stringClone = (char*)malloc(sizeof(char) * strlen(string));
    strcpy(stringClone, string);
    
    int removedNewLineFlag = 0; //auxiliar para verificação de caracter \n
    char * token = strtok(stringClone, "\n");
    
    if (strlen(token) != strlen(string)) // verifica se tem \n
        removedNewLineFlag = 1; //se tiver coloca a 1
    
    char specialCaracters[] = ",.!?";
    char * aux = NULL;
    
    token = strtok(token, " ");
    while (token!=NULL) {

        if ((aux = verify_delimiter(token, specialCaracters)) != NULL){
            remove_delimiter(token, aux);//remove o delimitador encostado a uma palavra
            insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, token);
            insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, aux);
        }else{
            insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, token);
        }
        
        token = strtok(NULL, " ");
        if (token != NULL){
            insert_string_into_matriz(stringMatrix, matrix_size, &stringMatrixSize, " ");
        }
    }
    
    if (removedNewLineFlag){ // se existir \n coloca-lo na bag of words
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
/**
 *@brief preencher_bag_of_word_corpus construir a bag of word do corpus
 *@param aux_matrix matriz onde estão as palavras a colocar na bag of word
 *@param size tamanho da matriz
 *@param cp corpus onde vai dicar a bag of word
 */
void preencher_bag_of_word_corpus(char **aux_matrix,int size, CONVERSA *conversa, int id, CORPUS *cp){
    
    PALAVRA * pal = NULL;
    POSICAO *pos = (POSICAO*)malloc(sizeof(POSICAO));
    
    pos->indice_mensagem=id;
    
    for(int i=0;i<size;i++){
        if ((pal = verifica_palavra_existente_corpus(cp, *(aux_matrix+i))) != NULL){
            

            //incrementa
            pal->freq_abs++;
            pos->pos = i;
            pos->pospnext = pal->pos;
            pal->pos = pos;
        }else{
            //insere
            pal = (PALAVRA*)malloc(sizeof(PALAVRA));
            pal->palavra = (char*)malloc(sizeof(char)*strlen(*(aux_matrix+i)));
            strcpy(pal->palavra, *(aux_matrix+i));
            pal->freq_abs = 1;
            pal->pnext = cp->bag_of_word_corpus;
            cp->bag_of_word_corpus = pal;
            cp->n_insercoes_bag_of_word_corpus++;
            pos->pos = i;
            pos->pospnext = NULL;
            pal->pos = pos;
        }
    }
}

/**
 *@brief preencher_bag_of_word_corpus construir a bag of word de cada conversa
 *@param matrix matriz onde estão as palavras a colocar na bag of word
 *@param size tamanho da matriz
 */
void bag_of_words(char ** matrix, int size, CONVERSA * conversa, int id, CORPUS *corpus){
    
    PALAVRA * pal = NULL;
    POSICAO *pos = (POSICAO*)malloc(sizeof(POSICAO));
    pos->indice_mensagem=id;
    for (int i=0;i<size;i++){
        if ((pal = verifica_palavra_existente(conversa, *(matrix+i))) != NULL){
            //incrementa
            pal->freq_abs++;
            pos->pos = i;
            pos->pospnext = pal->pos;
            pal->pos = pos;
        }else{
            //insere
            pal = (PALAVRA*)malloc(sizeof(PALAVRA));
            pal->palavra = (char*)malloc(sizeof(char)*strlen(*(matrix+i)));
            strcpy(pal->palavra, *(matrix+i));
            pal->freq_abs = 1;
            pal->pnext = conversa->bag_of_word_conversa;
            conversa->bag_of_word_conversa = pal;
            conversa->n_insercoes_bag_of_word_conversa++;
            pos->pos = i;
            pos->pospnext = NULL;
            pal->pos = pos;
        }
    }
}

/**
 *@brief verifica_palavra_existente verifica se uma palavra já esta na bag of word
 *@param conv conversa correspondente á bag_of_word em que pesquisamos
 *@param palavra palavra que vamos testar
*/
PALAVRA * verifica_palavra_existente(CONVERSA *conv, char *palavra){
    PALAVRA * pal = conv->bag_of_word_conversa;
    while ( pal != NULL ){

        if (strcmp(pal->palavra, palavra) == 0)
            return pal;

        pal = pal->pnext;
    }
    return NULL;
}

/**
 *@brief verifica_palavra_existente_corpus verifica se a palavra esta na bag of word para que nao existam palavras repetidas
 *@param cp corpus da mensagem onde pesquisamos
 *@param palavra palavra a testar
 */
PALAVRA * verifica_palavra_existente_corpus(CORPUS *cp, char *palavra){
    PALAVRA * pal = cp->bag_of_word_corpus;
    while ( pal != NULL ){
        if (strcmp(pal->palavra, palavra) == 0)
            
            return pal;
        
        pal = pal->pnext;
    }
    return NULL;
}


/**
 *@brief create_dynamic_matrix criar matriz
 *@param number_of_lines numero de linhas que estao a ser utilizadas
 *@param number_lines numero de linhas a inicializar
 */
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


/**
 * @brief add_more_lines
 * @param matrix matriz completa
 * @param number_of_lines numero de linhas que estao a ser utilizadas
 * @param number_to_add numero de linhas a adicionar
 */
char ** add_more_lines(char ** matrix, int * number_of_lines, int number_to_add){
    *matrix = (char*)realloc(*matrix, sizeof(char*) * ((*number_of_lines) + number_to_add));
    for (int i = (*number_of_lines); i<((*number_of_lines) + number_to_add); i++)
        *(matrix + i) = NULL;
    *number_of_lines = (*number_of_lines) + number_to_add;
    return matrix;
}



/**
 *@brief write_corpus_file escrever todas as conversas para um ficheiro de texto
 *@param cp corpus onde estao todas as conversas
 *@param file ficheiro de texto onde se pretende guardar as conversas/ o corpus
 */
void write_corpus_file(CORPUS cp, char file[]){
    FILE *fp=NULL;
    
    fp = fopen(file, "w");
    
    CONVERSA * conversa = cp.pfirst_conversa;
    MENSAGEM * mensagem = NULL;
    int nConversas = numero_conversas(cp);
    fprintf(fp,"Numero de conversa %d\n",nConversas);
    while (conversa != NULL){
        fprintf(fp,"conversa %d numero de mensagens %d\n",conversa->id, conversa->n_insercoes);
        for (int i = 0; i < conversa->n_insercoes; i++){
            mensagem = (conversa->pfirst_menssagem + i);
            fprintf(fp,"%d %s|%s\n", mensagem->utilizador, mensagem->text, mensagem->timestamp);
        }
        conversa = conversa->pnext;
    }
}

/**
 *@brief write_corpus_bin escrever todas as conversas para um ficheiro binário
 *@param cp corpus onde estao todas as conversas
 *@param file ficheiro onde se pretende guardar as conversas/ o corpus
 */
void write_corpus_bin(CORPUS cp, char file[]){
    FILE * fp = NULL;
    CONVERSA * conversa = cp.pfirst_conversa;
    MENSAGEM * mensagem = NULL;
    //int len=0;
    if((fp=fopen(file, "wb"))==NULL){
        fprintf(stdout, "...Erro Abrir ficheiro");
        return;
    }
    int n_ins=0;
    fwrite("teste", strlen("teste"), 1, fp);
    while (conversa != NULL){
        //printMatrix(conversa->bag_of_word_conversa, conversa->n_insercoes_bag_of_word_conversa);
        n_ins=conversa->n_insercoes;
        fwrite(&conversa->n_insercoes, sizeof(int),1, fp);
        fwrite(&conversa->id,sizeof(int),1, fp);
        for (int i = 0; i < conversa->n_insercoes; i++){
            mensagem = (conversa->pfirst_menssagem + i);
            
            fwrite(&mensagem->utilizador,sizeof(int),1, fp);
            fwrite(&mensagem->text,sizeof(char),sizeof(&mensagem->text), fp);
            fwrite(&mensagem->timestamp,sizeof(char),sizeof(&mensagem->timestamp), fp);
        }
        conversa = conversa->pnext;
    }
    
}

/**
 *@brief printMatrix imprimir as bag of word's
 *@param matrix matriz a imprimir
 *@param number_of_lines_used numero de palavras
 */
void printMatrix(PALAVRA * matrix, int number_of_lines_used){
    if (matrix != NULL){
        for (int i = 0; i<number_of_lines_used; i++){
            printf("Palavra: %s Frequencia:%d\n", matrix->palavra, matrix->freq_abs);
            // printf("Indice da mensagem  %d\n ", matrix->pos->indice_mensagem);
            matrix=matrix->pnext;
        }
    }
}


/* Function to insert a node at the beginging of the linked list */
void addElement(PALAVRA** list, char * new_data, int key)
{
    /* allocate node */
    PALAVRA* new_node =
    (PALAVRA*) malloc(sizeof(PALAVRA));
    
    new_node->palavra = (char *) malloc(sizeof(strlen(new_data)));
    
    /* put in the data  */
    strcpy(new_node->palavra,new_data);
    
    
    /* link the old list off the new node */
    new_node->pnext = (*list);
    
    /* move the head to point to the new node */
    (*list) = new_node;
}


/* Function to print nodes in a given linked list */
void printList(PALAVRA *node)
{
    while(node!=NULL)
    {
        printf(" ->%s\n", node->palavra);
        node = node->pnext;
    }
}

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(PALAVRA** list, int flag)
{
    PALAVRA* aux = *list;
    PALAVRA* a;
    PALAVRA* b;
    
    /* Base case -- length 0 or 1 */
    if ((aux == NULL) || (aux->pnext == NULL))
    {
        return;
    }
    
    /* Split aux into 'a' and 'b' sublists */
    FrontBackSplit(aux, &a, &b);
    
    /* Recursively sort the sublists */
    MergeSort(&a, flag);
    MergeSort(&b, flag);
    
    /* answer = merge the two sorted lists together */
    *list = Merge(a, b, flag);
}

PALAVRA* Merge(PALAVRA *a, PALAVRA *b, int flag)
{
    PALAVRA* result = NULL;
    
    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);
    
    /* Pick either a or b, and recur */
    if(flag){
        if (strcmp(a->palavra,b->palavra) < 0) {
            result = a;
            result->pnext = Merge(a->pnext, b, flag);
            
        } else {
            result = b;
            result->pnext = Merge(a, b->pnext, flag);
        }
    }
    
    return(result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
 and return the two lists using the reference parameters.
 If the length is odd, the extra node should go in the front list.
 Uses the fast/slow pointer strategy.  */
void FrontBackSplit(PALAVRA* source, PALAVRA** frontRef, PALAVRA** backRef){
    PALAVRA* fast;
    PALAVRA* slow;
    if (source==NULL || source->pnext==NULL){
        /* length < 2 cases */
        *frontRef = source;
        *backRef = NULL;
    }
    else{
        slow = source;
        fast = source->pnext;
        
        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL){
            fast = fast->pnext;
            if (fast != NULL){
                slow = slow->pnext;
                //fast = fast->pnext;
            }
        }
        
        /* 'slow' is before the midpoint in the list, so split it in two
         at that point. */
        *frontRef = source;
        *backRef = slow->pnext;
        slow->pnext = NULL;
    }
}



/*--------------------------------------*/
/*--------------------------------------*/
/*--------------------------------------*/
/*--------------------------------------*/

int levenshtein(char *s1, char *s2) {
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
            matrix[x][y] = MIN3(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));
    
    return(matrix[s2len][s1len]);
}


char* dicionario1(char pal[]){
    
    char dic[dicSize][10]={"Ola","Oi","bem","?","sim","contigo","tambem","Queres","ir","vamos","cinema","Pode","ser","!","ao","indo","la","surf","bota","ta","Antonio","Coutinho","Lp","Portugues","Ya",",", " ", ".", "!"};
    int ord[27];


    int min=500, indexmin=0;
    char aux[dicSize];
    for(int i=0;i<dicSize;i++){
        for(int j=0;j<dicSize;j++){
            aux[j]=dic[i][j];
        }
        ord[i]=levenshtein(aux, pal);
        
        if(ord[i]==0){
            printf("Palavra inserida corretamente\n");
            return 0;
        }
    }
    for(int h=0;h<dicSize;h++){
        if(ord[h]<min){
            
            min=ord[h];
            indexmin=h;
        }
    }
    printf("A correcao sugerida e: ");
        char sugestao[strlen(dic[indexmin])];
    for(int i=0;i<strlen(dic[indexmin]);i++){
        sugestao[i]=dic[indexmin][i];
        printf("%c",sugestao[i]);
    }
        printf("\n\n");
    
    return sugestao;
}


int dicionario(char pal[]){
    
    char dic[dicSize][10]={"Ola","Oi","bem","?","sim","contigo","tambem","Queres","ir","vamos","cinema","Pode","ser","!","ao","indo","la","surf","bota","ta","Antonio","Coutinho","Lp","Portugues","Ya",",", " ", ".", "!"};
    int ord[27];
    
    
    int min=500, indexmin=0;
    char aux[dicSize];
    for(int i=0;i<dicSize;i++){
        for(int j=0;j<dicSize;j++){
            aux[j]=dic[i][j];
        }
        ord[i]=levenshtein(aux, pal);
        
        if(ord[i]==0){
            printf("Palavra inserida corretamente\n");
            return 0;
        }
    }
    for(int h=0;h<dicSize;h++){
        if(ord[h]<min){
            
            min=ord[h];
            indexmin=h;
        }
    }
    printf("A correcao sugerida e: ");
    char sugestao[strlen(dic[indexmin])];
    for(int i=0;i<strlen(dic[indexmin]);i++){
        sugestao[i]=dic[indexmin][i];
        printf("%c",sugestao[i]);
    }
    printf("\n\n");
    return 0;
}


void merge_sort_td(MENSAGEM* a, MENSAGEM* aux, int lo, int hi){
    int mid = lo + (hi - lo) / 2;
    if (hi <= lo) return;
    merge_sort_td(a, aux, lo, mid);
    merge_sort_td(a, aux, mid+1, hi);
    merge_arrays(a, aux, lo, mid, hi);
    //printArrayPart(a, lo, hi);
}
void merge_arrays(MENSAGEM* a, MENSAGEM* aux, int lo, int mid, int hi) {
    int i = lo, j = mid+1, k;
    for (k = lo; k <= hi; k++) // copy
        aux[k] = a[k];
    for (k = lo; k <= hi; k++) { // merge
        if      (i > mid)          a[k] = aux[j++];
        else if (j > hi)           a[k] = aux[i++];
        else if ((aux+j)->timestamp<(aux+i)->timestamp)  a[k] = aux[j++];
        else                       a[k] = aux[i++];
    }
}

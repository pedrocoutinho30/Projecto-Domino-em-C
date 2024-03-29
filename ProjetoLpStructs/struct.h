//
//  struct.h
//  ProjetoLpStructs
//
//  Created by Pedro Coutinho on 20/12/17.
//  Copyright © 2017 Pedro Coutinho. All rights reserved.
//

#ifndef struct_h
#define struct_h
#define dicSize 29
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

#define M50 50

typedef struct utilizador{
    int id_utilizador;
    char * nome;
}UTILIZADOR;

typedef struct mensagem{
    int id;
    int utilizador;
    char * timestamp;
    char *text;

}MENSAGEM;


typedef struct posicao{
    int indice_mensagem;
    int pos;
    struct posicao*  pospnext;
}POSICAO;

typedef struct palavra{
    char *palavra;
    int freq_abs;
    POSICAO * pos;
    struct palavra* pnext;
}PALAVRA;

typedef struct conversa{
    int id;
    int tamanho;
    int n_insercoes;
    MENSAGEM *pfirst_menssagem;
    PALAVRA * bag_of_word_conversa;
    int n_insercoes_bag_of_word_conversa;
    struct conversa *pnext;
}CONVERSA;

typedef struct corpus{
    UTILIZADOR * pUtilizador;
    int number_of_users;
    int users_size;
    struct conversa *pfirst_conversa;
    //char **bag_of_word_corpus;
    PALAVRA *bag_of_word_corpus;
    //int tamanho_bag_of_word_corpus;
    int n_insercoes_bag_of_word_corpus;
}CORPUS;

int main_structs(void);
void add_user(CORPUS * cp1, char* name);
CONVERSA * insert_conversa_to_corpus(CORPUS * cp1);
CONVERSA * insert_message(CONVERSA * conversa, int user, char * message, char * time);
char * get_current_time(void);
int read_file(CORPUS * corpus, char file[]);
CORPUS* read_corpus(CORPUS * corpus, char file[]);
void print_conversa(CORPUS corpus);
void remover_conversa(CORPUS *cp, int remove);
void conversas_utilizador(CORPUS cp, int id);
void palavras_comuns(CORPUS cp,char word[]);

char* create_copy_dyn_string(char str[]);
char ** string_to_matrix(char * string, int * matrix_size);
void insert_string_into_matriz(char ** matrix, int * insertionsNumber, int * matrixSize, char * string);
void remove_delimiter(char* string, char* remove_delimiter);
char* verify_delimiter(char delimiter[], char *string);
void bag_of_words(char ** matrix, int size, CONVERSA *conversa, int id, CORPUS *corpus);
PALAVRA * verifica_palavra_existente(CONVERSA *conv, char *palavra);
PALAVRA * verifica_palavra_existente_corpus(CORPUS *cp, char *palavra);

char ** create_dynamic_matrix(int * number_of_lines, int number_lines);
char ** add_more_lines(char ** matrix, int * number_of_lines, int number_to_add);
void write_corpus_file(CORPUS cp, char file[]);
void write_corpus_bin(CORPUS cp, char file[]);
void printMatrix(PALAVRA* matrix, int number_of_lines_used);
void preencher_bag_of_word_corpus(char **aux_matrix,int size, CONVERSA *conversa,int id, CORPUS *cp);
void remover_mensagem(int id_mensagem, int id_conversa,CORPUS *cp);


PALAVRA* Merge(PALAVRA *a, PALAVRA *b, int flag);
void FrontBackSplit(PALAVRA* source,PALAVRA** frontRef, PALAVRA** backRef);
void printList(PALAVRA *node);
void MergeSort(PALAVRA** list, int flag);
void addElement(PALAVRA** list, char * new_data, int key);
void print_bag_of_word_corpus(CORPUS cp1);

int tf(CORPUS cp, char termo[]);
float idf(CORPUS cp, char pal[], int nConversas);
void tfIdf(CORPUS cp, char termo[]);
int numero_conversas(CORPUS cp);





MENSAGEM* Merge1(MENSAGEM *a, MENSAGEM *b, int flag, int i);
void FrontBackSplit1(MENSAGEM* source,MENSAGEM** frontRef, MENSAGEM** backRef, int i);
void printList1(MENSAGEM *node, int i);
void MergeSort1(MENSAGEM** list, int flag, int i);
void addElement1(MENSAGEM** list, char * new_data, int key, int i);

int dicionario(char pal[]);
char * dicionario1(char pal[]);
int levenshtein(char *s1, char *s2);

void merge_arrays(MENSAGEM* a, MENSAGEM* aux, int lo, int mid, int hi);
void merge_sort_td(MENSAGEM* a, MENSAGEM* aux, int lo, int hi);

#endif /* struct_h */

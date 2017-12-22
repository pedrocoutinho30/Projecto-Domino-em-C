//
//  struct.h
//  ProjetoLpStructs
//
//  Created by Pedro Coutinho on 20/12/17.
//  Copyright © 2017 Pedro Coutinho. All rights reserved.
//

#ifndef struct_h
#define struct_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define M50 50

typedef struct utilizador{
    int id_utilizador;
    char * nome;
}UTILIZADOR;

typedef struct mensagem{
    int utilizador;
    char * timestamp;
    char *text;
}MENSAGEM;

typedef struct conversa{
    int id;
    int tamanho;
    int n_insercoes;
    MENSAGEM *pfirst_menssagem;
    char **bag_of_word_conversa;
    int tamanho_bag_of_word_conversa;
    int n_insercoes_bag_of_word_conversa;
    struct conversa *pnext;
}CONVERSA;

typedef struct corpus{
    UTILIZADOR * pUtilizador;
    int number_of_users;
    int users_size;
    struct conversa *pfirst_conversa;
}CORPUS;

int main_structs(void);
void add_user(CORPUS * cp1, char* name);
CONVERSA * insert_conversa(CORPUS * cp1);
void insert_message(CONVERSA * conversa, int user, char * message, char * time);
char * get_current_time(void);
int read_file(CORPUS * corpus, char file[]);
void print_conversa(CORPUS corpus);
char* create_copy_dyn_string(char str[]);
char ** string_to_matrix(char * string, int * matrix_size);
void insert_string_into_matriz(char ** matrix, int * insertionsNumber, int * matrixSize, char * string);
void remove_delimiter(char* string, char* remove_delimiter);
char* verify_delimiter(char delimiter[], char *string);
char **bag_of_words(char ** matrix, int size, char **bag_of_word, int *size_bw, int *inserted_size);
char ** create_dynamic_matrix(int * number_of_lines, int number_lines);
char ** add_more_lines(char ** matrix, int * number_of_lines, int number_to_add);
void write_corpus_file(CORPUS cp, char file[]);
void write_corpus_bin(CORPUS cp, char file[]);
void printMatrix(char ** matrix, int number_of_lines_used);

#endif /* struct_h */
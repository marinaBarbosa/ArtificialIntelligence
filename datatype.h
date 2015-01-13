#ifndef DATATYPE_H
#define	DATATYPE_H

#define SIZE 23
#define SIZEN 21
#define SIZED 1

//Estrutura de dados 
typedef struct list {
    int data[SIZE];
    struct list *next;
} List;

typedef struct listN {
    double data[SIZE];
    struct listN *next;
} ListN;

typedef struct listF {
    double element[SIZE];
    int freq;
    struct listF *next;
} ListF;

typedef struct listD {
    int num;
    float data[SIZED];
    struct listD *next;
} ListD;

typedef struct listEnc {
    ListN *prox;
    struct listEnc *next;
} ListEnc;

#endif

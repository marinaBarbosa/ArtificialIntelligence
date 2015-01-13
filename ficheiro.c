#include "ficheiro.h"

List *leituraFicheiroListaOriginal (List *head, char *filename) {    
    FILE *fp = fopen(filename,"r");
    int i;
    char *pch = NULL, helper[128];
    int data[SIZE];
    
    if (fp == NULL)
        exit(1);
    
    for (i = 0; i < 2; i++)
        while (fgetc(fp) != '\n');
           
    while (!feof(fp)) {
        i = 0;
        fscanf(fp, "%s\n", helper);
        pch = strtok(helper, ";");
        data[i] = atoi(pch);
        i++;

        while (i < 23) {
            pch = strtok(NULL, ";");
            data[i] = atoi(pch);
            i++;
        }
        head = insert(head, data);
    }
    
    fclose(fp);
    
    return head;
}

void *guardarListaFicheiro(List *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    int i;
    if (fp == NULL || head == NULL)
        exit(1);
    while (head != NULL) {
        for (i = 0; i < SIZE; i++)
            if (i == SIZE-1)
                fprintf(fp, "%d", head->data[i]);
            else
                fprintf(fp, "%d,", head->data[i]);
        head = head->next;
       // if (head != NULL)
            fprintf(fp, "%c", '\n');
    }
    fclose(fp);
}

List *leituraFicheiroLista (List *head, char *filename) {    
    FILE *fp = fopen (filename,"r");
    int i;
    char *pch = NULL, helper[512];
    int data[SIZE];
    
    if (fp == NULL)
        exit(1);
    
    while (!feof(fp)) {
        i = 0;

        fscanf(fp, "%s\n", helper);
        pch = strtok(helper, ",");
        data[i] = atoi(pch);
        i++;

        while (i < 23) {
            pch = strtok(NULL, ",");
            data[i] = atoi(pch);
            i++;
        }
        head = insert(head,data);
    }
    
    fclose(fp);
return head;
}

void normalizacaoFicheiro (List *head, char *filename){
    int i;
    FILE *fp = fopen(filename, "w");
    if (fp == NULL || head == NULL)
        exit(1);    
    while (head != NULL) {
        for (i = 0; i < SIZE; i++) {
            if (i == SIZE-1)
                fprintf(fp,"%.4f",calculoNormal(head,i));
            else 
                fprintf(fp,"%.4f,",calculoNormal(head,i));
        }
        fprintf(fp,"%c",'\n');
        head = head->next;
    }
    fclose(fp);
}

ListN *leituraFicheiroListaNormalizada (ListN *head, char *filename) {    
    FILE *fp = fopen (filename,"r");
    int i;
    char *pch = NULL, helper[512];
    float data[SIZEN];
    
    if (fp == NULL)
        exit(1);
    
    while (!feof(fp)) {
        i = 0;

        fscanf(fp, "%s\n", helper);
        pch = strtok(helper, ",");
        data[i] = atof(pch);
        i++;

        while (i < 23) {
            pch = strtok(NULL, ",");
            data[i] = atof(pch);
            i++;
        }
        head = insertN(head,data);
    }
    
    fclose(fp);
    
    return head;
}
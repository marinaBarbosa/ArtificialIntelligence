/* 
 * File:   lista.h
 * Author: marina
 *
 * Created on 13 de Janeiro de 2015, 15:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

#ifndef LISTA_H
#define	LISTA_H

List *memAlloc(void); 
ListN *memAllocN(void);

void printLista(List *head);

List *insert(List *head, int *data);
ListN *insertN(ListN *head, float *data);

List *delete(List *head, List *obj);

#endif	/* LISTA_H */


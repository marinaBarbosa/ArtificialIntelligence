/* 
 * File:   algoritmo.h
 * Author: marina
 *
 * Created on 17 de Novembro de 2014, 18:41
 */

#ifndef ALGORITMO_H
#define	ALGORITMO_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "datatype.h"

int knnNeighbor(ListD *headD,ListN *headt, int kk);
void matrizConfusaoInicial(int intMatrix[][3]) ;
void matrizConfusao(int nspT,int nspTr,int m[][3]);

#endif	/* ALGORITMO_H */




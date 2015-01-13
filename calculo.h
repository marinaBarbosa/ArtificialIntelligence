/* 
 * File:   calculo.h
 * Author: marina
 *
 * Created on 19 de Outubro de 2014, 18:01
 */

#ifndef NEWFILE_H
#define	NEWFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "datatype.h"

double mediaColuna(List *head, int index);

double varianciaColuna(List *head, int index);

double desvioPadrao (List *head, int index);

double calculoNormal (List *head ,int index);

float distanciaEuclidiana (ListN *head,ListN *headt);

#endif	/* NEWFILE_H */


/* 
 * File:   ficheiro.h
 * Author: marina
 *
 * Created on 19 de Outubro de 2014, 21:10
 */

#ifndef FICHEIRO_H
#define	FICHEIRO_H

#include <stdio.h>
#include "datatype.h"
#include "lista.h"
#include "calculo.h"

void *guardarListaFicheiro(List *head, char *filename);

List *leituraFicheiroListaOriginal (List *head, char *filename);

List *leituraFicheiroLista (List *head, char *filename);

void normalizacaoFicheiro (List *head, char *filename);

ListN *leituraFicheiroListaNormalizada (ListN *head, char *filename);

#endif	/* FICHEIRO_H */



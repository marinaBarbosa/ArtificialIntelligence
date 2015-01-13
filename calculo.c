/* 
 * File:   calculo.c
 * Author: marina
 *
 * Created on 19 de Outubro de 2014, 18:03
 */

#include "calculo.h"

double mediaColuna(List *head, int index) {
    double avg = 0.0;
    int count = 0;
    while (head != NULL) {
        avg += head->data[index];
        count++;
        head = head->next;
    }
    return (avg / count);
}

double varianciaColuna(List *head, int index) {
    double val = 0.0;
    int count = 0;
    double avg = mediaColuna(head,index);
    while (head != NULL) {
        val += pow((head->data[index] - avg), 2);
        count++;
        head = head->next;
                
    }
    return (val / count);    
}

double desvioPadrao (List *head, int index) {
    return (sqrt(varianciaColuna(head, index)));    
}

double calculoNormal (List *head ,int index) {
  
    int count = index;
    
    double avg = mediaColuna (head, index);
    double desvio = desvioPadrao(head,index);
    
    if (count > 21)
        return head->data[index];
    
    if ( isnan((head->data[index])== -NAN) || head->data[index] == isnan(0.0) )
        return 0;
    
    double normal = (head->data[index]- avg)/(desvio);
    
    if (head == NULL)
        return -1;
        
    return normal;
}

float distanciaEuclidiana (ListN *head,ListN *headt) {
    float distEcl=0.0;
    int i;
    
    for (i = 0; i < SIZEN; i++ ){
        distEcl += sqrt(pow(((head->data[i]) - (headt->data[i])),2));
    }
    
    return distEcl;
}

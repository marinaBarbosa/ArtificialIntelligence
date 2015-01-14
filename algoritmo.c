#include "algoritmo.h"

int knnNeighbor(ListD *headD,ListN *headt) {
    
    int count = 0;
    int n = 0;
    
    if (headt == NULL || headD == NULL)
        printf("Correu mal");
    

    do {
        count++;
        headt = headt->next; 
 
    } while (count < headD->num);
   
    n = headt->data[SIZE-1];
    
   return n;
    
}
void matrizConfusaoInicial(int intMatrix[][3]) {


  int i, j;
  int count = 0;


  for (i = 0; i < 3; ++i) {
      for (j = 0; j < 3; ++j) {
          intMatrix[i][j] = 0;
      }
  }
}
void matrizConfusao(int nspT,int nspTr,int m[][3]) {
    m[nspTr-1][nspT-1] += 1;
}
float ordenar (float d,float v,int index) {

    float final;
    
    if (index == 0) {
        return d;        
    }
    
    if (d<v) {
        return d;
    }
    else {
        return v;
    }
} 
        

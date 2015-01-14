#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "calculo.h"
#include "ficheiro.h"
#include "algoritmo.h"

void clearScreen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void doPause() {
    printf("%s", "Prima uma tecla para continuar...");
    getchar();
}

int main(void) {
    List *dataset = NULL; // Original
    List *treino = NULL; // 70%
    List *teste = NULL; // 30%
    
    List *frqData = NULL; // Frequências do Dataset Original
    
    List *aux; //Auxiliar
    
    ListN *norTreino = NULL; // Treino Normalizado
    ListN *norTeste = NULL; // Teste Normalizado
    
    ListD *norDistD = NULL; //Distâncias
    
    int nspTeste = 0;
    int nspTreino = 0;
    int i,j,a,matriz[3][3];
    int opcao;
        
    //dataset = leituraFicheiroListaOriginal(dataset, "CTG_1500.csv");
    
    clearScreen();
    
    printf ("1 - Mostrar Valores/Média/Variância/Dividir Ficheiros\n");
    printf ("\n2 - Frequências Relativas\n");
    printf ("\n3 - Normalização dos Dados\n");
    printf ("\n4 - Média e Variância dos atributos da classe treino \n");
    printf ("\n5 - Algoritmo do vizinho mais próximo\n");
    printf ("\nOpção -> ");
    scanf("%d", &opcao);
   
    switch (opcao){

        case 1 :
            /* - Construa um programa em C que aceite o nome de um ficheiro de texto contendo o dataset em formato CSV.
             * - Implemente funções para ler os dados para uma matriz numérica (de preferência dinâmica) e listar o conteúdo da matriz no ecran.
             * - Acrescente as funções necessárias para calcular a média e a variância de cada um dos atributos do dataset.
             * - Guarde estes valores num novo ficheiro.
             */

            //1) Leitura dos dados do ficheiro .csv para uma lista (a cima) e imprimir 

            printLista(dataset);

            //2) Calculo da média e variância

            FILE *fvariancia = fopen("MediaVariancia.csv","w");
            for (i = 0; i < SIZE; i++) {
               fprintf(fvariancia,"Avg[%d]: %.4f\t\t", i+1, mediaColuna(dataset, i));
               fprintf(fvariancia,"Var[%d]: %.4f\n", i+1, varianciaColuna(dataset, i));
            }
            fclose(fvariancia);

            //3) Dividir em dois conjuntos treino e teste

            for(i = 1501; i > 450; i--) { // 70% dos dados 
                aux = dataset;
                a = rand() % i;

                for(j = 0; j < a; j++)
                 aux = aux->next;

                if (aux == NULL)
                     break;

                treino = insert(treino, aux->data);
                dataset = delete(dataset, aux);        
            }

            for(i = 450; i > 0; i--) { // 30% dos dados 
                aux = dataset;
                a = rand() % i;

               for(j = 0; j < a; j++)
                   aux = aux->next;

               if (aux == NULL)
                   break;
                teste = insert(teste, aux->data);
                dataset = delete(dataset, aux);        
            }
            guardarListaFicheiro(treino, "treino.csv");
            guardarListaFicheiro(teste, "teste.csv");
        break;

        case 3:
            /*
             * Normalização estatística do conjunto de treino e o guarde num novo ficheiro 
             * (apenas com dados normalizados) no formato CSV.
             */
            treino = leituraFicheiroLista(treino, "treino.csv");
            normalizacaoFicheiro (treino, "treinoNormalizado.csv");

            teste = leituraFicheiroLista(teste, "teste.csv");
            normalizacaoFicheiro (teste, "testeNormalizado.csv");
        break;
        
        case 5: 
            
            //Implemente um classificador K-NN
            
            //Leitura de treino e teste normalizado
            norTreino = leituraFicheiroListaNormalizada (norTreino, "treinoNormalizado.csv");
            norTeste = leituraFicheiroListaNormalizada (norTeste, "testeNormalizado.csv");
            
            int count = 0;
            int countn = 0,k,n=0;
            
            FILE *faux = fopen ("valoresDistancia.csv","a+");
            FILE *ford = fopen ("valoresOrdenados.csv","w");
         
            ListN *tsaux = norTeste; 
      
            for(j=0;j<1051;j++) {
                
                for(i=0;i<450;i++) {
                
                count = 0;
          
                ListN *taux = norTreino;
              
                fprintf(faux,"%d %.4f \n",i,distanciaEuclidiana (taux,tsaux));
               
                printf("[%d][%d] = %f\n",j+1,i+1,distanciaEuclidiana (taux,tsaux));  
                //norDistD = leitura (norDistD, "valoresDistancia.csv");

                    /*d[i] = d[i] = distanciaEuclidiana (taux,tsaux);
                    
                    BubbleSort(d[i], i);*/
                    taux = taux->next;

                }
                tsaux = tsaux->next;
            }
        break; 
    }
}
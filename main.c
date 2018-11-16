#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include "string.h"

#define infinity 99999.99

//declaração das funções auxiliares

float **alocmat(int lin, int col);
void inicializaMat(float **mat, int nVertices);
void imprimeMat(float **mat, int nVertices);


int main(){
  int nVertices, i, j, tamanhoLinha;
  FILE *arq;
  char nomeArq[20], linArq[20];
  float **matriz;
  float w; //w=weight

  printf("Digite o nome do arquivo a ser aberto: "); //arquivo grafo alterado, removido os vértices e está
  scanf("%s", nomeArq);                             //somente com as arestas é necessário definir a quantidade
                                                    //de vértices do grafo
  arq=fopen(nomeArq, "r");

  if(arq==NULL){
    printf("\nErro ao abrir o arquivo!!\n");
    exit(1);
  }else{

    fgets(linArq,20,arq);
    printf("linArq = %s\n", linArq);

    fgets(linArq,20,arq);
    printf("linArq = %s\n", linArq);

    nVertices = atoi(linArq);
    printf("nVertices = %d\n", nVertices);
/*
    while(linArq != "#arestas"||linArq != 500){
      printf("linArq = %s", linArq);
      fgets(linArq, 20, arq);
      nVertices = (int)linArq;
    }
*/
    matriz = alocmat(nVertices, nVertices);

    inicializaMat(matriz,nVertices); //inicializa matriz com a diagonal principal = 0 e o resto com infinito

    while(fscanf(arq, "%d %d %f", &i, &j, &w) != EOF){    //preenche a matriz com os valores do arquivo
      matriz[i-1][j-1]=w;
    }

    imprimeMat(matriz, nVertices);

  }
  free(matriz);
}

//corpo das funções auxiliares


void imprimeMat(float **mat, int nVertices){
  int i,j;

  printf("\n");

  for(i=0;i<nVertices;i++){
    for(j=0;j<nVertices;j++){
      printf("%.2f ", mat[i][j]);
    }
    printf("\n");
  }

}
void inicializaMat(float **mat, int nVertices){
  int i, j;
    for(i=0;i<nVertices;i++){
      for(j=0;j<nVertices;j++){
        if(i==j){
          mat[i][j]=0;
        }else{
          mat[i][j]= infinity;
        }
      }
    }
}


float **alocmat(int lin, int col){
	int i;
	float **m;
	m=(float**)malloc(sizeof(float*)*lin);
	for(i=0;i<lin;i++){
		m[i]=(float*)malloc(sizeof(float)*col);
	}
	return m;
}

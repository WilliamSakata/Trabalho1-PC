#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define infinity 99999.99

float **alocmat(int lin, int col);

int main(){
  int nVertices, i, j;
  FILE *arq;
  char nomeArq[20];
  float **matriz;
  float w; //w=weight

  printf("Digite o nome do arquivo a ser aberto: ");
  scanf("%s", nomeArq);

  arq=fopen(nomeArq, "r");

  if(arq==NULL){
    printf("\nErro ao abrir o arquivo!!\n");
    exit(1);
  }else{
    printf("Digite a quantidade de vértices do grafo: ");
    scanf("%d", &nVertices);

    matriz = alocmat(nVertices, nVertices);
    printf("\npassei alocmat\n");

    for(i=0;i<nVertices;i++){
      for(j=0;j<nVertices;j++){
        if(i==j){
          matriz[i][j]=0;
        }else{
          matriz[i][j]= infinity;
        }
      }
    }

    while(fscanf(arq, "%d %d %f", &i, &j, &w) != EOF){
      printf("\ni=%d, j=%d, w=%.2f\n", i,j,w);
      matriz[i-1][j-1]=w;
    }
    printf("\npassei while\n");

    printf("\n");

    printf("%f\n", matriz[499][499]);

    for(i=0;i<nVertices;i++){
      for(j=0;j<nVertices;j++){
        printf("%.2f ", matriz[i][j]);
      }
      printf("\n");
    }



  }
  free(matriz);
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

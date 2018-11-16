#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

float **alocmat(int lin, int col);

int main(){
  
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

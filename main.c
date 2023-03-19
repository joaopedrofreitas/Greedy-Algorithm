//#include "functions.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include <stdbool.h>
#define MAX 50
#define BOLD_RED "\x1b[31;1m"
#define BRIGHT_CYAN "\x1b[96;1m"
#define NO_COLOR "\x1b[0;0m"
#define sep "\n========================================\n"
int sum=0;

typedef struct{
	int i,j;int S_value;
} stance;
void set_Matrix(int col,int (*mat)[col],FILE *arq);//sz vale 4 aq
void print_Matrix(int col,int (*mat)[col]);
//int number_Matrix(int col);
//void joystick(int col,int (*mat)[col], int sz, bool *final, stance *st);
//void Sort_stance(stance *st,int *aux); 


int main(void){
FILE *arq;
int sz=0,al=0,col=0,aux=0,i=0,j=0,Num=0;
stance st;
bool final=0;

arq = fopen("matriz", "r");
if(arq==NULL){
	printf(BOLD_RED "ERROR" NO_COLOR );
	return(1);
}
fscanf(arq, "%d %d",&sz,&col);
printf("TAMANHO: %d %d\n", sz,sz);
int (*mat)[col]=malloc(sizeof(int[col][col]));
sz-=1;
printf(sep);
while(!feof(arq)){
	set_Matrix(col,mat,arq);
	print_Matrix(col,mat);
	printf(BOLD_WHITE "\nPOSIÇÃO INICIAL (lin col):" NO_COLOR);
	scanf("%d %d",&st.i,&st.j);sum+=mat[st.i][st.j];mat[st.i][st.j]=0;st.S_value=0;//setar posição inicial,value da stance = 0
		while(!final){
			if(st.i==sz){
				while(st.j!=sz){
					sum+=mat[st.i][st.j];
					mat[st.i][st.j]=0;
					st.j+=1;
				}
				sum+=mat[st.i][st.j];
				mat[st.i][st.j]=0;
				final=1;
				break;
			}
			if(st.j != 3){//posso ir para direita,diagonal inferior direita
				st.S_value=mat[st.i][st.j+1];
				if(st.S_value>aux){aux=st.S_value;i=st.i;j=st.j+1;}
				st.S_value=mat[st.i+1][st.j+1];
				if(st.S_value>=aux){aux=st.S_value;i=st.i+1;j=st.j+1;}
			}
			if(st.j != 0){//posso ir para esquerda,diagonal inferior esquerda
				st.S_value=mat[st.i][st.j-1];
				if(st.S_value>aux){aux=st.S_value;i=st.i;j=st.j-1;}
				//else if(st.S_value==aux){};
				st.S_value=mat[st.i+1][st.j-1];
				if(st.S_value>aux){aux=st.S_value;i=st.i+1;j=st.j-1;}
				//else if(){};
			}
			st.S_value=mat[st.i+1][st.j];//baixo
			if(st.S_value>aux){aux=st.S_value;i=st.i+1;j=st.j;}
			//else if(){}//ver qual está mais a direita;
			st.i=i;
			st.j=j;
			sum+=aux;
			aux=0;
			mat[st.i][st.j]=0;
		}
		printf("\nSOMA: %d\n",sum);
		print_Matrix(col,mat);
		st.i=0;st.j=0;st.S_value=0;sum=0;final=0;	
		printf(sep);
}
free(mat);
fclose(arq);
return 0;
}


void set_Matrix(int col,int (*mat)[col],FILE *arq){
int value=0;
	for(int i=0;i<col;i++){
				for(int j=0;j<col;j++){
					fscanf(arq,"%d",&value);
					mat[i][j]=value;
				}
			}

}
void print_Matrix(int col,int (*mat)[col]){
	for(int i=0;i<col;i++){
			for(int j=0;j<col;j++){
				printf("%d ", mat[i][j]);
			}
		printf("\n");
	}
	printf("\n");
}

/*int number_Matrix(int col){
	FILE *arq1;
	arq1 = fopen("matriz", "r");
	int cont=0,line_matrix=0,sz1=0,col2=0;char row[MAX];
	fscanf(arq1, "%d %d",&sz1,&col2);
	while(!feof(arq1)){
		fgets(row,MAX,arq1);
		line_matrix++;
		if(line_matrix==col){cont++;line_matrix=0;}
	}
	fclose(arq1);
	return (cont-1);
}*/



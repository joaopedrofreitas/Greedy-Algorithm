//#include "functions.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#define MAX 50
//void set_Matrix(int **mat,int sz,char row[], FILE *arq);
//void print_Matrix(char **mat, int sz);




int main(){
	FILE *arq;
	int sz,al,col;
	short value;
	char **mat,ch;
	char row[MAX];
	char *aux;
	//arq = fopen("matriz","r");
	//fclose(arq);
	//free(mat);
	/*void joystick(int (*mat)[sz]);
	void set_Matrix();
	//int (*mat)[sz]=malloc(sizeof(int[sz][sz]));
	int sortvalues(int (*mat)[sz]);*/
	//deixar o arquivo aberto, fecho dps


	arq = fopen("matriz", "r");
	if(arq==NULL){
		printf("ERROR");
		return(1);
	}
	fscanf(arq, "%d %d",&sz,&col);	
	printf("TAMANHO: %d %d", sz,sz);
	//while(!feof(arq))
	//{
		mat=(char **)malloc(sizeof(char *)*sz);
		for(int i=0;i<sz+1;i++){	
			mat[i]=(char *)malloc(sizeof(char *)*sz);
			row[strlen(row)-1]='\0';
			fgets(row,50, arq);
			printf("%s", row);
			strcpy(mat[i], row);
		}
		free(mat);
	//}
	
fclose(arq);
return 0;
}


//void set_Matrix(int **mat, int sz, char *row, FILE *arq){


/*void print_Matrix(char **mat, int sz){
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
				printf("%d", mat[i][j]);
		}
		printf("\n");
	}
}*/


#include"functions.h"
int sum=0, total=0;

void set_size(FILE *arq,uint8_t *sz,uint8_t *col){
	fscanf(arq, "%hhd %hhd",sz,col);
	printf("TAMANHO: %hhd %hhd\n",*sz,*sz);
}

void set_stance(stance *st,uint8_t col,int (*mat)[col]){
	printf(BRIGHT_CYAN "\nPOSIÇÃO INICIAL (lin col):" NO_COLOR);
	scanf("%hhd %hhd",&st->i,&st->j);sum+=mat[st->i][st->j];mat[st->i][st->j]=0;st->S_value=0;
}

bool set_Matrix(uint8_t col,int (*mat)[col],FILE *arq){
int value=0;
	for(int i=0;i<col;i++){
		for(int j=0;j<col;j++){
			fscanf(arq,"%d",&value);
			if(value==0){return 0;}
			mat[i][j]=value;
		}
	}
	return 1;
}
void print_Matrix(uint8_t col,int (*mat)[col]){
	for(int i=0;i<col;i++){
			for(int j=0;j<col;j++){
				if(mat[i][j]==0){printf(BRIGHT_GREEN"%3d " NO_COLOR, mat[i][j]);}
				else{printf("%d ", mat[i][j]);}
			}
		printf("\n");
	}
	printf("\n");
}

void joystick(uint8_t col,int (*mat)[col], uint8_t sz,stance *st){
	uint8_t i=0,j=0;
	int aux=0;
	bool final=0;
	while(!final){
			if(st->i==sz){
				while(st->j!=sz){
					sum+=mat[st->i][st->j];
					mat[st->i][st->j]=0;
					st->j+=1;
				}
				sum+=mat[st->i][st->j];
				mat[st->i][st->j]=0;
				final=1;
				break;
			}
			st->S_value=mat[st->i+1][st->j];
			if(st->S_value>=aux){aux=st->S_value;i=st->i+1;j=st->j;}
			if(st->j != 0){
				st->S_value=mat[st->i][st->j-1];
				if(st->S_value>=aux){aux=st->S_value;i=st->i;j=st->j-1;}
				st->S_value=mat[st->i+1][st->j-1];
				if(st->S_value>=aux){aux=st->S_value;i=st->i+1;j=st->j-1;}
			}
			if(st->j != 3){
				st->S_value=mat[st->i][st->j+1];
				if(st->S_value>=aux){aux=st->S_value;i=st->i;j=st->j+1;}
				st->S_value=mat[st->i+1][st->j+1];
				if(st->S_value>=aux){aux=st->S_value;i=st->i+1;j=st->j+1;}
			}
			st->i=i;
			st->j=j;
			sum+=aux;
			aux=0;
			mat[st->i][st->j]=0;
		}
		print_Matrix(col,mat);
		printf(BRIGHT_CYAN "\nSOMA (INDIVIDUAL): %d\n"NO_COLOR,sum);
		total+=sum;
		st->i=0;st->j=0;st->S_value=0;sum=0;final=0;	
		printf(sep);
}

void Total_sum(){
	printf(BRIGHT_CYAN"\nSOMA TOTAL (TODAS AS MATRIZES): %d\n"NO_COLOR, total);
}
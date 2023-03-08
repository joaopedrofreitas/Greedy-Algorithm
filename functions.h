#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*typedef struct{	
	short i;
	short j;
}local;*/

FILE *arq;
short sz;
int **mat;
//int (*mat)[sz]=malloc(sizeof(int[sz][sz]));
short value;
//arq = fopen("matriz","r");
//fclose(arq);
//free(mat);

void set_Matrix(int **mat,int sz);
/*void joystick(int (*mat)[sz]);
void set_Matrix();
int sortvalues(int (*mat)[sz]);*/

#endif

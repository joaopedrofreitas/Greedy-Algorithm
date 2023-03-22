#include "functions.h"


int main(void){
FILE *arq;
uint8_t sz=0,col=0;
stance *st = malloc(sizeof(*st));
arq = fopen("dataset/input.data", "r");
if(arq==NULL){printf(BOLD_RED "ERROR" NO_COLOR );return(1);}
set_size(arq,&sz,&col);
int (*mat)[col]=malloc(sizeof(int[col][col]));sz-=1;
printf(sep);
while(!feof(arq)){
		if(!set_Matrix(col,mat,arq)){
		printf(BOLD_RED "FIM DA EXECUÇÃO\n" NO_COLOR); 
		break;
	}
	print_Matrix(col,mat);
	set_stance(arq,st,col,mat);
	joystick(col,mat,sz,st);
}
Total_sum();
printf(sep);
free(st);free(mat);fclose(arq);
return 0;
}
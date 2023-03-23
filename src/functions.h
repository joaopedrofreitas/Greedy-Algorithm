#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include <stdbool.h>
#define MAX 50
#define BOLD_RED "\x1b[31;1m"
#define BRIGHT_CYAN "\x1b[96;1m"
#define NO_COLOR "\x1b[0;0m"
#define BRIGHT_GREEN "\x1b[92;1m"
#define sep "\n========================================\n"
typedef struct{
   uint8_t i,j;ushort S_value;
}stance;

bool set_Matrix(uint8_t col,int (*mat)[col],FILE *arq);
void print_Matrix(uint8_t col,int (*mat)[col]);
void joystick(uint8_t col,int (*mat)[col], uint8_t sz,stance *st);
void set_size(FILE *arq,uint8_t *sz,uint8_t *col);
void set_stance(stance *st,uint8_t col,int (*mat)[col]);
void Total_sum();

#endif
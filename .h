#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct information {
  int mssv;
  char hoten[50];
  float diem;
}
  information;


void swapfloat(float *,float*);
void swapfloat(float *a,float *b){
  float t=*a;
  *a=*b;
  *b=t;
}

void swapint(int *,int*);
void swapint(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
}

void swapstring(char *,char *);
void swapstring(char a[],char b[]){
  char t[50];
  stringcpy(t,a);
  stringcpy(a,b);
  stringcpy(b,t);
}

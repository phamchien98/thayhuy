#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#ifndef      __data_H__
#define      __data_H__
 

#include"vietnamese.h"

typedef struct information {
  int mssv;//mssv
  char hoten[50];
  char password[50];
  char quequan[50];
  float diem;
}
  information;
information datanull={0,"",0};


void printdata(information a)
{
  printf("%d %s %f\n", a.mssv,a.hoten,a.diem);
}


int sosanhkey2(information a,information b){
  if (a.diem>b.diem)
    return 1;
  else return -1;
}

int sosanhkeyphanbiethoathuong(information a,information b){
  if (strcmp(a.hoten,b.hoten)==0)
    return 0;
  else 
    if (strcmp(a.hoten,b.hoten)>0)
    return 1;
  else return -1;
}


int sosanhkey(information a,information b)
{
  //  return VietNamCompareName(a.hoten,b.hoten);
  char ten_a[50],ten_b[50];
  strcpy(ten_a,a.hoten);
  strcpy(ten_b,b.hoten);

  for(int i = 0; ten_a[i]; i++){
    ten_a[i] = tolower(ten_a[i]);
  }
  for(int i = 0; ten_b[i]; i++){
    ten_b[i] = tolower(ten_b[i]);
  }


   if(strcmp(ten_a,ten_b)<0) 
      return -1;
   if(strcmp(ten_a,ten_b)>0)  return 1;
    else return 0;

}
/*
int databinarysearchmintomax(information a[],int size,information key)
{
  if(size>0)
    {

      int head=0,last=size-1,mid=(head+last)/2+1;
      int sosanh;
      while(1)
	{sosanh=sosanhkey(a[mid],key);
	  if(head==last) if(sosanh==0) return head;
	  if(sosanh==-1)
	    {head=mid;mid=(last+head
	}
    }
  else return -1
}
*/
void getinfo(information *info)
{
  printf("key: ");
  scanf("%d%*c",&((*info).mssv));
  printf("hoten: ");
  scanf("%s%*c",(*info).hoten);
  printf("diem: ");
  scanf("%f%*c",&((*info).diem));
}

void swapdata(information *a,information *b){
information c=*a;
*a=*b;
*b=c;
}

void makenulldata(information *info)
{

  *info=datanull;
}







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
  strcpy(t,a);
  strcpy(a,b);
  strcpy(b,t);
}


   
#endif

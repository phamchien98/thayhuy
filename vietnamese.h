#include<string.h>
#include<stdlib.h>

#ifndef    __vietnamese_H__
#define    __vietnamese_H__
void loaidaugachchan(char *,int);
int VietNamCompareName(char *,char *);
void loaidaugachchan(char a[],int size)
{
  int i=0;
  for(i=0;i<size;i++)
    {
      if(a[i]=='_') a[i]=' ';
    }
  
}
void   cutName(char *s3,char*s4)
{
  int i=0,j=0,k=0;
  //cat s3->s5
  if(strlen(s3)==0) s4[0]='\0';
  for(i=strlen(s3)-1;i>=0;i--)
    {
      if(s3[i]==' ') break;
    }
  if(i!=-1)
    {
      for (j=i+1;j<strlen(s3);j++)
	{ s4[k]=s3[j];k++; }
      s4[k]='\0';
  
      s3[i]='\0';
    }
  else{
    strcpy(s4,s3);s3[0]='\0';
  }
}

int VietNamCompareName(char* s1,char*s2)
{
  //  return 0;
  if(strcmp(s1,s2)==0) return 0;
  char *s3=(char*)malloc(sizeof(char)*strlen(s1));
  char *s4=(char*)malloc(sizeof(char)*strlen(s2));
  strcpy(s3,s1);
  strcpy(s4,s2);
  char *s5=(char*)malloc(sizeof(char)*strlen(s1));
  char *s6=(char*)malloc(sizeof(char)*strlen(s2));
  
  cutName(s3,s5);
  cutName(s4,s6);
  if(strcmp(s5,s6)>0){
    //   free(s3);free(s4);free(s5);free(s6);
    return 1;}
  else if(strcmp(s5,s6)<0)
      {
	//free(s3);free(s4);free(s5);free(s6);
      return -1;
    }
  else VietNamCompareName(s3,s4);
}

#endif

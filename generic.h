#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#ifndef   __generic_H__
#define   __generic_H__
#include"data.h"


struct list_el{
  information info;
  struct  list_el *next;
};
typedef struct list_el list;


list *newNode(information );
void printlist(list *);
void readNode(list* );
int sosanhnode(list *,list *);
//insert
void insertaftercurrent  (list **,list **,list **,information );
void insertbeforecurrent(list **,list **,list **,information );
void inserthead         (list **,list **,list **,information );
void insertend          (list **,list **,list **,information );
void insertatposition   (list **,list **,list **, information,int);
//delete

void deletehead(list **,list **,list **,information *);
void deletecurrent(list **,list **,list **,information *);
int  deleteatposition(list **,list **,list **,int,information *);
int  freelist           (list **,list **,list **);
//print

void reverse (list **,list **,list **);
void printlist(list *);
void fprintlist(FILE *,list *);

//search replace
list * search(list *,information );
list *searchmovetofront(list **,list **,list **,information);
list *searchtrasnpose(list **,list **,list **,information);
void update(list *);
list *cut(list **,int ,int );
int fsplit(list **,list **,list **,int,int);
int count(list *);
list *copy(list *);


int countlist(list *root)
{
  int i=0;
  while(root!=NULL)
    {
      root=root->next;
      i++;
    }
  return i;
}

//
void duoicurrent(list **root,list **cur,list **pre)
{
  if(*root==*cur||*root==NULL) pre=NULL;
  else {
    *pre=*root;
    while((*pre)->next!=*cur){*pre=(*pre)->next;}
  }
}
// list *new=newNode(a);

list * newNode(information infor)
{
  list* a=(list *)malloc(sizeof(list));
  if(a==NULL){ printf("loi cap phat\n"); return NULL; }
  a->next=NULL;
  a->info=infor;
  return a;
  
}


void printnode(list* node)
{
  if(node!=NULL)
    printdata(node->info);
  else printf("NULL\n");
}

void printlist(list *root)
{
  if(root==NULL) printf("emtpy\n");
  while(root!=NULL)
    {
      printnode(root);
      root=root->next;
    }
  
}

void insertaftercurrent(list ** root,list**cur,list**pre,information infor)
{
  list *new=newNode(infor);
  if((*root)!=NULL)
    {
      new->next=(*cur)->next;
      (*cur)->next=new;
      *pre=*cur;
      *cur=new;
    }
  else{ *cur=new;*root=new;*pre=NULL;}
}


void insertbeforecurrent(list **root,list**cur,list**pre,information infor)
  {
  list *new=newNode(infor);
  if((*root)!=NULL)
    {
      if(*cur!=*root){
      new->next=(*cur);
      (*pre)->next=new;
      *cur=new;}
      else {new->next=*cur;*cur=new;*root=new;}
    }
     else{ *cur=new;*root=new;*pre=NULL;}
}

void  inserthead(list ** root,list **cur,list **pre,information infor)
{
 list *new=newNode(infor);
 if((*root)!=NULL){
 new->next=(*root);
 (*root)=new;
 *cur=*root;
 *pre=NULL;
 }
   else{ *cur=new;*root=new;*pre=NULL;}
}

void insertend(list **root,list **cur,list **pre,information info )
{
  list *new=newNode(info);
  if((*root)!=NULL)
    {
      while(*cur!=NULL)
	{
	  *pre= *cur;
	  (*cur)=(*cur)->next;
	}
      (*cur)= new;
      (*pre)->next=*cur;
    }

  else{ *cur=new;*root=new;*pre=NULL;}

}


void insertatposition(list **root,list**cur,list **pre,information info,int n)
{
  if(*root!=NULL){
    if(n==0) inserthead(root,cur,pre,info);
    else {
      *cur=*root;
      *pre=*root;
      int i=1;
      while((*cur)->next!=NULL&&i!=n)
	{
	  i++;*pre=*cur;*cur=(*cur)->next;
	}
      list *temp=newNode(info);
      temp->next=(*cur)->next;
      (*cur)->next=temp;
      *pre=*cur;
      *cur=temp;
    }
  }
  else {*root=newNode(info);*cur=*root;*pre=NULL;}

}


//deletehead(&root,&cur,&pre)
void deletehead(list **root,list **cur,list **pre,information *trave)
{
  if(*root!=NULL){
    *trave=(*root)->info;
    (*cur)=(*root)->next;
    free(*root);
    *root=*cur;
    *pre=NULL;}
  else printf("NULL\n");
}

void deletecurrent(list **root,list **cur,list **pre,information *trave)
{
  if((*root)!=NULL)
    {
      if(*cur!=*root)
	{
	  *trave=(*cur)->info;
	  (*pre)->next=(*cur)->next;
	  free(*cur);
	  *cur=*pre;
	  *pre=*root;
	  while((*pre)->next!=*cur&&*pre!=*cur){*pre=(*pre)->next;}
	}
      else 
	if ((*root)->next==NULL)
	  {
	    *trave=(*root)->info;
	    free(*root);*cur=NULL;*root=NULL;}
	else {*trave=(*root)->info;*cur=(*root)->next;free(*root);*root=*cur;}
    }
  else
    {
      printf("NULL\n");
    }
  
}
// deleteatposition
int deleteatposition(list **root,list **cur,list **pre,int n,information *trave)
{
  list *tpre,*tcur;
  if(n==0)
    {
      tcur=*root;
      *root=(*root)->next;
      *trave=tcur->info;
      free(tcur);
      return 0;
    }
  if(*root!=NULL)
    {
      tcur=*root;
      int i=0;
      if(n==0)
	{
	  *trave=(*root)->info;
	  *cur=(*root)->next;free(root);
	  *root=*cur;*pre=NULL;return 0;}
      while((tcur)->next!=NULL&&i!=n)
	{
	  i++;
	  tpre=tcur;
	  tcur=(tcur)->next;
	}
      if(i!=n){
	printf("error: only exits %d node while n= %d\n",i+1,n);
	return 0;}
      else
	{(tpre)->next=(tcur)->next;*trave=tcur->info;
	  free(tcur);tcur=(tpre)->next;*cur=tcur;*pre=tpre;}
      
    }
  else { printf("NULL\n");}
  
}

  
//
//freelist( &root,&cur,&pre);
//success=> 1 error => 0
int freelist(list **root,list **cur,list **pre)
{
  list *temp=malloc(sizeof(list));
  while((*root)!=NULL)
  {
    temp=(*root);
    (*root)=(*root)->next;
    free(temp);
  }
  *cur=NULL;
  *pre=NULL;
  if((*root)==NULL) return 1;
  else return 0;
}
// reverse(&root);
void reverse (list ** root,list **cur,list **pre)
{
  if(*root==NULL) printf("NULL\n");
  else  if((*root)->next!=NULL)
    { *cur=(*root)->next;
      *pre=(*cur)->next;
      (*root)->next=NULL;
      
      while(*cur!=NULL)
	{
	  (*cur)->next=*root;
	  *(root)=*cur;
	  *cur=*pre;
	  if(*pre!=NULL) *pre=(*pre)->next;    
	}
      *cur=*root;
      *pre=NULL;
    }
  
}

//printlist(root)
list * search(list *root,information s)
{
  list *temp=root;
  while(temp!=NULL)
    {
      if(sosanhkey(s,temp->info)==0)return temp;
      temp=temp->next;
    }
  return NULL;
}

list * searchmovetofront(list **root,list **cur,list **pre,information s)
{
  list *temp=*root;
  list *temp2;
  if(*root==NULL) return NULL;
  if(sosanhkey(s,temp->info)==0)
    { *cur=*root;
      *pre=NULL;
      return *root;
    }
  while(temp->next!=NULL)
    {
      if(sosanhkey(s,temp->next->info)==0){

	temp2=temp->next;
	temp->next=temp2->next;
	temp2->next=*root;
	*root=temp2;
	*cur=*root;
	*pre=NULL;
	return *root;
      }
      temp=temp->next;
    }
 
  return NULL;
}

list *searchtrasnpose(list **root,list **cur,list **pre,information s){
  list *temp=*root;
  list *temp2,*temp3;
  if(*root==NULL) return NULL;
  if(sosanhkey(s,temp->info)==0)
    {
      *cur=*root;
      *pre=NULL;
      return *root;
    }
  if(sosanhkey(s,temp->next->info)==0)
    {
      temp2=temp->next;
      temp->next=temp2->next;
      temp2->next=temp;
      *root=temp2;
      *cur=*root;
      *pre=NULL;
      return *root;
    }
  while(temp->next->next!=NULL)
    {
      if(sosanhkey(s,temp->next->next->info)==0){
	
	temp2=temp->next;
	temp3=temp2->next;
	temp2->next=temp3->next;
	temp->next=temp3;
	temp3->next=temp2;
	*pre=temp;
	*cur=temp3;
	return temp3;
      }
      temp=temp->next;
    }
  return NULL;

  
}
void update(list *node)
{
  if(node==NULL) printf("NULL\n");
  else{
    getinfo(&(node->info));
  }
}

//cut
/*
list * cut(list **root,int start,int n)
{
  list * root1;
  list *temp=*root,*cur,*pre;
  int i=1;
  if((start+n)>count(*root)) return NULL;
  while(temp->next!=NULL&&i<start)
    {
      pre=temp;
      temp=temp->next;
      i++;
    }
  cur=temp;
  while(temp!=NULL&&i<(n+start))
    {
      cur=cur->next;
      i++;
    }
  root1=temp->next;
  temp->next=cur->next;
  cur->next=NULL;
  
  
  return root1;

}

// fspit
 int fsplit(list **root,list **root1,list **root2,int start,int n)
{
  list *temp,*cur,*pre;
  int i=0;
  if((start+n)>count(*root)) return 1;
  while(temp->next!=NULL&&i<start)
    {
      pre=temp;
      temp=temp->next;
      i++;
      
    }
   while(temp!=NULL&&i<=(n+start))
    {
      cur=cur->next;
      i++;
    }

  
  return 0;

}


list *copy(list *root){
  list *root1,*cur,*pre;
  while(root!=NULL)
    {
      insertend(&root1,&cur,&pre,root->info);
      root=root->next;
    }
  return root1;
}


*/



#endif

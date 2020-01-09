#ifndef __hangdoi_H__
#define __hangdoi_H__
#include "generic.h"
void enqueue(list **root,list **last,information info)
{
  list *new=(list *)malloc(sizeof(list));
  new->info=info;
  if((*root)!=NULL)
    {
      new->next=*root;
      (*root)=new;
      
    }
  else {(*root)=new;*last=new;new->next=NULL;}
}

information dequeue(list **root,list **last)
{
  if((*root)!=NULL)
    {
      
      list *temp=*root;
      information p=(*last)->info;

      if((*root)->next==NULL)
	{*root=NULL;
	  *last=NULL;
	  free(temp);
	  return p;
	}
     else  
       {
	 while(temp->next!=*last)
	   temp=temp->next;
	 *last=temp;
	 temp=temp->next;
	 (*last)->next=NULL;

	 free(temp);
	 return p;
       }
      
    }
  return datanull;
  
}
information flast(list *last)
{
  if (last!=NULL)
    {
      return last->info;
    }
  else return datanull;
}

void freequeue(list ** root)
{
  list *temp=*root;
  while(temp!=NULL)
    {
      *root=(*root)->next;
      free(temp);
      temp=*root;
    }

}

#endif

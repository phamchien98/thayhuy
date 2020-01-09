#ifndef __nganxep_H__
#define __nganxep_H__

#include"generic.h"
int isemptyqueue(list * top)
{
  return top==NULL;
}

void push(list **top,information info)
{
 list *new=(list *)malloc(sizeof(list));
  new->info=info;
  new->next=(*top);
  (*top)=new;

}

information pop(list **top)
{
  list *temp=*top;
  information data;
  if(!isemptyqueue(*top))
    {
      (*top)=(*top)->next;
      data=temp->info;
      free(temp);
      return data;
    }
  else return datanull;
}
information top(list *top)
{
  if(!isemptyqueue(top))
    {
      return top->info;
    }
  else return datanull;
}


#endif

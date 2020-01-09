#ifndef __sort_H__
#define __sort_H__
#include "data.h"
///heap sort

void heapmaxpify(information a[],int i,int end)
{
  int max=i;
  if(2*i+1<=end&&sosanhkey(a[2*i+1],a[max])==1)
    {
      max=2*i+1;
    }
  if(2*i+2<=end&&sosanhkey(a[2*i+2],a[max])==1)
    {
      max=2*i+2;
    }
   if(max!=i){
     swapdata(&a[i],&a[max]);
     heapmaxpify(a,max,end);
   }
  
}
void built_max_heap(information a[],int end)
{
  int i;
  for(i=end;i>=0;i--)
    {
      heapmaxpify(a,i,end);
    }

}
// danh so tu 0
void heapsort(information a[],int end)
{
  int j;
  built_max_heap(a,end);
  //  for(j=0;j<=end;j++)printdata(a[j]);
   //   printf("built ok\n");
  int i=end;
  for(;i>=1;i--){
    //   printf("swap %s %s\n",a[0].hoten,a[i].hoten );
  swapdata(&a[0],&a[i]);
  heapmaxpify(a,0,i-1);
  }
}


/********************** merge sort**********/



//////// quick sort
int partition(information a[],int left,int right)
{
  int i=left,j=right+1;
  while(i<j)
    {
      i=i+1;
      while(i<=right&&sosanhkey(a[i],a[left])==-1)
	{
	  i++;
	}
      j--;
      while(j>=left&&sosanhkey(a[j],a[left])==1)
	{
	  j--;
	}
      swapdata(&a[i],&a[j]);

    }
  swapdata(&a[i],&a[j]);swapdata(&a[j],&a[left]);
  return j;
  
}



void quicksort(information a[],int p,int q)
{
  if(p<q)
    {
      int pivot=partition(a,p,q);
      if(p<pivot)
	quicksort(a,p,pivot-1);
      if(pivot<q)
	quicksort(a,pivot+1,q);
    }
  
}
////



#endif

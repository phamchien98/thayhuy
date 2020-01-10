#ifndef __binarytree_H__
#define __binarytree_H__
#include"tree.h"

treenode * binaryparent(treenode *root,treenode *child)
{
  if(root==child||root==NULL){return NULL;}
  else if(root->left=child) return root;
  else if(root->right=child) return root;
  else if(sosanhkey(root->info,child->info)>0)
    return binaryparent(root->left,child);
  else return binaryparent(root->right,child);
}


int binaryadd(treenode **root,information info){
  treenode temp;
  if(*root==NULL){ 
    *root=creatnewNode(info);
    (*root)->left=NULL;
    (*root)->right=NULL;
    //   printf("____\n");
  }
  else
    {

      temp=**root;
      if(sosanhkey(temp.info,info)>=0)
      	{//printf("add trai\n");
      	  binaryadd(&((*root)->left),info);
      	}
      else
      	{
      	  // printf("add phai\n");
      	 binaryadd(&((*root)->right),info);
      	}
    }

}


int binaryadd_key2(treenode **root,information info){
  treenode temp;
  if(*root==NULL){ 
    *root=creatnewNode(info);
    (*root)->left=NULL;
    (*root)->right=NULL;
    //   printf("____\n");
  }
  else
    {

      temp=**root;
      // printf("%s %f %d",temp.info.hoten,temp.info.diem,sosanhkey2(temp.info,info));
      if(sosanhkey2(temp.info,info)>=0)
        {//printf("add trai\n");
          binaryadd_key2(&((*root)->left),info);
        }
      else
        {
          // printf("add phai\n");
         binaryadd_key2(&((*root)->right),info);
        }
    }

}



treenode* binarysearch(treenode*root,information info){
  
  if(root==NULL) return NULL;
  
  if (sosanhkey(root->info,info)==0)
    { return root;}
 else  if(sosanhkey(root->info,info)<0)
    {
      //  printf("re phai\n");
      return binarysearch(root->right,info);
    }
 else  if(sosanhkey(root->info,info)>0)
    {
      //  printf("re trai\n");
      return binarysearch(root->left,info);
    }
}

treenode* binarysearch_phanbiethoatthuong(treenode*root,information info){
  
  if(root==NULL) return NULL;
  
  if (sosanhkeyphanbiethoathuong(root->info,info)==0)
    { return root;}
 else  if(sosanhkeyphanbiethoathuong(root->info,info)<0)
    {
      //  printf("re phai\n");
      return binarysearch_phanbiethoatthuong(root->right,info);
    }
 else  if(sosanhkeyphanbiethoathuong(root->info,info)>0)
    {
      //  printf("re trai\n");
      return binarysearch_phanbiethoatthuong(root->left,info);
    }
}


treenode *leftmost_child(treenode *root){
  if(root==NULL||(root->left==NULL&&root->right==NULL))
    return NULL;
  else if(IsLeaf(root->left)) return root->left;
  else if(root->left!=NULL)return leftmost_child(root->left);
  else return leftmost_child(root->right);
}

treenode * MAX_tree(treenode*root){
  if(root==NULL) return NULL;
  else if(root->right==NULL)
    return root;
  else{
    return MAX_tree(root->right);
  }
    
}
treenode * MIN_tree(treenode* root)
{
if(root==NULL) return NULL;
  else if(root->left==NULL)
    return root;
  else{
    return MIN_tree(root->left);
  }
}



void binarydelete(treenode **root,information key,information *trave){
  
  if(*root==NULL) {return;}

  
  if(sosanhkey(key,(*root)->info)<0)
    {
      binarydelete(&(*root)->left,key,trave);
    }
  else  if(sosanhkey(key,(*root)->info)>0)
    {binarydelete(&(*root)->right,key,trave);}
  
  // leaf
  
  else if((*root)->left==NULL&&(*root)->right==NULL)
    {
      *trave=(*root)->info;
      treenode *temp=*root;
      *root=NULL;
      free(temp);
      return ;
    }
  
  // don't have left child
  else if((*root)->left==NULL)
    {
      treenode *temp=*root;
      *trave=(*root)->info;
      (*root)=(*root)->right;
      free(temp);
      return ;
    }
  // don't have right child
  else if((*root)->right==NULL)
    {
      treenode *temp=*root;
      (*root)=(*root)->left;
      free(temp);
      
      return ;
    }
  // have right child and left child
  
  else {
    treenode *temp=(*root)->right;
    treenode *temp2=*root;
    while(temp->left!=NULL)
      {
	temp2=temp;
	temp=temp->left;
      }
    
    (*root)->info=temp->info;
    temp2->left=temp->right;
    *trave=temp->info;
    free(temp);
  }
  
}


void printtreee(treenode *root){
  if (root==NULL){
    return ;
  }
  printtreee((*root).left);
  printf("%s %s\n",(*root).info.tienganh,(*root).info.tiengviet);
  // if (strcmp((*root).info.hoten,"Admin")!=0){
    
  // }
  
  printtreee((*root).right);
}

void fprinttreee(treenode *root,FILE *file){
  if (root==NULL){
    return ;
  }
  fprinttreee((*root).left,file);
  // if (strcmp((*root).info.hoten,"Admin")!=0){
    // fprintf(file, "chien" );
    // printf("hello\n");
    // printf("%s %s %f\n",(*root).info.hoten,(*root).info.password,(*root).info.diem);
    fprintf(file,"%s %s %f\n",(*root).info.hoten,(*root).info.password,(*root).info.diem);
  
  
  fprinttreee((*root).right,file);
}


void copy_allnode_order_byscore(treenode *root,treenode **temp_tree){

  if(root==NULL){
    return;
  }
  binaryadd_key2(temp_tree,(*root).info);
  copy_allnode_order_byscore((*root).left,temp_tree);
  copy_allnode_order_byscore((*root).right,temp_tree);

}
void printtreee_byscore(treenode *root){
  if (root==NULL){
    return ;
  }
  treenode *temp_tree=NULL;


  copy_allnode_order_byscore(root,&temp_tree);
  printtreee(temp_tree);



  // printtreee((*root).left);
  // printf("%s %s %f\n",(*root).info.hoten,(*root).info.password,(*root).info.diem);
  // printtreee((*root).right);
}


void freeallnodetree(treenode **root){

}

#endif

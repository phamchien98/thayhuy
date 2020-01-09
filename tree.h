#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"data.h"
#include<string.h>

#ifndef   __tree_H__
#define   __tree_H__
typedef struct treenode{
  information info;
  struct treenode * left;
  struct treenode *right;
}treenode;

int isemptytree(treenode *);
void freetree(treenode **);
int IsLeaf(treenode *);
int counttree(treenode *);

treenode * creatnewNode(information);
treenode * creatfrom2tree(information ,treenode*,treenode*);

int height(treenode*);
void printtreenode(treenode*);
void inordertree(treenode*);
void preordertree(treenode*);
void postordertree(treenode*);
void printtangthun(treenode *,int );


int isemptytree(treenode *root)
{
  return root==NULL;

}

void freetree(treenode **root)
{

  if(*root!=NULL)
    {
      if((*root)->left!=NULL)
	freetree(&((*root)->left));
      if((*root)->right!=NULL)
	freetree(&((*root)->right));
      free(*root);
      *root=NULL;
    }
}

int IsLeaf(treenode *treenode)
{
  if(treenode==NULL) return 0;
  return (treenode->left==NULL&&treenode->right==NULL);

}

int counttree(treenode *root)
{
  if(root==NULL) return 0;
  return counttree(root->left)+counttree(root->right)+1;
}

treenode * creatfrom2tree(information info,treenode*root1,treenode* root2)
{
  treenode *root=(treenode*)malloc(sizeof(treenode));
  root->info=info;
  root->left=root1;
  root->right=root2;
  return root;
}

treenode * creatnewNode(information info)
{
  treenode* newnode= (treenode *)malloc(sizeof(treenode));
  newnode->info=info;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}

int height(treenode*root)
{
  if(root==NULL) return 0;
  else{
    int a=height(root->left);
    int b=height(root->right);
    if(a>=b)return a+1;
    else return b+1;}
}
void printtreenode(treenode*node)
{
  if(node!=NULL)
    printdata(node->info);
}
void inordertree(treenode*root)
{

  if(root!=NULL)
    {
      printtreenode(root);
      inordertree(root->left);
      inordertree(root->right);
    }
}


void preordertree(treenode*root)
{
  
  if(root!=NULL){
    preordertree(root->left);
    printtreenode(root);
    preordertree(root->right);
  
  }
}

void postordertree(treenode*root)
{
  
  if(root!=NULL){
    postordertree(root->left);
    postordertree(root->right);
    printtreenode(root);
  }
}



#endif

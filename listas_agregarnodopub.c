#include "TPO.h"

void AgregarNodoPub(POST *post, NodePub *root)
{
  NodePub *current=root;
  
   if(current==NULL){
    root = (NodePub*)malloc(sizeof(NodePub));
    root->post=*post;
    return;
  }
  
  while(current->nxt!=NULL){
    current=current->nxt;
  }
  current->nxt=(NodePost*)malloc(sizeof(NodePost));
  current->nxt->post=*post;
  return;
}
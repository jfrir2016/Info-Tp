#include "TPO.h"

int BorrarPub(int id, NodePost *root)
{
  NodePost anterior=*root;
  NodePost current=*root;
  while(current->post.id!=id){
    anterior=current;
    if(current->next==NULL){
      return 1;
    }
    current=current->nxt;
  }if(current!=*root){
    anterior->nxt=current->next;
    if(current.post.root!=NULL){
      free(current.post.root);
    }
  }else{
    if(current.post.root!=NULL){
      free(current.post.root);
    }
    *root=current->next;
  }return 0;
}
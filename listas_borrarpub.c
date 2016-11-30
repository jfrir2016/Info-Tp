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
    while(current.post.root!=NULL){
      BorrarComentario(current.post.root->comentario.id, current.post.root);
    }
    free(current);
  }else{
    while(current.post.root!=NULL){
      BorrarComentario(current.post.root->comentario.id, current.post.root);
    }
    *root=root->next;
    free(current);
  }return 0;
}
#include "TPO.h"

int BorrarPub(int id, NodePub *root)
{
  NodePub anterior=*root;
  NodePub current=*root;
  while(current->publicacion.id!=id){
    anterior=current;
    if(current->next==NULL){
      return 1;
    }
    current=current->nxt;
  }if(current!=*root){
    anterior->nxt=current->next;
  }else{
    free(current.publicacion.*root);
    *root=current->next
  }return 0;
}
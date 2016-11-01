#include "TPO.h"

int BorrarUsuario(int id, NodeUser *root)
{
  NodeUser anterior=*root;
  NodeUser current=*root;
  while(current->user.id!=id){
    anterior=current;
    if(current->next==NULL){
      return 1;
    }
    current=current->nxt;
  }if(current!=*root){
    anterior->nxt=current->next;
  }else{
    *root=current->next
  }return 0;
}
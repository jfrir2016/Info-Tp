#include "TPO.h"

int AgregarNodoUsuario(USU *usuario, NodeUser *root)
{
  NodeUser *current=root;
  
  int id=1;
  
  if(current->user==NULL){
    current->user=*usuario;
    current->user.id=id;
    return id;
  }
  while(current->nxt!=NULL){
    current=current->nxt;
  }
  current->nxt=(NodeUser*)malloc(sizeof(NodeUser));
  current->nxt->user=*usuario;
  id=(current->user.id)++;
  current->nxt->user.id=id;
  return id;
}
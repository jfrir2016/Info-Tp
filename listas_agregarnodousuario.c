#include "TPO.h"

void AgregarNodoUsuario(USU *usuario, NodeUser *root)
{
  NodeUser *current=root;
  
  if(current==NULL){
    current->user=*usuario;
    return;
  }
  while(current->nxt!=NULL){
    current=current->nxt;
  }
  current->nxt=(NodeUser*)malloc(sizeof(NodeUser));
  current->nxt->user=*usuario;
  return;
}
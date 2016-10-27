#include "TPO.h"

void AgregarNodoPub(PUB *publicacion, NodePub *root)
{
  NodePub current=*root;
  while(current->nxt!=NULL){
    current=current->nxt;
  }current.publicacion=*publicacion;
  return;
}
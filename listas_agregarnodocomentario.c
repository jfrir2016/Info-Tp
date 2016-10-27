#include "TPO.h"

void AgregarNodoComentario(COMMT *comentario, NodeComment *root)
{
  NodeComment current=root;
  while(current->nxt!=NULL){
    current=current->nxt;
  }current.comentario=*comentario;
  return;
}
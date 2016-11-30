#include "TPO.h"

void AgregarNodoComentario(COMMT *comentario, NodePost *rootp, NodeComment *rootc)
{
  NodeComment *current=rootc;
  NodePost *currentpost=rootp;
  
  if(currentpost->post.id==comentario->idP){
    if(current==NULL){
      rootc = (NodeComment*)malloc(sizeof(NodeComment));
      rootc->comentario=*comentario;
      return;
    }
    while(current->nxt!=NULL){
      current=current->nxt;
    }
    current->nxt=(NodeComment*)malloc(sizeof(NodeComment));
    current->nxt->comentario=*comentario;
    return;
  }
  current=current->nxt;
  while(1){
    if(currentpost->post.id==comentario->idP){
    
      if(current==NULL){
	  rootc = (NodeComment*)malloc(sizeof(NodeComment));
	  rootc->comentario=*comentario;
	  return;
      }
      while(current->nxt!=NULL){
	  current=current->nxt;
      }
      current->nxt=(NodeComment*)malloc(sizeof(NodeComment));
      current->nxt->comentario=*comentario;
      return;
    }
    currentpost=currentpost->nxt;
  }
}
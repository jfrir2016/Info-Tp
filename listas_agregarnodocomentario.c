#include "TPO.h"

void AgregarNodoComentario(COMMT *comentario, NodePost *rootp, NodeComment *rootc)
{
  NodeComment *current=rootc;
  NodePost *currentpost=rootp;
  do{
      if(currentpost->post.id==comentario->idP){
	
	if(current==NULL){
	  rootc = (NodePub*)malloc(sizeof(NodePub));
	  rootc->comentario=*comentario;
	  return;
	}
	while(current->nxt!=NULL){
	  current=current->nxt;
	}
	current->nxt=(NodeComment*)malloc(sizeof(NodeComment));
	current->nxt->comentario=*comentario;
	return;
      }if(currentpost->nxt!=NULL)
	currentpost=currentpost->nxt;
  }while(currentpost->nxt!=NULL);
}
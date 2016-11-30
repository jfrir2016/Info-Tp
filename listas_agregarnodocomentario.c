#include "TPO.h"

void AgregarNodoComentario(COMMT *comentario, NodePost *rootp, NodeComment *rootc)
{
  NodeComment *current=rootc;
  NodePost *currentpost=rootp;
  do{
      if(currentpost->publicacion.id==comentario->idP){
	while(current->nxt!=NULL){
	  current=current->nxt;
	}current->comentario=*comentario;
	return;
      }if(currentpost->nxt!=NULL)
	currentpost=currentpost->nxt;
  }while(currentpost->nxt!=NULL);
}
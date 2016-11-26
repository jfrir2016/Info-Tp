#include "TPO.h"

void AgregarNodoComentario(COMMT *comentario, NodePub *rootp, NodeComment *rootc)
{
  NodeComment *current=rootc;
  NodePub *currentpub=rootp;
  do{
      if(currentpub->publicacion.id==comentario->idP){
	while(current->nxt!=NULL){
	  current=current->nxt;
	}current->comentario=*comentario;
	return;
      }if(currentpub->nxt!=NULL)
	currentpub=currentpub->nxt;
  }while(currentpub->nxt!=NULL);
}
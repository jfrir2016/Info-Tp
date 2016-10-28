#include "TPO.h"

int AgregarNodo(USU *usuario, COMMT *comentario, PUB *publicacion, Roots *roots)
{
  NodePub currentpub=*roots->rootpub;
  
  if(usuario!=NULL){
    AgregarNodoUsuario(usuario, roots->rootuser);
    return 0;
  }
  
  else if(comentario!=NULL){
    while(currentpub->next!=NULL){
      if(currentpub.publicacion.id==comentario.idP){
	AgregarNodoComentario(comentario, currentpub.publicacion.*root);
	return 0;
      }if(currentpub->nxt!=NULL)
	currentpub=currentpub->nxt;
    }
  }
  
  else if(publicacion!=NULL){
    AgregarNodoPub(publicacion, roots->rootpub);
    return 0;
  }else return 1;
}
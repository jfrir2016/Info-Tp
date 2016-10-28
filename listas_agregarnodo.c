#include "TPO.h"

int AgregarNodo(NODO *nodo, Roots *roots, int NodoTypeDescriptor)
{
  NodePub currentpub=*roots.rootpub;
  switch(NodoTypeDescriptor){
    
    case NUser:
      AgregarNodoUsuario(&(*nodo.usuariogen), roots->rootuser);
      return 0;
      break;
      
    case NPub:
      AgregarNodoPub(&(*nodo.pubgen), roots->rootpub);
      return 0;
      
    case NComm:
      while(currentpub->next!=NULL){
      if(currentpub.publicacion.id==*nodo.comentario.idP){
	AgregarNodoComentario(&(*nodo.comentario), currentpub.publicacion->root);
	return 0;
      }if(currentpub->nxt!=NULL){
	currentpub=currentpub->nxt;
      }else return 1;
    }
  }
}
#include "TPO.h"

int GuardarPost (NodePub *primero, char *archivo)
{
  FILE* fd;
  NodePub* aux;
  PUB *datos;
  
  if((fd=fopen(archivo,"w"))==NULL)
    return 1;
  for(aux=primero;aux!=NULL;)
  {
    datos=&(aux->publicacion);
    fwrite(datos,sizeof(PUB),1,fd);
    primero=aux;
    aux=aux->nxt;
    free(primero);
  }
  fclose(fd);
  return 0;
}

#include "TPO.h"

int LoadPubli (NodePub **primero,char *archivo)
{
  FILE *fd;
  NodePub *aux;
  PUB *datos
  
  if((fd=fopen(archivo,"r"))==NULL)
    return 1;
  aux=(NodePub*)malloc(sizeof(NodePub));
  *primero=aux;
  datos=&(aux->publicacion);
  fread(datos,sizeof(PUB),1,fd);
  while(!feof(fd))
  {
    aux->nxt=(NodePub*)malloc(sizeof(NodePub));
    aux=aux->nxt;
    datos=&(aux->publicacion);
    fread(datos,sizeof(PUB),1,fd);
  }
  fclose(fd);
  aux->nxt=NULL;
  return 0; 
}

  
  
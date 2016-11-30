#include "TPO.h"

int LoadComments (NodePub **primero)
{
  FILE *fd;
  NodeComment *aux,*first;
  NodePub *read;
  COMMT *datos;
  char Archivo[8];
  
  for(read=primero;read!=NULL;read=read->nxt)
  {
    sprintf(Archivo,"%d.c",read->publicacion.id);
    
    if((fd=fopen(Archivo,"r"))==NULL)
      return 1;
    
    aux=(NodeComment*)malloc(sizeof(NodeComment));
    first=aux;
    datos=&(aux->comentario);
    fread(datos,sizeof(COMMT),1,fd);
    
    while(!feof(fd))
    {
      aux->nxt=(NodeComment*)malloc(sizeof(NodeComment));
      aux=aux->nxt;
      datos=&(aux->comentario);
      fread(datos,sizeof(COMMT),1,fd);
    }
    read->publicacion.root=first;
    aux->nxt=NULL;
    fclose(fd);
  }
  return 0; 
}

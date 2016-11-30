#include "TPO.h"

int GuardarComents (NodePub *primero)
{
  FILE* fd;
  NodeComment *aux, *first;
  NodePub* read;
  COMMT *datos;
  char Archivo[8];
  
  for(read=primero;read!=NULL;read=read->nxt)
  {
    sprintf(Archivo,"%d.c",read->publicacion.id);
    
    if((fd=fopen(Archivo,"w"))==NULL)
      return 1;
    
    first=read->publicacion.root;
    for(aux=first;aux!=NULL;)
    {
      datos=&(aux->comentario);
      fwrite(datos,sizeof(COMMT),1,fd);
      first=aux;
      aux=aux->nxt;
      free(primero);
    }
    fclose(fd);
  }
  return 0;
}

  
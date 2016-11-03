#include "TPO.h"

int LoadUsuarios (USU **primero,char *archivo)
{
  FILE *fd;
  USU *aux;
  
  if((fd=fopen(archivo,"r"))==NULL)
    return 1;
  aux=(USU*)malloc(sizeof(USU));
  *primero=aux;
  fread(aux,sizeof(USU),1,fd);
  while(!feof(fd))
  {
    aux->nxt=(USU*)malloc(sizeof(USU));
    aux=aux->nxt;
    fread(aux,sizeof(USU),1,fd);
  }
  fclose(fd);
  return 0;
}

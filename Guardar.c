#include "TPO.h"

int GuardarUsuarios (USU *primero, char *archivo)
{
  FILE* fd;
  USU* aux;
  if((fd=fopen(archivo,"w"))==NULL)
    return 1;
  for(aux=primero;aux!=NULL;)
  {
    fwrite(aux,sizeof(USU),1,fd);
    primero=aux;
    aux=aux->nxt;
    free(primero);
  }
  fclose(fd);
  return 0;
}

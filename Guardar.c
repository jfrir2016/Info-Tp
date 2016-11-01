#include "TPO.h"

int GuardarUsuarios (USU *primero, char *archivo)
{
  FILE* fd;
  USU* aux;
  if((fd=fopen(archivo,"w"))==NULL)
    return 1;
  for(aux=primero;aux!=NULL;)
  {
    fprintf(fd,"%s ,%d ,%s ,%s ,%s \n",aux->Nombre,aux->Edad,aux->email,aux->Usuario,aux->Contra);
    //fprintf(fd,"%s,%d\n",aux->a.Nombre,aux->a.edad);
    primero=aux;
    aux=aux->nxt;
    free(primero);
  }
  fclose(fd);
  return 0;
}

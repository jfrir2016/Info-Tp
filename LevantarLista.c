#include "TPO.h"

int LoadUsuarios (USU **primero,char *archivo)
{
  FILE *fd;
  USU *aux;
  char buff[TAM];
  int i;
  
  if((fd=fopen(archivo,"r"))==NULL)
    return 1;
  aux=(USU*)malloc(sizeof(USU));
  *primero=aux;
  //while(!feof(fd))
  //{
    fread(buff,TAM,1,fd);
    for(i=0;buff[i]!="a";i++)
      aux->Nombre[i]=buff[i];
    //aux=aux->nxt;
  //}
  fclose(fd);
  return 0;
}


    /*fscanf(fd,"%s",aux->Nombre);
    fscanf(fd,"%s",a);

    fscanf(fd,"%s",aux->email);
    fscanf(fd,"%s",aux->Usuario);
    fscanf(fd,"%s",aux->Contra);*/
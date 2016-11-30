#include "TPO.h"

int Check (USU **cli,NodeUser *primo)
{
  int e;
  NodeUser *a;
  
  a=primo;
  
  if(a==NULL){
    return -1;
  }
  
  e=strcmp((*cli)->Usuario,a->user.Usuario);
  while(e!=0&&a->nxt!=NULL)
  {
    a=a->nxt;
    e=strcmp((*cli)->Usuario,a->user.Usuario);
  }
  if(e){
    return -1;
  }
  if(!strcmp((*cli)->Contra,a->user.Contra))
    return a->user.id;
  
  return -1;
}

    
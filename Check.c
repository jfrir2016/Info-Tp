#include "TPO.h"

int Check (USU **cli)
{
  int e;
  USU *a;
  
  a=primo;
  e=strcmp((*cli)->Usuario,a->Usuario);
  while(e!=0&&a->nxt!=NULL)
  {
    a=a->nxt;
    e=strcmp((*cli)->Usuario,a->Usuario);
  }
  if(a->nxt==NULL)
    return 1;
  if(strcmp((*cli)->Contra,a->Contra))
    return 1;
  *cli=a;
  return 0;
}

    
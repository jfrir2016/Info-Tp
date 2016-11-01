#include "TPO.h"

int Check (USU **cli,USU *primo)
{
  int e;
  USU *a;
  //b=*cli;
  a=primo;
  e=strcmp((*cli)->Usuario,a->Usuario);
  while(e!=0||a!=NULL)
  {
    a=a->nxt;
    e=strcmp((*cli)->Usuario,a->Usuario);
  }
  if(a==NULL)
    return -1;
  *cli=a;
  return 0;
}
    
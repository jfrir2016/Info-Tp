#include "TPO.h"

void NodoalaCola (USU **h,USU *aux)
{
  USU *last;
  aux->nxt=NULL;
  if(*h==NULL)
    *h=aux;
  else
  {
    for(last=*h;last->nxt!=NULL;last=last->nxt);
    last->nxt=aux;
  }
}

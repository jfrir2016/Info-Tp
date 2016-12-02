#include "TPO.h"

void ListarPost (char** buffer, NodePost *PRoot){
  int i;
  for(i=0; buffer[i]!=NULL && PRoot!=NULL ; i++, PRoot=PRoot->nxt)
    buffer[i]= PRoot->post.titulo;
  return;
}
#include "TPO.h"

POST* BuscoPost (char *name, NodePost *PRoot){
  int i;
  POST* find;
  
  find=NULL;
  
  for( i=0; PRoot!=NULL; i++, PRoot=PRoot->nxt){
    if(!strcmp(PRoot->post.titulo,name))
      find=PRoor->post;
  }
  return find;
}
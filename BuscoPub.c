#include "TPO.h"

POST* BuscoPost (char *name, NodePost *PRoot){
  int i;
  POST* find;
  
  find=NULL;
  
  for( i=0; PRoot!=NULL; i++, PRoot=PRoot->nxt){
    if(!strcmp(PRoot->post.titulo,name))
      find=PRoot->post;	//incompatible types when assigning to type ‘struct POST *’ from type ‘struct Post’: find=PRoot->post;
  }
  return find;
}
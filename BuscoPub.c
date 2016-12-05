#include "TPO.h"

POST* BuscoPost (char *name, NodePost *PRoot, int id, NodeUser *URoot)
{
  POST* find;
  NodePost *Aux
  find=NULL;
  
  for(Aux=PRoot; Aux!=NULL;Aux=Aux->nxt)
  {
    if(!strcmp(Aux->post.titulo,name))
      find=Aux->post;	//incompatible types when assigning to type ‘struct POST *’ from type ‘struct Post’: find=PRoot->post;
  }
  return find;
}
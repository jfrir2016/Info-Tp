#include "TPO.h"

int main (void)
{
  NodePub *root = (NodePub*)malloc(sizeof(NodePub));
  PUB pub;
  pub.id=0;
  pub.idU=0;
  strcpy(pub.titulo, "Hola");
  strcpy(pub.contenido, "asd");
  NodeComment *rootc = (NodeComment*)malloc(sizeof(NodeComment));
  pub.root = rootc;
  
  
  AgregarNodoPub(&pub, root);
  
  COMMT comment;
  
  comment.id=0;
  comment.idP=0;
  comment.idU=0;
  strcpy(comment.contenido, "Hola");
  
  AgregarNodoComentario(&comment, root, rootc);
  
  printf("%d, %s", rootc->comentario.id, rootc->comentario.contenido);
  return 0;
}
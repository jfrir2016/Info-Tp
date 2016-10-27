#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <netdb.h>

#define FUSU "Usuarios.csv"
#define PORT 43210
#define BUFFER 255
typedef struct User
{
  int id;
  char Nombre[20];
  int Edad;
  char Usuario[20];
  char Contra[8];
  char email[35];
}USU;

typedef struct UserNode		//Usen esto para manejar usuarios en la lista
{
  struct User user;
  struct UserNode *nxt;
}NodeUser;

typedef struct Publicacion
{
  int id;
  int idU;			//Id del usuario que la creo
  char titulo[20];
  char contenido[100];
  struct CommentNode *firstComment;
}PUB;

typedef struct PublicationNode	//Para manejar publicaciones en la lista
{
  struct Publicacion publicacion;
  struct PublicationNode *nxt;
}NodePub;

typedef struct Comentario
{
  int id;
  int idP;			//Id de la publicacion a la que pertenece
  int idU;			//Id del usuario que lo creo
  char titulo[20];
  char contenido[100];
}COMMT;

typedef struct CommentNode
{
  struct Comentario commentario;
  struct CommentNode *nxt;
}NodeComment;
  

int Registro (USU**);

void NodoalaCola (USU**,USU*);

int GuardarUsuarios (USU *primero, char *archivo);

USU* LoadUsuarios (char *);

void sigchld_handler(int);
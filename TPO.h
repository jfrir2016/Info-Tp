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

#define FUSU "Usuarios"
#define FPUB "Posts"

#define PORT 43210
#define BUFFER 255
#define NUser 1			//NodeTypeDescriptor User
#define NPub 2			//NodeTypeDescriptor Pub
#define NComm 3			//NodeTypeDescriptor Comment

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
  char contenido[500];
  struct CommentNode *root;
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
  char contenido[241];
}COMMT;

typedef struct CommentNode
{
  struct Comentario comentario;
  struct CommentNode *nxt;
}NodeComment;

typedef struct roots		//Debe ser inicializado al inicio del servidor y cargado con los roots de las listas principales
{
  NodeUser *user;
  NodePub *pub;
}Roots;


int Registro (Roots *);

int GuardarUsuarios (USU *, char *);

int GuardarPost (NodePub *, char *);

int GuardarComents (NodePub *);

int LoadUsuarios (USU**, char *);

int LoadPubli (NodePub **,char *);

int LoadComments (NodePub **);

void sigchld_handler(int);

void AgregarNodoUsuario(USU*, NodeUser*);

void AgregarNodoComentario(COMMT*, NodePub*, NodeComment*);

void AgregarNodoPub(PUB*, NodePub*);

int BorrarPub(int, NodePub);			//idem sig.

int BorrarUsuario(int, NodeUser);		//retorna 0 si se borro, 1 si no se encontro
 
int BorrarComentario(int, NodeComment);		//idem anterior

int Check (USU **,NodeUser *);
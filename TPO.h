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
  struct User *nxt;
}USU;

int Registro (USU**);

void NodoalaCola (USU**,USU*);

int GuardarUsuarios (USU *primero, char *archivo);

USU* LoadUsuarios (char *);

void sigchld_handler(int);
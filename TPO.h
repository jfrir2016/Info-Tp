#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FUSU "Usuarios.csv"

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
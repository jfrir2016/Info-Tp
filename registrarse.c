#include "TPO.h"

int Registro (USU **Primo)
{
  USU *point;
  USU *aux;
  point=(USU*)malloc(sizeof(USU));
  char Aux[8];
  int a;
  do
  {
    //system("clear");
  
    printf("Ingrese Nombre: ");
    scanf("%s",point->Nombre);
  
    printf("Ingrese edad: ");
    scanf("%d",&(point->Edad));
  
    printf("Ingrese e-mail: ");
    scanf("%s",point->email);
  
    printf("Ingrese Usuario: ");
    scanf("%s",point->Usuario);
  
    printf("Ingrese Contraseña: ");
    scanf("%s",point->Contra);
  
    printf("Repita Contraseña: ");
    scanf("%s",Aux);
    a=strcmp(point->Contra,Aux);
    if(a)
      printf("ERROR: Contraseñas diferentes\n");
    //sleep(3);
  }while(a);
  
  NodoalaCola(Primo,point);
  
  aux=*Primo;
  
  while(aux!=NULL)		//Print
	{
	  printf("%s\t%d\t%s\t%s\t%s\n",aux->Nombre,aux->Edad,aux->email,aux->Usuario,aux->Contra);
	  aux=aux->nxt;
	}
  return 0;
}
  
#include "TPO.h"

int Registro (USU **Primo)
{
  USU *point;
  char Aux[8];
  int a;
  
  point=(USU*)malloc(sizeof(USU));
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

  return 0;
}
  
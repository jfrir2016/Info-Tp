#include "TPO.h"

int Registro (Roots *Ini)
{
  NODO *point;
  char Aux[8];
  int a;
  
  point=(NODO*)malloc(sizeof(NODO));
  do
  {
    //system("clear");
  
    printf("Ingrese Nombre: ");
    scanf("%s",point->usuariogen.Nombre);
  
    printf("Ingrese edad: ");
    scanf("%d",&(point->usuariogen.Edad));
  
    printf("Ingrese e-mail: ");
    scanf("%s",point->usuariogen.email);
  
    printf("Ingrese Usuario: ");
    scanf("%s",point->usuariogen.Usuario);
  
    printf("Ingrese Contraseña: ");
    scanf("%s",point->usuariogen.Contra);
  
    printf("Repita Contraseña: ");
    scanf("%s",Aux);
    a=strcmp(point->usuariogen.Contra,Aux);
    if(a)
      printf("ERROR: Contraseñas diferentes\n");
    //sleep(3);
  }while(a);
  
  AgregarNodo(point,Ini,NUser);

  return 0;
}
  
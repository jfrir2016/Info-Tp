#include "Cliente.h"

usu* Registro (void)
{
	USU Datos;
  char Aux[8];
  int a,id;
  
  do
  {
    //system("clear");
  
    printf("Ingrese Nombre: ");
    scanf("%s",Datos.Nombre);
  
    printf("Ingrese edad: ");
    scanf("%d",&(Datos.Edad));
  
    printf("Ingrese e-mail: ");
    scanf("%s",Datos.email);
  
    printf("Ingrese Usuario: ");
    scanf("%s",Datos.Usuario);
  
    printf("Ingrese Contraseña: ");
    scanf("%s",Datos.Contra);
  
    printf("Repita Contraseña: ");
    scanf("%s",Aux);
    a=strcmp(Datos.Contra,Aux);
    if(a)
      printf("ERROR: Contraseñas diferentes\n");
    //sleep(3);
  }while(a);
  
  id=AgregarNodoUsuario(&Datos,Ini);

  return id;
}
  
#include "Cliente.h"

int Ingresar (usu *dir,IplImage* imagenFondo, char* nombreVentana)
{	/*
	printf("Ingrese Nombre de Usuario: ");
	scanf("%s",dir->Usuario);
	printf("Ingrese Contraseña: ");
	scanf("%s",dir->Contra);
	//Falta contemplar errores
	dir->id=1;
	return 0;
	*/
	crearCampodeTexto(imagenFondo);
	//Mostramos la imagen
  cvShowImage (nombreVentana,imagenFondo);
	
}
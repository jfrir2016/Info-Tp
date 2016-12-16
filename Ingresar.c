#include "Cliente.h"

int Ingresar (usu *dir,IplImage* imagenFondo, char* nombreVentana)
{
  cvZero(imagenFondo);
  
  crearCampodeTexto(imagenFondo);
  
  //Mostramos la imagen
  cvShowImage (nombreVentana,imagenFondo);
  
  leerCampodeTexto(nombreVentana, imagenFondo, dir);
  
  dir->id=1;

  return 0;
}
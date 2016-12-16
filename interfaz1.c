#include "Cliente.h"

int interfaz1 (IplImage* imagenFondo,char* nombreVentana)
{
  char a;
	int b;
	
	cvZero(imagenFondo);
  //Creamos el menu
  menuInicio(imagenFondo);
  
  //Mostramos la imagen
  cvShowImage (nombreVentana,imagenFondo);
  
  a = cvWaitKey(0);
	printf("%c\n",a);
	fflush(stdout);
	a=a-'0';
	b=a;
  return b;
}
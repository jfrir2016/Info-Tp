#include "Cliente.h"

int interfaz1 (void){
  int a;
  //Creamos una ventana de tamaño HEIGHTxWIDTH
  cvNamedWindow("Boton",  CV_WINDOW_NORMAL);
  cvResizeWindow("Boton", HEIGHT, WIDTH);

  //Creamos una imagen de fondo que podamos modificar del mismo tamaño que la pantalla
  IplImage* imagenFondo = cvCreateImage(cvSize(HEIGHT,WIDTH), 8, 3);
  cvZero(imagenFondo);
  
  //Creamos el menu
  menuInicio(imagenFondo);
  
  //Mostramos la imagen
  cvShowImage ("Boton",imagenFondo);
  
  a= cvWaitKey(0) -'0'-1;
  
  cvReleaseImage(&imagenFondo);
  cvDestroyWindow("Boton");
  
  return a;
}
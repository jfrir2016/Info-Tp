//MENU PRINCIPAL
//no me anda
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#define HEIGHT 1000
#define WIDTH 700

void menuPrincipal(IplImage*, int);

int main(void){

  cvNamedWindow("menuPrincipal", CV_WINDOW_NORMAL);
  cvResizeWindow("menuPrincipal", HEIGHT, WIDTH);
  
  IplImage* imagenFondo = cvCreateImage(cvSize(HEIGHT,WIDTH), 8, 3);
  cvZero(imagenFondo);
  
  menuPrincipal(imagenFondo,1);
  
  cvShowImage("menuPrincipal", imagenFondo);
  
  cvWaitKey(0);
  
  cvReleaseImage(&imagenFondo);
  cvDestroyWindow("menuPrincipal");
  
  return 0;
  
}

void menuPrincipal(IplImage* imagenFondo, int id){
  
  int rectanguloDesdeDonde_X = HEIGHT/2-100;
  int rectanguloDesdeDonde_Y = 90;
  int rectanguloHastaDonde_X = rectanguloDesdeDonde_X + 200;
  int rectanguloHastaDonde_Y = rectanguloDesdeDonde_Y + 50;
  
  int i;
  
  char buffer[5][25];
  strcpy(buffer[0],"1) Ver publicaciones");
  strcpy(buffer[1],"2) Crear publicacion");
  strcpy(buffer[2],"3) Borrar publicacion");
  strcpy(buffer[3],"4) Darse de baja");
  strcpy(buffer[4],"5) Salir");
  
  CvFont admin;
  CvFont textos;
  CvFont infonianos;
  CvFont encabezado;
  
  //Incializamos las fuentes
  cvInitFont(&admin,CV_FONT_HERSHEY_SIMPLEX, 0.7, 0.8, 0, 2,8);
  cvInitFont(&infonianos,CV_FONT_HERSHEY_SIMPLEX,1.5,1.5, 0, 6,8);
  cvInitFont(&encabezado,CV_FONT_HERSHEY_SIMPLEX, 0.4, 0.5, 0, 1,8);
  
  if(id==1){
    cvPutText (imagenFondo,"Modo administrador", cvPoint(20,WIDTH-20), &admin, cvScalar(0,255,0,0));
  }
  
  cvPutText (imagenFondo,"INFONIANOS",cvPoint(20,50),&infonianos,cvScalar(255,255,0,0));
  cvPutText (imagenFondo,"Just post it!",cvPoint(20,70),&encabezado,cvScalar(255,255,0,0));
  cvPutText (imagenFondo,"Menu principal",cvPoint(HEIGHT/2-20, 80),&textos,cvScalar(255,255,255,0));
  
  for (i=0;i<5;i++){
    cvRectangle (imagenFondo,
			    cvPoint (rectanguloDesdeDonde_X, rectanguloDesdeDonde_Y+(i*25)),
			    cvPoint (rectanguloHastaDonde_X, rectanguloHastaDonde_Y+(i*25)),
			    cvScalar (255,255,255,0),1,8,0);
    
    cvPutText (imagenFondo,buffer[i], 
			   cvPoint(rectanguloDesdeDonde_X +10,rectanguloDesdeDonde_Y+(i*25)+10),
			   &textos,
			   cvScalar(255,255,255,0));
  }
    
}
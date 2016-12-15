#include "Cliente.h"

void menuInicio (IplImage* imagenFondo)
{
  int rectanguloDesdeDonde_X = HEIGHT*0.2;
  int rectanguloDesdeDonde_Y = WIDTH*0.5;
  int rectanguloHastaDonde_X = rectanguloDesdeDonde_X + REC_TAM_X;
  int rectanguloHastaDonde_Y = rectanguloDesdeDonde_Y + REC_TAM_Y;
  int BrectanguloDesdeDonde_X = rectanguloDesdeDonde_X + 400;
  int BrectanguloHastaDonde_X = rectanguloHastaDonde_X + 400;

  CvFont Font;
  CvFont Titulo;
  CvFont Encabezado;

  //Incializamos las fuentes
  cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.7, 0.8, 0, 2,8);
  cvInitFont(&Titulo,CV_FONT_HERSHEY_SIMPLEX,1.5,1.5, 0, 6,8);
  cvInitFont(&Encabezado,CV_FONT_HERSHEY_SIMPLEX, 0.4, 0.5, 0, 1,8);

  cvPutText (imagenFondo,"Bienvenido al Foro",cvPoint(HEIGHT/2-125, 200), &Font, cvScalar (255,255,255,0));
  cvPutText (imagenFondo,"INFONIANOS",cvPoint(20,50),&Titulo,cvScalar(255,255,0,0));
  cvPutText (imagenFondo,"Just post it!",cvPoint(20,70),&Encabezado,cvScalar(255,255,0,0));

  cvRectangle (imagenFondo,
			  cvPoint (rectanguloDesdeDonde_X, rectanguloDesdeDonde_Y),
			  cvPoint (rectanguloHastaDonde_X, rectanguloHastaDonde_Y),
			  cvScalar (255,255,255,0),1,8,0);

  cvPutText (imagenFondo,"1)Ingresar",cvPoint(rectanguloDesdeDonde_X + 10, rectanguloDesdeDonde_Y + 30), &Font, cvScalar (255,255,255,0));

  cvRectangle (imagenFondo,
			  cvPoint (BrectanguloDesdeDonde_X, rectanguloDesdeDonde_Y),
			  cvPoint (BrectanguloHastaDonde_X, rectanguloHastaDonde_Y),
			  cvScalar (255,255,255,0),1,8,0);

  cvPutText (imagenFondo,"2)Registrarse",cvPoint(BrectanguloDesdeDonde_X + 10, rectanguloDesdeDonde_Y + 30), &Font, cvScalar (255,255,255,0));
}
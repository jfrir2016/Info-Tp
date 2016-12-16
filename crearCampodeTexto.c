#include "Cliente.h"

void crearCampodeTexto(IplImage* imagenFondo)
{
	// Realizamos calculos para definir los puntos (x,y)
	int rectanguloDesdeDonde_X = ANCHO *0.6;
	int rectanguloDesdeDonde_Y = ALTO *0.25;
	int rectanguloHastaDonde_X = rectanguloDesdeDonde_X + REC_TAM_X;
	int rectanguloHastaDonde_Y = rectanguloDesdeDonde_Y + REC_TAM_Y;
	
	CvFont Font;
	cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.7, 0.8, 0, 2,8);
	// Creamos un rectangulo y se lo asignamos a la imagen de fondo
	cvRectangle (imagenFondo,
				 cvPoint (rectanguloDesdeDonde_X, rectanguloDesdeDonde_Y),
				 cvPoint (rectanguloHastaDonde_X, rectanguloHastaDonde_Y),
				 cvScalar (255,255,255,0),1,8,0);
	// Ponemos un texto de referencia
	cvPutText (imagenFondo,"Nombre de usuario:",cvPoint(rectanguloDesdeDonde_X + 35, rectanguloDesdeDonde_Y - 8), &Font, cvScalar (255,255,255,0));
	
	cvRectangle (imagenFondo,
				 cvPoint (rectanguloDesdeDonde_X, rectanguloDesdeDonde_Y+2*REC_TAM_Y),
				 cvPoint (rectanguloHastaDonde_X, rectanguloHastaDonde_Y+3*REC_TAM_Y),
				 cvScalar (255,255,255,0),1,8,0);
	// Ponemos un texto de referencia
	cvPutText (imagenFondo,"Contraseña:",cvPoint(rectanguloDesdeDonde_X + 35, rectanguloDesdeDonde_Y - 8), &Font, cvScalar (255,255,255,0));
}
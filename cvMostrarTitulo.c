#include "Cliente.h"

void cvMostrarTitulo (IplImage* imagenFondo)
{
  CvFont infonianos;
  CvFont encabezado;
  
  cvInitFont(&infonianos,CV_FONT_HERSHEY_SIMPLEX,1.5,1.5, 0, 6,8);
  cvInitFont(&encabezado,CV_FONT_HERSHEY_SIMPLEX, 0.4, 0.5, 0, 1,8);
  
  cvPutText (imagenFondo,"INFONIANOS",cvPoint(20,50),&infonianos,cvScalar(255,255,0,0));
  cvPutText (imagenFondo,"Just post it!",cvPoint(20,70),&encabezado,cvScalar(255,255,0,0));
  return;
}
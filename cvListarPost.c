#include "Cliente.h"
int cvListarPost(IplImage* imagenFondo, char* nombreVentana, int sockfd)
{
  cvZero(imagenFondo);
  
  int cant, i,aux,j;
  char buffer[BUFFER];
  int a;
  
  int recDesdeDonde_X= ANCHO/4;
  int recDesdeDonde_Y= ALTO/4;
  int recHastaDonde_X= recDesdeDonde_X + REC_TAM_X;
  int recHastaDonde_Y= recDesdeDonde_Y + REC_TAM_Y;
  
  CvFont Font;
  cvInitFont(&Font, CV_FONT_HERSHEY_SIMPLEX, 0.7, 0.8, 0, 2, 8);
  
  if((recv(sockfd,&cant,sizeof(int),0))==-1)
  {
    perror("Recv");
    exit(1);
  }
  
  printf("Caantidad: %d\n",cant);
  fflush(stdout);
  
  cvMostrarTitulo(imagenFondo);
  
  if(cant==0)
  {
    cvPutText(imagenFondo,"No hay publicaciones",cvPoint(ANCHO/2-100,ALTO/2),&Font,cvScalar(0,0,255,0));
    cvPutText(imagenFondo,"ENTER para continuar",cvPoint(ANCHO/2-100,ALTO/2+30),&Font,cvScalar(0,0,255,0));
    cvShowImage(nombreVentana,imagenFondo);
    cvWaitKey(0);
    return -1;
  }
  
  for(i=1,aux=0,j=0 ;i<=cant; i++,aux++)
  {
    printf("i: %d\nj: %d",i,j);
  fflush(stdout);
    if((recv(sockfd,buffer,BUFFER,0))==-1)
    {
      perror("Recv");
      exit(1);
    }
    
    if(aux==4){aux=0;j++;}
    if(j==2 && i!=cant)
    {
      cvRectangle(imagenFondo,
			      cvPoint(ANCHO-300,ALTO-100),
			      cvPoint(ANCHO-300+REC_TAM_X+100,ALTO-100+REC_TAM_Y),
			      cvScalar(255,0,0,0),1,8,0);
      cvPutText(imagenFondo,"ENTER pagina siguiente",cvPoint(ANCHO-290,ALTO-70),&Font,cvScalar(255,255,255,0));
      cvShowImage(nombreVentana,imagenFondo);
      
      a = (int)cvWaitKey(0);
      
      if(a=='\n')
      {
	j=0;
	cvZero(imagenFondo);
      }
      else
      {
	if((send(sockfd,&a,sizeof(int),0))==-1)	//Envio seleccion
	{
	  perror("Send");
	  exit(1);
	}
	return 0;
      }
    }
    cvRectangle(imagenFondo,
			      cvPoint(recDesdeDonde_X+((REC_TAM_X*2)*j),recDesdeDonde_Y+(REC_TAM_Y*aux+10)),
			      cvPoint(recHastaDonde_X+((REC_TAM_X*2)*j),recHastaDonde_Y+(REC_TAM_Y*aux+10)),
			      cvScalar(255,255,255,0),1,8,0);
    cvPutText(imagenFondo,buffer,cvPoint(recDesdeDonde_X+10+((REC_TAM_X*2)*j),recDesdeDonde_Y+30+(REC_TAM_Y*aux+10)),&Font,cvScalar(255,255,255,0));
    cvShowImage(nombreVentana,imagenFondo);
    
    if(i==cant)
    {
      a=(int)cvWaitKey(0);
      if((send(sockfd,&a,sizeof(int),0))==-1)	//Envio seleccion
      {
	perror("Send");
	exit(1);
      }
    }
  }
  return 0;
}
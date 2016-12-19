//	CLIENT

#include "Cliente.h"

int main(void)
{
  
  char buffer[BUFFER];
  int sockfd;
  int a, id, cant, i=0;
  
  usu buff;
  post bufp;
  int (*Menu1[])(usu*,IplImage*,char*,int)={Ingresar,Registro};
	
  struct sockaddr_in server_addr;
  struct sockaddr_in my_addr;
   
  if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
  {
    perror("Socket");
    exit(1);
  }
  
  server_addr.sin_family= AF_INET;
  server_addr.sin_port= htons(PORT);
  server_addr.sin_addr.s_addr=inet_addr(IP);
  memset(&(server_addr.sin_zero),'\0',8);
  
  my_addr.sin_family= AF_INET;
  my_addr.sin_port= 0;
  my_addr.sin_addr.s_addr=INADDR_ANY;
  memset(&(my_addr.sin_zero),'\0',8);
  
  if((connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in)))==-1)
  {
    perror("Connect: ");
    exit(1);
  }
  
  printf("Conectado\n");
  
  //Creamos una ventana de tamaño ALTOxANCHO
    cvNamedWindow("Ventana",  CV_WINDOW_NORMAL);
    cvResizeWindow("Ventana", ANCHO, ALTO);

    //Creamos una imagen de fondo que podamos modificar del mismo tamaño que la pantalla
    IplImage* imagenFondo = cvCreateImage(cvSize(ANCHO,ALTO), 8, 3);
  
  do
  {
    if(i!=-1)
      //Se genera la interfaz y se asigna la seleccion a la variable a
      a=interfaz1(imagenFondo,"Ventana");
    else a=1;

    if(a!=0)
    {
      a--;
      Menu1[a](&buff,imagenFondo,"Ventana",i);	//Llamo a funcion Ingresar o Registrarse
    }
    
    else
      buff.id=0;
		
    if((send(sockfd,&buff,sizeof(buff),0))==-1) //Envio datos de Usuario
    {
      perror("Send");
      exit(1);
    }
    if((recv(sockfd,&id,sizeof(int),0))==-1)	//Recivo id o -1 en caso de error
    {
      perror("Recv");
      exit(1);
    }
    i=id;
  
  }while(id<0);
	if(id==0)
		return 0;
  
	do
	{
	  a=menuPrincipal(imagenFondo,"Ventana",id);
	  if((send(sockfd,&a,sizeof(int),0))==-1)	//Envio seleccion
	  {
	    perror("Send");
	    exit(1);
	  }
  
	  switch(a)
	  {
	    case 1:
	      if((recv(sockfd,&cant,sizeof(int),0))==-1)	//Recivo id o -1 en caso de error
	      {
		perror("Recv");
		exit(1);
	      }
	      if(cant==0)
	      {
		printf("No hay Publicaciones\n");
		break;
	      }
	      for(i=1;i<=cant;i++)
	      {
		if((recv(sockfd,buffer,BUFFER,0))==-1)	//Recivo id o -1 en caso de error
		{
		  perror("Recv");
		  exit(1);
		}
		printf("%d)%s\n",i,buffer);
	      }
	      scanf("%d",&a);
	      if((send(sockfd,&a,sizeof(int),0))==-1)	//Envio seleccion
	      {
		perror("Send");
		exit(1);
	      }
	      if((recv(sockfd,&bufp,sizeof(post),0))==-1)	//Recivo Publicacion
	      {
		perror("Recv: ");
		exit(1);
	      }
	      printf("%s\n\n%s\n",bufp.titulo,bufp.contenido);	//Muestro
	      break;
	
	    case 2:
	      printf("Ingrese Titulo de Publicacion\n");
	      scanf("%s",bufp.titulo);
	      printf("Ingrese Cuerpo de Publicacion\n");
	      scanf("%s",bufp.contenido);
	      if((send(sockfd,&bufp,sizeof(post),0))==-1)	//Envio seleccion
	      {
		perror("Send");
		exit(1);
	      }
	      break;
	
	    case 3:
	      cant = cvListarPost(imagenFondo,"Ventana",sockfd);
	      if(cant==-1)
		break;
	      if((recv(sockfd,&cant,sizeof(int),0))==-1)
	      {
		perror("Recv");
		exit(1);
	      }
	      
	      cvZero(imagenFondo);
	      cvResultadoBorrarPub(imagenFondo,cant);
	      cvShowImage("Ventana",imagenFondo);
	      cvWaitKey(0);
	      break;
	
	    case 4:
	      cvBajaUsuario(imagenFondo,"Ventana",sockfd);
	      break;
	
	    case 5:
	      printf("Hasta Luego\n");
	      break;
	  }

	}while(a<4);
	
	close(sockfd);
	return 0;
}
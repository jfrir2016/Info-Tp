//	CLIENT

#include "Cliente.h"

int main(void)
{
  
  char buffer[BUFFER];
  int sockfd, pedido, accion, msglen;
  int a, id, cant, i=0;
  
  usu buff;
  post bufp;
  int (*Menu1[])(usu*)={Ingresar,Registro};
	
  struct  sockaddr_in server_addr;
  struct hostent *he;
  
   
  if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
  {
    perror("Socket: ");
    exit(1);
  }
  
  server_addr.sin_family= AF_INET;
  server_addr.sin_port= htons(PORT);
  server_addr.sin_addr.s_addr=*((struct in_addr *)he->h_addr);
  memset(&(server_addr.sin_zero),'\0',8);
  
  if((connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in)))==-1)
  {
    perror("Connect: ");
    exit(1);
  }
  
  do
  {
    printf("\t\tMenu de Inicio\n1)Ingresar\n2)Registrarse\n");
    scanf("%d",a);
    a--;
    Menu1[a](&buff);				//Llamo a funcion Ingresar o Registrarse

    if((send(sockfd,buff,sizeof(buff),0,))==-1) //Envio datos de Usuario
    {
      perror("Send: ");
      exit(1);
    }
    if((recv(sockfd,&id,sizeof(int),0,))==-1)	//Recivo id o -1 en caso de error
    {
      perror("Recv: ");
      exit(1);
    }
  }while(id<0);
  
  do
  {
    printf("\t\tMenu Principal\n1)Ver Publicaciones\n2)Crear Publicacion\n3)Borrar Publicacion\n4)Darse de Baja\n5)Salir");
    scanf("%d",&a);
  
    if((send(sockfd,&a,sizeof(int),0,))==-1)	//Envio seleccion
    {
      perror("Send: ");
      exit(1);
    }
  
    switch(a)
    {
      case 1:
	if((recv(sockfd,&cant,sizeof(int),0,))==-1)	//Recivo id o -1 en caso de error
	{
	  perror("Recv: ");
	  exit(1);
	}
	if(cant==0)
	  printf("No hay Publicaciones\n");
	for(i=1,i<=cant,i++)
	{
	  if((recv(sockfd,buffer,BUFFER,0,))==-1)	//Recivo id o -1 en caso de error
	  {
	    perror("Recv: ");
	    exit(1);
	  }
	  printf("%d)%s\n",i,buffer);
	}
	scanf("%d",&a);
	if((send(sockfd,&a,sizeof(int),0,))==-1)	//Envio seleccion
	{
	  perror("Send: ");
	  exit(1);
	}
	if((recv(sockfd,&bufp,sizeof(post),0,))==-1)	//Recivo Publicacion
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
	if((send(sockfd,&bufp,sizeof(post),0,))==-1)	//Envio seleccion
	{
	  perror("Send: ");
	  exit(1);
	}
	break;
	
      case 3:
	if((recv(sockfd,&cant,sizeof(int),0,))==-1)
	{
	  perror("Recv: ");
	  exit(1);
	}
	if(cant==0)
	  printf("No hay Publicaciones\n");
	
	for(i=1,i<=cant,i++)
	{
	  if((recv(sockfd,buffer,BUFFER,0,))==-1)	
	  {
	    perror("Recv: ");
	    exit(1);
	  }
	  printf("%d)%s\n",i,buffer);
	}
	scanf("%d",&a);
	if((send(sockfd,&a,sizeof(int),0,))==-1)	//Envio seleccion
	{
	  perror("Send: ");
	  exit(1);
	}
	if((recv(sockfd,&cant,sizeof(int),0,))==-1)
	{
	  perror("Recv: ");
	  exit(1);
	}
	if(cant==0)
	  printf("No es una publicacion propia\n");
	else
	  print("Publicacion borrada con exito\n");
	break;
	
      case 4:
	if((recv(sockfd,&cant,sizeof(int),0,))==-1)
	{
	  perror("Recv: ");
	  exit(1);
	}
	if(cant==1)
	{
	  printf("Se ha dado de baja\n");
	  break;
	}
	printf("No se pudo dar de baja\n");
	break;
	
      case 5:
	print("Hasta Luego\n");
	break;
    }
  }while(a<4);
  
  close(sockfd);
  
  return 0;
}
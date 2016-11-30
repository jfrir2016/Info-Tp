//	CLIENT

#include "TPO.h"

int main(void)
{
  
  char buffer[BUFFER];
  int sockfd, pedido, accion, msglen;
	int a;
	char* (*Menu1[])(NodeUser*)={Ingresar,Registro};
	
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
		menu[a](URoot);
	}while(id<0);
	
	
	
	
	
	
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  accion=0;//para que reciba la primera vez que entre
  
  while(1)
  {
    //Elegir recibir o escribir
    switch(accion)
    {
      case 0: //recibir
	if((msglen=recvfrom(sockfd,buffer,BUFFER,0,(struct sockaddr *) &server_addr, sizeof(struct sockaddr)))==-1)
	{
	  perror("Recvfrom: ");
	  exit(1);
	}
	
	buffer[msglen]='\0';
	printf("%s\n",buffer);
	//accion sirve para que el server diga si va a seguir escribiendo o si nececita recibir
	if((read(sockfd,&accion,sizeof(accion)))==-1)
	{
	  perror("Read: ")
	  exit(1);
	}
	
	break;
	
      case 1: //mandar texto
	
	scanf("%s",buffer);
	if((sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *) &server_addr,sizeof(struct sockaddr)))==-1)
	{
	  perror("Sendto: ");
	  exit(1);
	}
	
	if((read(sockfd,&accion,sizeof(accion)))==-1)
	{
	  perror("Read: ")
	  exit(1);
	}
	break;
	
      case 2: //mandar numero(pedido)
	
	scanf("%d",&pedido);
	if((write(sockfd,&pedido,sizeof(pedido)))==-1)
	{
	  perror("Write: ")
	  exit(1);
	}
	if((read(sockfd,&accion,sizeof(accion)))==-1)
	{
	  perror("Read: ")
	  exit(1);
	}
	break;
	
      case 3://salir
	
	close(sockfd);
	return 0;
	break;
    }
  }
}
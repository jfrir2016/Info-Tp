//	SERVER

#include "TPO.h"

int main (void)
{
  
  NodeUser *URoot=NULL;
	NodePost *PRoot=NULL;
	NodeComment *CRoot=NULL;
	
	int sockfd, accion, new_fd, size;
  char buffer[BUFFER];
  
	
	struct sockaddr_in server_addr;
  struct sockaddr_in client_addr;
  
  
  // Creo el socket y guardo su descriptor; exit si hubo error
  if((sockfd= socket(AF_INET, SOCK_STREAM, 0))==-1)
  {
      perror("Socket: ");
      exit(1);
  }
  
  //ingreso y cargo con bind la info del server
  server_addr.sin_family= AF_INET;
  server_addr.sin_port= PORT;
  server_addr.sin_addr.s_addr= INADDR_ANY;
  memset(&(server_addr.sin_zero),'\0',8);
  
	
	
  if((bind(sockfd,(struct sock_addr *)&server_addr, sizeof(struct sock_addr)))==-1)
  {
    perror("Bind: ");
    exit(1);
  }
  
	if(LoadUsuarios (&URoot,FUSU))					//Levanto todas las listas
		printf("Error Cargar Listas\n");
	if(LoadPubli (&PRoot,FPUB))
		printf("Error Cargar Listas\n");
	if(LoadComments (&PRoot))
		printf("Error Cargar Listas\n");
    
  if(listen(sockfd,MEMSET)==-1)
  {
    perror("Listen: ");
    exit(1);
  }
  
  if(signal(SIGCHLD, sigchld_handler) == SIG_ERR)
  {
    perror("signal");
    exit(1);
  }
    
  while(1)
  {
  
    size = sizeof(struct sockaddr_in);
      
    if((new_fd=accept(sockfd,&client_addr,&size))==-1)
    {
			perror("Accept");
			exit(1);
    }
    
    printf("Se recibio conexion de: %s", inet_ntoa(client_addr.sin_addr));
    
    if(!fork())
      {
				//proceso hijo
				close(sockfd);
				
				if((recv(sockfd,buff,strlen(buff),0,)))==-1)
					{
					perror("Sendto: ");
					exit(1);
					}
				
				
				
				
				
				
				
				
				
				strcpy(buffer,"Ingrese 0 para iniciar sesion y 1 para registrarse\n");
				if((sendto(new_fd,buffer,strlen(buffer),0,(struct sockaddr *) &client_addr,sizeof(struct sockaddr)))==-1)
				{
					perror("Sendto: ");
					exit(1);
				}
				accion=2;
				if((write(new_fd,&accion,sizeof(accion)))==-1)
				{
					perror("Write: ")
					exit(1);
				}
	
				if((read(new_fd,&accion,sizeof(accion)))==-1)
				{
					perror("Read: ")
					exit(1);
				}
	
				switch(accion)
				{
					case 0://iniciar sesion
					break;
					case 1://registrarse
					break;
				}
      }
      
		//proceso padre
    close(new_fd)
    
    }
    return 0;
}
//	SERVER

#include "TPO.h"

int main (void)
{
  
  int sockfd:
  int new_fd;
  int size;
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

	/*loguear o registrar
	 * si elije loguear comparo usr y pass
	 * si elige registrarse recibo usr y pass, comparo y agrego a la base
	 * legueo
	 */
	
      }
      
      //proceso padre
      close(new_fd)
    
    }
    return 0;
}
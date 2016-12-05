//	SERVER

#include "TPO.h"

int main (void)
{
  NodeUser *URoot=NULL;
  NodePost *PRoot=NULL;
  NodeComment *CRoot=NULL;
	
  int sockfd, accion, new_fd, size;
  int id, sel, i;
  int (*Menu[])(int,NodePost,int,NodeUser)={Posteo,AgregarPost,BorrarPost,...,...};
  
  USU *buff;
	
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
	//Proceso hijo
	close(sockfd);
	buff=(USU*)malloc(sizeof(USU));
	do
	{
	  if((recv(sockfd,buff,sizeof(USU),0,))==-1)	//recive seleccio de Menu de Inicio
	  {
	    perror("Recv: ");
	    exit(1);
	  }
	  if(buff->id==1)
	    id=Check(&buff,URoot);			//Logueo
	  else
	    id=AgregarNodoUsuario(buff,URoot);		//Registro
	
	  //BuscarNombreDeId
	
	  if((send(sockfd,&id,sizeof(int),0,))==-1)	//Envia respuesta
	  {
	    perror("Send: ");
	    exit(1);
	  }
	}while(id<0); //Bucle
	
	if((recv(sockfd,&sel,sizeof(int),0,))==-1)			//Recivo id o -1 en caso de error
	{
	  perror("Recv: ");
	  exit(1);
	}
	
	sel--;
	Menu[a](sockfd,PRoot,id,URoot);
	
	  // case 1: Posteo (Falta considerar comentar y demas)
	  // case 2: AgregarPost
	  // case 3: BorrarPost
	  // case 4: BajaUsu
	    
	    
	    
	    
	      
	    
	
	
	
	
      
    }			//proceso padre
    close(new_fd)
    
  }
  return 0;
}
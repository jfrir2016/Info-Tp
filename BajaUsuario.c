#include "TPO.h"

int BajaUsu (int id, NodeUser *URoot)
{
  if(!(a=BorrarNodoUsuario(id,URoot)))
  {
    if((send(sockfd,&a,sizeof(int),0))==-1)	//Envia 1 por correcto
    {
      perror("Send: ");
      exit(1);
    }
  }
  else
  {
    if((send(sockfd,&a,sizeof(int),0))==-1)	//Envia 0 por error
    {
      perror("Send: ");
      exit(1);
    }
  }
  return 0;
}
    
      
  
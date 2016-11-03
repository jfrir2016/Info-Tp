#include "TPO.h"

int main (void)
{
  Roots *Inicios;
  USU *aux;				
  int a;
  
  /*if(LoadUsuarios(&Primero,FUSU2))	//Cargado
    perror("ERROR: ");*/

  do					//Registro
  {
    Registro(Inicios));
    scanf("%d",&a);
  }while(a!=1);
  
  /*aux=(USU*)malloc(sizeof(USU));
  printf("\t\t\tBienvenido\nIngrese nombre de Usuario: ");
  scanf("%s \n",aux->Usuario);
  printf("Ingrese Contraseña: ");
  scanf("%s \n",aux->Contra);
  Check(&aux,Primero);*/
  
  	
  /*if(GuardarUsuarios(Primero,FUSU))	//Guardado
    perror("ERROR: ");*/
  
  
  //aux=Primero;
  /*while(aux->nxt!=NULL)		//Print
  {
    printf("%s\t%d\t%s\t%s\t%s\n",aux->Nombre,aux->Edad,aux->email,aux->Usuario,aux->Contra);
    aux=aux->nxt;
  }*/
  
  
  return 0;
}
#include "TPO.h"

int Ingresar (NodeUser *)
{
	USU *Name;
	int id;
	
	Name=(USU*)malloc(sizeof(USU));
	printf("Ingrese Nombre de Usuario: ");
	scanf("%s",Name->Usuario);
	printf("Ingrese Contraseña: ");
	scanf("%s",Name->Contra);
	id=Check(&Name,URoot)
	if(id==-1)
		return -1;
	return id;
}
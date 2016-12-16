void leerCampodeTexto(char* nombreVentana, IplImage* imagenFondo)
{
	char texto[20];
	int i = 0;
	for (i=0; i<20; i++) { texto[i]=(char)0; } //inicializo
	CvSize text_size;
	int baseline;
	int puntero_lector = 0;
	char aux = cvWaitKey(0); //Completar campos
	
	CvFont Font;
	cvInitFont(&Font,CV_FONT_HERSHEY_SIMPLEX, 0.7, 0.8, 0, 2,8);
	
	// Definimos desde donde y hasta donde va a ir el texto
	int textoDesdeDonde_X = ANCHO *0.6+10;
	int rectanguloDesdeDonde_Y = ALTO *0.25+10;
	int textoHastaDonde_X = textoDesdeDonde_X + REC_TAM_X;
	int textoHastaDonde_Y = rectanguloDesdeDonde_Y + REC_TAM_Y - 8;

	while (aux != 27) //llenar campo User, usa la misma logica que writemsj
	{
		printf("Leimos: %c\n", aux);
		printf("Nuestro texto va quedando como: %s\n", texto);
		fflush(stdout);
		//Aca vamos a entrar si escribio una letra
		if (aux > 31 && aux < 127)
		{

			//cvGetTextSize(texto, &Font, &text_size, &baseline);     //Tamaño que va a ocupar el texto
			if (strlen(texto)<20)
			{
				texto[puntero_lector]=aux;
				cvPutText(imagenFondo,texto,cvPoint(textoDesdeDonde_X,textoHastaDonde_Y), &Font, cvScalar (255,255,255,0));
				cvShowImage(nombreVentana,imagenFondo);
				puntero_lector++;
			}
		}

		//Aca vamos a entrar si quiere borrar algo
		if ((aux==8 || aux==127) && puntero_lector)
		{
			cvPutText(imagenFondo,texto,cvPoint(textoDesdeDonde_X,textoHastaDonde_Y), &Font, cvScalar (0,0,0,0));
			texto[puntero_lector]=(char)0;
			puntero_lector--;
			texto[puntero_lector]=(char)0;
			cvPutText(imagenFondo,texto,cvPoint(textoDesdeDonde_X,textoHastaDonde_Y), &Font, cvScalar (255,255,255,0));
			cvShowImage(nombreVentana,imagenFondo);
		}
		aux = cvWaitKey(0);
	}
}
CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lpthread -lopencv_core -lopencv_highgui -lopencv_imgproc
OBJS = Server_thread.o AgregarPost.o BajaUsuario.o BorrarPub.o BuscoPub.o Check.o Guardar.o GuardarComents.o GuardarPub.o LevantarCom.o LevantarLista.o LevantarPubli.o ListarPost.o listas_agregarnodopub.o listas_agregarnodousuario.o listas_borrarpub.o listas_borrarusuario.o listas_borrarcomentario.o sigchld_handler.o sig_finish.o
OBJTS = cliente.o Ingresar.o registrarse.o menuInicio.o interfaz1.o

All : CliExe SerExe Del

CliExe : $(OBJTS)
	$(CC) $(OBJTS) -o $@ $(LDFLAGS)
%.o : %.c %.h
	$(CC) $(CFLAGS) $< -o $@

SerExe : $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
%.o : %.c %.h
	$(CC) $(CFLAGS) $< -o $@
Del :
	rm -f ./*.o
#colors
red=		"\033[0;31m"
green=		"\033[0;32m"
yellow=		"\033[0;33m"
blue=		"\033[0;34m"
magenta=	"\033[0;35m"
cyan=		"\033[0;36m"
white=		"\033[0;37m"
reset=		"\033[0m"


#include the local libs folder
CC = gcc
INC = -Ilibs/
LIB = libs/*/src/*.c

BASE_PATH = Sesiones

all: Lugares

Lugares: Lugares.o
	@echo -e $(yellow) "Terminando... " $(reset)
	mv *.cfg /bin
	$(CC) *.o -o bin/LugaresTuristicos
	@echo -e $(green) "Listo" $(reset)

Lugares.o:
	@echo -e $(yellow) "Compilando: " $(reset) "Lugares.c"
	$(CC) -Wall -c $(INC) $(LIB) "$(BASE_PATH)/Lugares Turisticos/LugaresTuristicos.c"

#Clean up
.PHONY: all 
clean:
	@echo -e $(green) "Limpiando..." $(reset)
	rm -rf *.o
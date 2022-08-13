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
INC = -Ilibs/
LIB = -Llibs/project/*.c

BASE_PATH = Sesiones

Lugares: Lugares.o
	@echo -e $(yellow) "Terminando... " $(reset)
	gcc bin/LugaresTuristicos.o -o bin/LugaresTuristicos
	@echo -e $(green) "Listo" $(reset)

Lugares.o:
	@echo -e $(yellow) "Compilando: " $(reset) "Lugares.c"
	gcc -Wall $(INC) $(LIB) "$(BASE_PATH)/Lugares Turisticos/LugaresTuristicos.c" -o bin/LugaresTuristicos.o

hello:
	@echo -e $(yellow) "hello world" $(reset)

#Clean up
.PHONY: clean
clean:
	@echo -e $(green) "Limpiando..." $(reset)
	cd bin
	rm -rf *.o
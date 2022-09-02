#include "../trabajador.h"

Trabajador* newTrabajador(){
    Trabajador* worker = malloc(sizeof(Trabajador));
    worker->id = -1;
    worker->name = newString();
    worker->birthDate = newDate();
    return worker;
}
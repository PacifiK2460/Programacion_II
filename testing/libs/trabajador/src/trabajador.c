#include "../trabajador.h"

Trabajador* newTrabajador(){
    Trabajador* worker = calloc(sizeof(Trabajador));
    worker->id = -1;
    worker->name = newString();
    worker->birthDate = newDate();
    return worker;
}
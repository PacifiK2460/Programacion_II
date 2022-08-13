#ifndef TRABAJADOR_H
    #define TRABAJADOR_H

    #include "../string/string.h"

    typedef struct Date{
        int day;
        int month;
        int year;
    } Date;

    typedef struct Trabajador{
        int id;
        String name;
        Date birthDate;
    } Trabajador;


    Trabajador* newTrabajador();
    Date newDate();
#endif
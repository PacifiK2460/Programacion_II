#include <stdio.h>
#include "libs/project/trabajador.h"

int main(){
    //define and get one worker info
    Trabajador worker;

    // Worker initialization
    {
        int id;
        String name;
        Date birthDate;

        // Get worker info
        // TODO add info validation and error handling
        printf("Enter worker born day: ");
        evaluarInt(&birthDate.day);

        printf("Enter worker born month: ");
        evaluarInt(&birthDate.month);

        printf("Enter worker born year: ");
        evaluarInt(&birthDate.year);

        printf("Enter worker ID: ");
        evaluarInt(&id);

        printf("Enter worker name: ");
        evaluarString(&name);

        worker.id = id;|
        worker.name = name;
        worker.birthDate = birthDate;
    }
}
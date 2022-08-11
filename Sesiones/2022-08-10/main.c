#include <stdio.h>
#include "libs/project/trabajador.h"

#define input(str, ...)    \
    while (1)              \
    {                      \
        printf("%s", str); \
        if (__VA_ARGS__)   \
            break;         \
    }

int main()
{
    // define and get one worker info
    Trabajador worker;

    // Worker initialization
    {
        int id;
        String name;
        Date birthDate;

        // Get worker info
        input("Enter worker id: ", evaluarInt(&birthDate.day));
        input("Enter worker born day: ", evaluarInt(&birthDate.day));
        input("Enter worker born month: ", evaluarInt(&birthDate.month));
        input("Enter worker born year: ", evaluarInt(&birthDate.year));
        input("Enter worker ID: ", evaluarInt(&id));
        input("Enter worker name: ", evaluarString(&name));

        worker.id = id;
        worker.name = name;
        worker.birthDate = birthDate;
    }
}
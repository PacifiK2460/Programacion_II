#include <stdio.h>
#include "../libs/IO/IO.h"
#include "../libs/graph/graph.h"
#include "../libs/project/trabajador/trabajador.h"

#define input(str, condition)    \
    while (1)              \
    {                      \
        printf("%s", str); \
        if (condition) break;   \
    }

int main(){
    Graph trabajadores;

    // Worker initialization
    {
        // define and get one worker info
        Trabajador* worker = newTrabajador();

        // Get worker info
        input("Enter worker born day: ", evaluarInt(worker->birthDate.day));
        input("Enter worker born month: ", evaluarInt(worker->birthDate.month));
        input("Enter worker born year: ", evaluarInt(worker->birthDate.year));
        input("Enter worker ID: ", evaluarInt(worker->id));
        input("Enter worker name: ", evaluarString(worker->name.str));

        // Add worker to graph
        graph_add_leaf(&trabajadores, worker);
    }
}}
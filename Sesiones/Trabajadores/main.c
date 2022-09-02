#include <stdio.h>
#include "../libs/io/IO.h"
#include "../libs/graph/graph.h"
#include "../libs/project/trabajador/trabajador.h"

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
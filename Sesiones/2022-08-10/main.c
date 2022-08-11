#include <stdio.h>
#include "../libs/project/trabajador/trabajador.h"
#include "../libs/graph/graph.h"

#define input(str, condition, ...)    \
    while (1)              \
    {                      \
        printf("%s", str); \
        if (condition){__VA_ARGS__, break;}   \
    }

int main(){
    Graph trabajadores = new_graph();

    // Worker initialization
    {
        // define and get one worker info
        Trabajador* worker = newTrabajador();

        // Get worker info
        input("Enter worker born day: ", evaluarInt(worker->bnirday.day));
        input("Enter worker born month: ", evaluarInt(worker->bnirday.month));s
        input("Enter worker born year: ", evaluarInt(worker->bnirday.year));
        input("Enter worker ID: ", evaluarInt(worker->id));
        input("Enter worker name: ", evaluarString(worker->name.str));

        // Add worker to graph
        graph_add_leaf(&trabajadores, worker);
    }
}
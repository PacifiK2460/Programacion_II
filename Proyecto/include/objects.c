#include "objects.h"

int addProducto(PProducto producto){
    if(producto == NULL)
        return 0;
    return !addNode(&Productos.productos, producto);
}

int serializeProductos(){
    // Abrir el archivo
    FILE* file = fopen("productos.dat", "w+");
    if(file == NULL)
        return 0;

    // Escribir el numero de productos
    fprintf(file, "%d\n", Productos.productos.size);

    // Escribir los productos
    for(int i = 0; i < Productos.productos.size; i++){
        PProducto producto = (PProducto)getNode(&Productos.productos, i);
        fprintf(file, "%d ", producto->id);
        fprintf(file, "%d ", producto->tipo);
        fprintf(file, "%s ", producto->nombre);
        fprintf(file, "%f\n", producto->precio);
    }

    fclose(file);
    return 1;
}

int deserealizeProductos(){
    // Abrir el archivo
    FILE* file = fopen("productos.dat", "r+");
    if(file == NULL)
        return 0;

    // Leer el numero de productos
    int size;
    fscanf(file, "%d\n", &size);

    // Leer los productos
    for(int i = 0; i < size; i++){
        PProducto producto = (PProducto)malloc(sizeof(Producto));
        fscanf(file, "%d ", &producto->id);
        fscanf(file, "%d ", &producto->tipo);
        fscanf(file, "%s ", producto->nombre);
        fscanf(file, "%f\n", &producto->precio);
        addNode(&Productos.productos, producto);
    }

    fclose(file);
    return 1;
}

void CrearListaDeProductos(){
    Productos.serialize = serializeProductos;
    Productos.deserialize = deserealizeProductos;
    Productos.addProducto = addProducto;
}

int addPersonal(PPersonal personal){
    if(personal == NULL)
        return 0;
    return !addNode(&Personal.personal, personal);
}

int serializePersonal(){
    // Abrir el archivo
    FILE* file = fopen("personal.dat", "w+");
    if(file == NULL)
        return 0;

    // Escribir el numero de personal
    fprintf(file, "%d\n", Personal.personal.size);

    // Escribir el personal
    for(int i = 0; i < Personal.personal.size; i++){
        PPersonal personal = (PPersonal)getNode(&Personal.personal, i);
        fprintf(file, "%d ", personal->id);
        fprintf(file, "%d ", personal->cargo);
        fprintf(file, "%s ", personal->nombre);
        switch(personal->cargo){
            case COCINERO:
                // Queda pendiente enlazar el listado de los pedidos atendidos
                fprintf(file, "%d ", personal->cocinero.tiempo_cocinando[0]);
                fprintf(file, "%d ", personal->cocinero.tiempo_cocinando[1]);
                fprintf(file, "%d\n", personal->cocinero.tiempo_restante);
                break;
            case VENDEDOR:
                // Queda pendiente enlazar el listado de los pedidos atendidos
                break;
        }
    }

    fclose(file);
    return 1;
}

int deserealizePersonal(){
    // Abrir el archivo
    FILE* file = fopen("personal.dat", "r+");
    if(file == NULL)
        return 0;

    // Leer el numero de personal
    int size;
    fscanf(file, "%d\n", &size);

    // Leer el personal
    for(int i = 0; i < size; i++){
        PPersonal personal = (PPersonal)malloc(sizeof(Personal));
        fscanf(file, "%d ", &personal->id);
        fscanf(file, "%d ", &personal->cargo);
        fscanf(file, "%s ", personal->nombre);
        switch(personal->cargo){
            case COCINERO:
                // Queda pendiente enlazar el listado de los pedidos atendidos
                fscanf(file, "%d ", &personal->cocinero.tiempo_cocinando[0]);
                fscanf(file, "%d ", &personal->cocinero.tiempo_cocinando[1]);
                fscanf(file, "%d\n", &personal->cocinero.tiempo_restante);
                break;
            case VENDEDOR:
                // Queda pendiente enlazar el listado de los pedidos atendidos
                break;
        }
        if(addNode(&Personal.personal, personal))
            return 1;
    }

    fclose(file);
    return 1;
}

void CrearListaDePersonal(){
    Personal.serialize = serializePersonal;
    Personal.deserialize = deserealizePersonal;

    Personal.addPersonal = addPersonal;
}

int serializePedidos(){
    // Abrir el archivo
    FILE* file = fopen("pedidos.dat", "w+");
    if(file == NULL)
        return 0;

    // Escribir el numero de pedidos
    fprintf(file, "%d\n", Pedidos.pedidos.size);

    // Escribir los pedidos
    for(int i = 0; i < Pedidos.pedidos.size; i++){
        PPedido pedido = (PPedido)getNode(&Pedidos.pedidos, i);
        fprintf(file, "%d ", pedido->id);
        fprintf(file, "%d ", pedido->fecha.dia);
        fprintf(file, "%d ", pedido->fecha.mes);
        fprintf(file, "%d ", pedido->fecha.anio);
        fprintf(file, "%d ", pedido->vendedor->id);
        fprintf(file, "%d ", pedido->cocinero->id);
        fprintf(file, "%d ", pedido->productos.size);
        for(int j = 0; j < pedido->productos.size; j++){
            PEncargo encargo = (PEncargo)getNode(&pedido->productos, j);
            fprintf(file, "%d ", encargo->producto->id);
            fprintf(file, "%d ", encargo->cantidad);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return 1;
}

int deserealizePedidos(){
    // Abrir el archivo
    FILE* file = fopen("pedidos.dat", "r+");
    if(file == NULL)
        return 0;

    // Leer el numero de pedidos
    int size;
    fscanf(file, "%d\n", &size);

    // Leer los pedidos
    for(int i = 0; i < size; i++){
        PPedido pedido = (PPedido)malloc(sizeof(Pedido));
        fscanf(file, "%d ", &pedido->id);
        fscanf(file, "%d ", &pedido->fecha.dia);
        fscanf(file, "%d ", &pedido->fecha.mes);
        fscanf(file, "%d ", &pedido->fecha.anio);

        // We need to link the vendedor and cocinero
        fscanf(file, "%d ", &pedido->vendedor);
        fscanf(file, "%d ", &pedido->cocinero);

        int sizeProductos;
        fscanf(file, "%d ", &sizeProductos);

        for(int j = 0; j < sizeProductos; j++){
            PEncargo encargo = (PEncargo)malloc(sizeof(Encargo));
            // We need to link the producto
            fscanf(file, "%d ", &encargo->producto);
            fscanf(file, "%d ", &encargo->cantidad);
            addNode(&pedido->productos, encargo);
        }
        if(addNode(&Pedidos.pedidos, pedido))
            return 1;
    }

    fclose(file);
    return 1;
}

void CrearListaDePedidos(){
    Pedidos.serialize = serializePedidos;
    Pedidos.deserialize = deserealizePedidos    ;
}
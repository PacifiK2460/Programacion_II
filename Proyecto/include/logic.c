#include "logic.h"

void splashScreen()
{
    printf(CLEAR_SCREEN);
    printf(CURSOR_HIDE);
    // Get console size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    print_in_the_middle("🍔", height / 2 - 2);

    printf(BRIGHT_WHITE);
    print_in_the_middle("Hamburguesas Don Chuy©", height / 2 - 1);
    printf(RESET);

    printf(DIM);
    print_in_the_middle("By: Martinez Lara & Zavala Valdez", height / 2);
    printf(RESET);

    printf(DIM ITALIC);
    print_in_the_middle("Presiona cualquier tecla para continuar...", height);
    printf(RESET);

    holdScreen();

    printf(CURSOR_SHOW);
    printf(CLEAR_SCREEN);
}

PPersonal loginScreen()
{
    do
    {
        printf(CLEAR_SCREEN);
        printf(CURSOR_HIDE);

        // Print bottom and top bars
        {
            // Get console size
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

            CURSOR_GOTO(0, 0);
            for (int i = 0; i < width; i++)
            {
                BG_RGB(240, 190, 1);
                printf(" " RESET);
            }

            CURSOR_GOTO(0, height);
            for (int i = 0; i < width; i++)
            {
                BG_RGB(240, 190, 1);
                printf(" " RESET);
            }
        }

        char *username = input("Ingresa tu nombre de usuario: ", BUFFER_SIZE);

        printf(CLEAR_SCREEN);
        printf(CURSOR_HIDE);

        // Print bottom and top bars
        {
            // Get console size
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

            CURSOR_GOTO(0, 0);
            for (int i = 0; i < width; i++)
            {
                BG_RGB(240, 190, 1);
                printf(" " RESET);
            }

            CURSOR_GOTO(0, height);
            for (int i = 0; i < width; i++)
            {
                BG_RGB(240, 190, 1);
                printf(" " RESET);
            }
        }

        char *password = input("Ingresa tu contraseña: ", BUFFER_SIZE);
        PPersonal user = Personal.login(username, password);

        printf(CLEAR_SCREEN);
        if (user != NULL)
        {
            return user;
        }

    } while (1);
}

void cargarPrecios()
{
    // En este menu el administrador podra cargar los precios de los productos

    // Primero con un menu seleccionara el tipo de producto: hamburguesa o Papas
    // Despues con la funcion input se le pedira el nombre del producto
    // Despues con la funcion input se le pedira el precio del producto

    // Se debe validar que el precio sea un numero y que no sea negativo

    // Se debe validar que el nombre del producto no este vacio

    // Se debe validar que el nombre del producto no este repetido

    PMenu tipoDeProducto = createMenu("Tipo de producto", "Escoge alguna opción ✅", 2,
                                      "🍔 Hamburguesa",
                                      "🍟 Papas");

    printf(CLEAR_SCREEN);
    printf(CURSOR_HIDE);
    showMenu(tipoDeProducto);

    if (tipoDeProducto->selectedOption == -1)
        return;

    char *nombre;
    { // Pedir nombre y validar
        do
        {
            nombre = input("Ingresa el nombre del producto: ", BUFFER_SIZE);
            if (strlen(nombre) == 0)
            {
                alertScreen("El nombre no puede estar vacio", ERR);
                free(nombre);
            }

            { // Buscamor por un nombre
                int contador = 0;
                for (PProducto producto = getNode(&Productos.productos, contador); producto != NULL; producto = getNode(&Productos.productos, ++contador))
                {
                    if (strcmp(producto->nombre, nombre) == 0)
                    {
                        alertScreen("El nombre del producto ya existe", ERR);
                        free(nombre);
                        break;
                    }
                }
            }

            // Si no se encontro el nombre, se sale del ciclo
            break;
        } while (1);
    }

    float precio;
    { // Pedir precio y validar
        do
        {
            char *_precio = input("Ingresa el precio del producto: ", BUFFER_SIZE);

            // Convertimos el valor obtenido a float
            if (sscanf(_precio, "%f", &precio) != 1)
            {
                alertScreen("El precio debe ser un numero", ERR);
                free(_precio);
                continue;
            }

            // Validamos que el precio no sea negativo
            if (precio <= 0)
            {
                alertScreen("El precio debe ser mayor a 0", ERR);
                free(_precio);
                continue;
            }

            // Si no se encontro el nombre, se sale del ciclo
            free(_precio);
            break;
        } while (1);
    }

    // Si todo sale bien, se agrega el producto a la lista de productos
    // Y se guarda en el archivo

    PProducto producto = (PProducto)malloc(sizeof(Producto));

    strcpy(producto->nombre, nombre);
    // El id del producto se genera automaticamente, es el indice en el que se encuentra en la lista
    producto->id = Productos.productos.size;
    producto->tipo = tipoDeProducto->selectedOption;
    producto->precio = precio;

    if (Productos.addProducto(producto))
        alertScreen("Producto agregado con exito", INFO);

    if (!Productos.serialize())
        alertScreen("No se pudo guardar el producto", WARNING);

    free(nombre);
}
void ModificarPrecios()
{
    // Enlistar con un menu todos los productos y sus precios, modificar solo el precio del producto seleccionado

    // Se debe validar que el precio sea un numero y que no sea negativo

    PMenu productos = createMenu("Productos", "Escoge alguna opción ✅", 0);
    { // Agregar productos al menu

        int contador = 0;
        for (PProducto producto = getNode(&Productos.productos, contador); producto != NULL; producto = getNode(&Productos.productos, ++contador))
        {
            char nombre[BUFFER_SIZE];
            sprintf(nombre, "%s - $%.2f", producto->nombre, producto->precio);
            addMenuOption(productos, nombre);
        }
    }

    printf(CLEAR_SCREEN);
    printf(CURSOR_HIDE);
    showMenu(productos);
    if (productos->selectedOption == -1)
        return;

    PProducto producto = getNode(&Productos.productos, productos->selectedOption);

    do
    {
        char *nuevoPrecio = input("Ingresa el nuevo precio del producto: ", BUFFER_SIZE);
        float precio;
        if (sscanf(nuevoPrecio, "%f", &precio) != 1)
        {
            alertScreen("El precio debe ser un numero", ERR);
            free(nuevoPrecio);
            return;
        }

        if (precio <= 0)
        {
            alertScreen("El precio debe ser mayor a 0", ERR);
            free(nuevoPrecio);
            return;
        }

        producto->precio = precio;

        alertScreen("Precio modificado con exito", INFO);
        break;
    } while (1);

    if (!Productos.serialize())
        alertScreen("No se pudo guardar el producto", WARNING);
}
void AgregarPersonal()
{
    // En este menu el administrador podra agregar personal

    // Primero con un menu seleccionara el tipo de personal: cocinero o mesero
    // Despues con la funcion input se le pedira el nombre del personal

    // Se debe validar que el nombre del personal no este vacio

    // Se debe validar que el nombre del personal no este repetido

    PMenu tipoDePersonal = createMenu("Tipo de personal", "Escoge alguna opción ✅", 2,
                                      "👨‍🍳 Cocinero",
                                      "👨‍🍳 Mesero");

    printf(CLEAR_SCREEN);
    printf(CURSOR_HIDE);
    showMenu(tipoDePersonal);
    if (tipoDePersonal->selectedOption == -1)
        return;

    PPersonal personal = (PPersonal)malloc(sizeof(Personal));

    char *nombre = 0;
    char *contrasena = 0;
    UserType tipo = USER;

    do
    {
        while (1)
        {
            nombre = input("Ingresa el nombre del personal: ", BUFFER_SIZE);
            if (strlen(nombre) == 0)
            {
                alertScreen("El nombre no puede estar vacio", ERR);
                free(nombre);
                continue;
            }

            { // Buscamor por un nombre
                int contador = 0;
                for (PPersonal personal = getNode(&Personal.personal, contador); personal != NULL; personal = getNode(&Personal.personal, ++contador))
                {
                    if (strcmp(personal->nombre, nombre) == 0)
                    {
                        alertScreen("El nombre del personal ya existe", ERR);
                        free(nombre);
                        break;
                    }
                }
            }

            break;
        }

        // Si se selecciono un mesero, leer la nueva contraseña
        if (tipoDePersonal->selectedOption == 1)
        {
            contrasena = input("Ingresa la contraseña del mesero: ", BUFFER_SIZE);

            // Pedir el tipo de usuario
            PMenu tipoDeUsuario = createMenu("Tipo de usuario", "Escoge alguna opción ✅", 2,
                                             "👨‍🍳 Administrador",
                                             "👨‍🍳 Usuario");

            printf(CLEAR_SCREEN);
            printf(CURSOR_HIDE);
            showMenu(tipoDeUsuario);
            if (tipoDeUsuario->selectedOption == -1)
                return;

            if (tipoDeUsuario->selectedOption == 0)
                tipo = ADMIN;
            else
                tipo = USER;
        };

        // Si se le selecciono un cocinero, leer el tiempo de preparacion de los productos
        if (tipoDePersonal->selectedOption == 0)
        {
            contrasena = "pswd";

            alertScreen("Los cocineros nunca iniciaran sesión, por lo tanto no requieren una contraseña", INFO);

            char *tiempo;
            int tiempoDePreparacionDeHamburguesas;
            int tiempoDePreparacionDePapas;
            while (1)
            {
                tiempo = input("Ingresa el tiempo de preparacion de las hamburguesas: ", BUFFER_SIZE);

                if (sscanf(tiempo, "%d", &tiempoDePreparacionDeHamburguesas) != 1)
                {
                    alertScreen("El tiempo de preparacion debe ser un numero", ERR);
                    free(tiempo);
                    continue;
                }

                if (tiempoDePreparacionDeHamburguesas <= 0)
                {
                    alertScreen("El tiempo de preparacion debe ser mayor a 0", ERR);
                    free(tiempo);
                    continue;
                }

                break;
            }

            while (1)
            {
                tiempo = input("Ingresa el tiempo de preparacion de las papas: ", BUFFER_SIZE);
                if (sscanf(tiempo, "%d", &tiempoDePreparacionDePapas) != 1)
                {
                    alertScreen("El tiempo de preparacion debe ser un numero", ERR);
                    free(tiempo);
                    continue;
                }

                if (tiempoDePreparacionDePapas <= 0)
                {
                    alertScreen("El tiempo de preparacion debe ser mayor a 0", ERR);
                    free(tiempo);
                    continue;
                }
                break;
            }

            // Si todo sale bien, se guarda el tiempo de preparacion

            personal->cocinero.tiempo_cocinando[HAMBURGUESAS] = tiempoDePreparacionDeHamburguesas;
            personal->cocinero.tiempo_cocinando[PAPAS] = tiempoDePreparacionDePapas;
        }

        // Si no se encontro el nombre, se sale del ciclo
        break;
    } while (1);

    // Si todo sale bien, se agrega el personal a la lista de personal
    // Y se guarda en el archivo
    strcpy(personal->nombre, nombre);
    strcpy(personal->password, contrasena);
    // El id del personal se genera automaticamente, es el indice en el que se encuentra en la lista
    personal->id = Personal.personal.size;
    personal->cargo = tipoDePersonal->selectedOption;
    personal->tipo = tipo;

    if (Personal.addUser(personal))
        alertScreen("Personal agregado con exito", INFO);

    if (!Personal.serialize())
        alertScreen("No se pudo guardar el personal", WARNING);

    free(nombre);
    free(contrasena);
}

void GenerarReportes()
{
    // Al generar los reportes de ventas, se tendra que iterar por cada pedido e ir sumando el total de cada pedido por dia
    // Para asi poder mostrar el total de ventas por dia

    // El metodo para mostrar esta informacion es mediante un menu, en el cual se mostrara el total de ventas por dia. No tomara en cuenta la entrada del usuario
    // El menu se mostrara en pantalla hasta que el usuario presione la tecla ESC

    PMenu registro = createMenu("Registro de ventas", "Presiona ESC para salir", 0);

    // Ahora se itera por cada pedido y se agrega esa información como una opcion del menu
    for (int i = 0; i < Pedidos.pedidos.size; i++)
    {
        // Se obtiene el pedido
        PPedido pedido = (PPedido)getNode(&Pedidos.pedidos, i);

        // Se obtiene la fecha del pedido
        char fecha[11];
        sprintf(fecha, "%02d/%02d/%02d", pedido->fecha.dia, pedido->fecha.mes, pedido->fecha.anio);

        // Se obtiene el total del pedido
        float total = 0;
        for (int j = 0; j < pedido->productos.size; j++)
        {
            PProducto producto = (PProducto)getNode(&pedido->productos, j);
            total += producto->precio;
        }

        // Se crea la opcion del menu
        char *opcion = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        sprintf(opcion, "%s - $%.2f", fecha, total);

        // Se agrega la opcion al menu
        if (!addMenuOption(registro, opcion))
        {
            alertScreen("No se pudo crear el menu", ERR);
            free(opcion);
            return;
        }
    }
}

void adminMenu(PPersonal user)
{
    PMenu menu = createMenu("Menu Principal 🍔", "Escoge alguna opción ✅", 4,
                            "🪙 Cargar Precios",
                            "✏️ Modificar Precios",
                            "🪪 Agregar Personal",
                            "📈 Generar Reportes");

    while (1)
    {
        printf(CLEAR_SCREEN);
        printf(CURSOR_HIDE);
        showMenu(menu);
        if (menu->selectedOption == -1)
            return;

        switch (menu->selectedOption)
        {
        case 0:
            cargarPrecios();
            break;
        case 1:
            ModificarPrecios();
            break;
        case 2:
            AgregarPersonal();
            break;
        case 3:
            GenerarReportes();
            break;
        default:
            break;
        }
    }
}

Fecha getCurrentDate()
{
    // Return the current date
    Fecha fecha;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fecha.dia = tm.tm_mday;
    fecha.mes = tm.tm_mon + 1;
    fecha.anio = tm.tm_year + 1900;

    return fecha;
}

void realizarPedido(PPersonal vendedor)
{
    // Se toma el pedido del usuario
    // El pedido se toma preguntando al usuario que quiere pedir, la cantidad y ya;
    // Esto se pide mediante un menu y un input;

    // El pedido se debe de guardar en la lista de pedidos, y se debe de guardar en el archivo
    // Ademas de que el pedido se asigna al cocinero que tenga menos pedidos

    // Se crea el pedido
    PPedido pedido = (PPedido)malloc(sizeof(Pedido));
    pedido->id = Pedidos.pedidos.size;
    pedido->fecha = getCurrentDate();

    // Agregar IDPtr del vendedor, asi como la del cocinero a la que se le asigno
    pedido->vendedor = vendedor;

    // Dejar al usuario pedir la cantidad de productos que quiera
    int continuar = 0;
    do
    {
        // Se crea el menu
        PMenu menu = createMenu("Selecciona tu producto", "Presiona ESC para salir", 0);

        // Se agregan las opciones al menu
        for (int i = 0; i < Productos.productos.size; i++)
        {
            PProducto producto = (PProducto)getNode(&Productos.productos, i);

            // Se crea la opcion del menu
            char *opcion = (char *)malloc(sizeof(char) * BUFFER_SIZE);
            sprintf(opcion, "%s - $%.2f", producto->nombre, producto->precio);

            // Se agrega la opcion al menu
            if (!addMenuOption(menu, opcion))
            {
                alertScreen("No se pudo crear el menu", ERR);
                free(opcion);
                return;
            }
        }

        // Se muestra el menu
        printf(CLEAR_SCREEN);
        printf(CURSOR_HIDE);
        showMenu(menu);
        if (menu->selectedOption == -1)
            return;

        // Se obtiene el producto seleccionado
        PEncargo encargo = (PEncargo)malloc(sizeof(Encargo));
        PProducto producto = (PProducto)getNode(&Productos.productos, menu->selectedOption);

        // Se pide la cantidad
        int cantidad = 0;
        while (1)
        {
            printf(CLEAR_SCREEN);
            printf(CURSOR_HIDE);
            char *_cantidad = input("Ingresa la cantidad que quieres pedir: ", BUFFER_SIZE);

            // Se verifica que la cantidad sea un numero
            sprintf(_cantidad, "%d", cantidad);
            if (cantidad <= 0)
            {
                alertScreen("La cantidad debe ser mayor a 0", ERR);
                free(_cantidad);
                continue;
            }

            break;
        }

        // Se agrega el producto al pedido
        if (!addNode(&pedido->productos, encargo))
        {
            alertScreen("No se pudo agregar el encargo al pedido", ERR);
            return;
        }

        encargo->cantidad = cantidad;
        encargo->producto = producto;

        // Se pregunta si se quiere pedir algo mas
        printf(CLEAR_SCREEN);
        printf(CURSOR_HIDE);
        PMenu _continuar = createMenu("¿Quieres pedir algo mas?", "Presiona ESC para salir", 2,
                                      "Si", NULL, NULL,
                                      "No", NULL, NULL);

        showMenu(_continuar);
        if (_continuar->selectedOption == -1 || _continuar->selectedOption == 1)
            continuar = 0;

        continuar = 1;
    } while (continuar);

    // Se agrega el pedido a la lista de pedidos
    if (!addNode(&Pedidos.pedidos, pedido))
    {
        alertScreen("No se pudo agregar el pedido a la lista", ERR);
        return;
    }

    // Se guarda el pedido en el archivo
    if (!Pedidos.serialize())
    {
        alertScreen("No se pudo guardar el pedido en el archivo", ERR);
        return;
    }
}
void verPedidos() {
    // Muestra cada pedido para seleccionarlo, una vez seleccionado se muestra la informacion del pedido

    // Se crea el menu
    PMenu menu = createMenu("Selecciona tu pedido a mostrar", "Presiona ESC para salir", 0);

    // Se agregan las opciones al menu
    for (int i = 0; i < Pedidos.pedidos.size; i++)
    {
        PPedido pedido = (PPedido)getNode(&Pedidos.pedidos, i);

        // Se crea la opcion del menu
        char *opcion = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        sprintf(opcion, "Pedido #%d", pedido->id);

        // Se agrega la opcion al menu
        if (!addMenuOption(menu, opcion))
        {
            alertScreen("No se pudo crear el menu", ERR);
            free(opcion);
            return;
        }
    }

    // Se muestra el menu
    printf(CLEAR_SCREEN);
    printf(CURSOR_HIDE);
    showMenu(menu);
    if (menu->selectedOption == -1)
        return;

    // Se obtiene el pedido seleccionado
    PPedido pedido = (PPedido)getNode(&Pedidos.pedidos, menu->selectedOption);

    // Se muestra la informacion del pedido
    printf(CLEAR_SCREEN);
    printf(CURSOR_HIDE);
    printf("Pedido #%d\n", pedido->id);
    printf("Fecha: %d/%d/%d\n", pedido->fecha.dia, pedido->fecha.mes, pedido->fecha.anio);
    printf("Vendedor: %s\n", pedido->vendedor->nombre);
    printf("Cocinero: %s\n", pedido->cocinero->nombre);

    float total = 0;
    int tiempoDePreparacion = 0;

    // Se muestra la lista de productos con su id, nombre, precio y cantidad
    printf("Productos:\n");
    for (int i = 0; i < pedido->productos.size; i++)
    {
        PEncargo encargo = (PEncargo)getNode(&pedido->productos, i);
        PProducto producto = encargo->producto;

        printf("  %d. %s - $%.2f - %d\n", i + 1, producto->nombre, producto->precio, encargo->cantidad);

        total += producto->precio * encargo->cantidad;
        tiempoDePreparacion += pedido->vendedor->cocinero.tiempo_cocinando[producto->tipo] * encargo->cantidad;
    }

    printf("Total: $%.2f\n", total);
    printf("Tiempo de preparacion: %d minutos\n", tiempoDePreparacion);

    holdScreen();
}
void verReportes()
{
    // Mostrar una lista por cada cocinero, y mostrar el id de cada pedido que ha preparado

    // Se crea el menu
    PMenu menu = createMenu("Selecciona el cocinero a mostrar", "Presiona ESC para salir", 0);

    // Se agregan las opciones al menu
    for (int i = 0; i < Personal.personal.size; i++)
    {
        PPersonal personal = (PPersonal)getNode(&Personal.personal, i);

        // Se verifica que el personal sea un cocinero
        if (personal->tipo != COCINERO)
            continue;

        // Se crea la opcion del menu
        char *opcion = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        sprintf(opcion, "%s", personal->nombre);

        // Se agrega la opcion al menu
        if (!addMenuOption(menu, opcion))
        {
            alertScreen("No se pudo crear el menu", ERR);
            free(opcion);
            return;
        }
    }

    // Se muestra el menu
    printf(CLEAR_SCREEN);
    printf(CURSOR_HIDE);
    showMenu(menu);
    if (menu->selectedOption == -1)
        return;

    // Se obtiene el cocinero seleccionado
    PPersonal cocinero = (PPersonal)getNode(&Personal.personal, menu->selectedOption);

    // Se muestra la informacion del cocinero
    printf(CLEAR_SCREEN);
    printf(CURSOR_HIDE);
    printf("Cocinero: %s\n", cocinero->nombre);

    // Se muestra la lista de pedidos que ha preparado
    printf("Pedidos:\n");
    for (int i = 0; i < Pedidos.pedidos.size; i++)
    {
        PPedido pedido = (PPedido)getNode(&Pedidos.pedidos, i);

        // Se verifica que el pedido haya sido preparado por el cocinero
        if (pedido->cocinero != cocinero)
            continue;

        printf("  %d. Pedido #%d\n", i + 1, pedido->id);
    }

    holdScreen();
}

void userMenu(PPersonal user)
{
    PMenu menu = createMenu("Menu Principal 🍔", "Escoge alguna opción ✅", 3,
                            "🛒 Realizar Pedido", NULL, NULL,
                            "📝 Ver Pedidos", NULL, NULL,
                            "📊 Ver Reportes", NULL, NULL);

    while (1)
    {
        printf(CLEAR_SCREEN);
        printf(CURSOR_HIDE);
        showMenu(menu);
        if (menu->selectedOption == -1)
            return;

        switch (menu->selectedOption)
        {
        case 0:
            realizarPedido();
            break;
        case 1:
            verPedidos();
            break;
        case 2:
            verReportes();
            break;
        default:
            break;
        }
    }
}

void loadDatabase()
{
    CrearListaDePersonal();
    if (!Personal.deserialize())
    {
        printf("No se pudo cargar la base de datos de personal\n");
        holdScreen();
        exit(1);
    }

    CrearListaDeProductos();
    if (!Productos.deserialize())
    {
        printf("No se pudo cargar la base de datos de productos\n");
        holdScreen();
        exit(1);
    }

    CrearListaDePedidos();
    if (!Pedidos.deserialize())
    {
        printf("No se pudo cargar la base de datos de pedidos\n");
        holdScreen();
        exit(1);
    }

    // Link missing data
    // First we go through all the pedidos and link the Cocinero and Vendedor
    {
        int contador = 0;
        for (PPedido pedido = getNode(&Pedidos.pedidos, 0); pedido != NULL; pedido = getNode(&Pedidos.pedidos, ++contador))
        {
            int idCocinero = pedido->cocineroID;
            int idVendedor = pedido->vendedorID;

            pedido->cocinero = NULL;
            pedido->vendedor = NULL;

            // Search for the cocinero
            {
                int contador = 0;
                for (PPersonal personal = getNode(&Personal.personal, 0); personal != NULL; personal = getNode(&Personal.personal, ++contador))
                {
                    if (personal->id == idCocinero)
                    {
                        pedido->cocinero = personal;
                        break;
                    }
                }

                if (pedido->cocinero == NULL)
                {
                    printf("No se pudo encontrar el cocinero con id %d\n, hay información corrupta", idCocinero);
                    holdScreen();
                    exit(1);
                }
            }

            // Search for the vendedor
            {
                int contador = 0;
                for (PPersonal personal = getNode(&Personal.personal, 0); personal != NULL; personal = getNode(&Personal.personal, ++contador))
                {
                    if (personal->id == idVendedor)
                    {
                        pedido->vendedor = personal;
                        break;
                    }
                }

                if (pedido->vendedor == NULL)
                {
                    printf("No se pudo encontrar el vendedor con id %d\n, hay información corrupta", idVendedor);
                    holdScreen();
                    exit(1);
                }
            }

            // Search for the producto
            {
                int contador = 0;
                for (PEncargo encargo = getNode(&pedido->productos, 0); encargo != NULL; encargo = getNode(&pedido->productos, ++contador))
                {
                    // Search for the Producto's Id in the list of products
                    int idProducto = encargo->productoID;
                    encargo->producto = NULL;

                    int _contador = 0;
                    for (PProducto producto = getNode(&Productos.productos, 0); producto != NULL; producto = getNode(&Productos.productos, ++_contador))
                    {
                        if (producto->id == idProducto)
                        {
                            encargo->producto = producto;
                            break;
                        }
                    }
                }
            }
        }
    }
}
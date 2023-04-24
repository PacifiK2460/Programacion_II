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

PUser loginScreen()
{
    PUser fixedAdmin = (PUser)malloc(sizeof(User));
    fixedAdmin->id = 0;
    strcpy(fixedAdmin->name, "admin");
    strcpy(fixedAdmin->password, "admin");
    fixedAdmin->type = ADMIN;

    Usuarios.addUser(fixedAdmin);

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
        PUser user = Usuarios.login(username, password);

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

    if(!Productos.serialize())
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

    if(!Productos.serialize())
        alertScreen("No se pudo guardar el producto", WARNING);
}
void AgregarPersonal() {
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

    char *nombre;
    do{
        nombre = input("Ingresa el nombre del personal: ", BUFFER_SIZE);
        if(strlen(nombre) == 0){
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

        // Si no se encontro el nombre, se sale del ciclo
        break;
    }while(1);

    // Si todo sale bien, se agrega el personal a la lista de personal
    // Y se guarda en el archivo

    PPersonal personal = (PPersonal)malloc(sizeof(Personal));

    strcpy(personal->nombre, nombre);
    // El id del personal se genera automaticamente, es el indice en el que se encuentra en la lista
    personal->id = Personal.personal.size;
    personal->cargo = tipoDePersonal->selectedOption;

    if (Personal.addPersonal(personal))
        alertScreen("Personal agregado con exito", INFO);
}
void GenerarReportes() {}

void adminMenu(PUser user)
{
    PMenu menu = createMenu("Menu Principal 🍔", "Escoge alguna opción ✅", 4,
                            "🪙 Cargar Precios",
                            "✏️ Modificar Precios",
                            "🪪 Agregar Personal",
                            "💻 Generar Reportes");

    while (1)
    {
        printf(CLEAR_SCREEN);
        printf(CURSOR_HIDE);
        showMenu(menu);

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

void realizarPedido() {}
void verPedidos() {}
void verReportes() {}

void userMenu(PUser user)
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
    CrearListaDeUsuarios();
    if (!Usuarios.deserialize())
    {
        printf("No se pudo cargar la base de datos de usuarios\n");
        holdScreen();
        exit(1);
    }

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
            int idCocinero = pedido->cocinero;
            int idVendedor = pedido->vendedor;

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
                    int idProducto = encargo->producto;
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
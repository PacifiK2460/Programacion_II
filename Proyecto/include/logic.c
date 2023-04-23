#include "logic.h"
#include "objects.h"

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
            // Cargar precios
            break;
        case 1:
            // ModificarPrecios();
            break;
        case 2:
            // Agregar personal
            break;
        case 3:
            // Generar reportes
            break;
        default:
            break;
        }
    }
}

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
            // Realizar pedido
            break;
        case 1:
            // Ver pedidos
            break;
        case 2:
            // Ver reportes
            break;
        default:
            break;
        }
    }
}

void loadDatabase()
{
    CrearListaDeUsuarios();
    if(!Usuarios.deserealize())
    {
        printf("No se pudo cargar la base de datos de usuarios\n");
        holdScreen();
        exit(1);
    }

    CrearListaDePersonal();
    if(!Personal.deserealize())
    {
        printf("No se pudo cargar la base de datos de personal\n");
        holdScreen();
        exit(1);
    }

    CrearListaDeProductos();
    if(!Productos.deserealize())
    {
        printf("No se pudo cargar la base de datos de productos\n");
        holdScreen();
        exit(1);
    }

    CrearListaDePedidos();
    if(!Pedidos.deserealize())
    {
        printf("No se pudo cargar la base de datos de pedidos\n");
        holdScreen();
        exit(1);
    }

    // Link pedidos with users, products and personal
    // First we go through all the pedidos and link the Cocinero and Vendedor
    {
        int contador = 0;
        for(PPedido pedido = getNode(&Pedidos.pedidos, 0); pedido != NULL; pedido = getNode(&Pedidos.pedidos, ++contador))
        {
            int idCocinero = pedido->cocinero;
            int idVendedor = pedido->vendedor;

            pedido->cocinero = NULL;
            pedido->vendedor = NULL;

            // Search for the cocinero
            {
                int contador = 0;
                for(PPersonal personal = getNode(&Personal.personal, 0); personal != NULL; personal = getNode(&Personal.personal, ++contador))
                {
                    if(personal->id == idCocinero)
                    {
                        pedido->cocinero = personal;
                        break;
                    }
                }

                if(pedido->cocinero == NULL)
                {
                    printf("No se pudo encontrar el cocinero con id %d\n, hay información corrupta", idCocinero);
                    holdScreen();
                    exit(1);
                }
            }

            // Search for the vendedor
            {
                int contador = 0;
                for(PPersonal personal = getNode(&Personal.personal, 0); personal != NULL; personal = getNode(&Personal.personal, ++contador))
                {
                    if(personal->id == idVendedor)
                    {
                        pedido->vendedor = personal;
                        break;
                    }
                }

                if(pedido->vendedor == NULL)
                {
                    printf("No se pudo encontrar el vendedor con id %d\n, hay información corrupta", idVendedor);
                    holdScreen();
                    exit(1);
                }
            }
        
            // Search for the producto
            {
                int contador = 0;
                for(PEncargo encargo = getNode(&pedido->productos,0); encargo != NULL; encargo = getNode(&pedido->productos, ++contador)){
                    // Search for the Producto's Id in the list of products
                    int idProducto = encargo->producto;
                    encargo->producto = NULL;

                    int _contador = 0;
                    for(PProducto producto = getNode(&Productos.productos, 0); producto != NULL; producto = getNode(&Productos.productos, ++_contador))
                    {
                        if(producto->id == idProducto)
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
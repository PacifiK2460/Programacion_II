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

    getc(stdin);
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

    addNode(&users, fixedAdmin);

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
        PUser user = login(username, password);

        printf(CLEAR_SCREEN);
        if (user != NULL)
        {
            return user;
        }

    } while (1);
}

void ModificarPrecios()
{
    {
        Product *hamburguesa = (Product *)malloc(sizeof(Product));
        strcpy(hamburguesa->name, "Hamburguesa");
        hamburguesa->price = 50;
        hamburguesa->id = 0;
        addNode(&pedidos, hamburguesa);

        Product *papas = (Product *)malloc(sizeof(Product));
        strcpy(papas->name, "Papas");
        papas->price = 30;
        papas->id = 1;
        addNode(&pedidos, papas);

        Product *refresco = (Product *)malloc(sizeof(Product));
        strcpy(refresco->name, "Refresco");
        refresco->price = 20;
        refresco->id = 2;
        addNode(&pedidos, refresco);
    }

    PMenu menu = createMenu("Modificar Precios", "Escoge alguna opción ✅", 3,
                            "🍔 Hamburguesa", NULL, NULL,
                            "🍟 Papas", NULL, NULL,
                            "🥤 Refresco", NULL, NULL);

    while (1)
    {
        printf(CLEAR_SCREEN);
        printf(CURSOR_HIDE);
        showMenu(menu);

        switch (menu->selectedOption)
        {
        case 0:
            // Hamburguesa
            break;
        case 1:
            // Papas
            break;
        case 2:
            // Refresco
            break;
        default:
            break;
        }
    }
}

void adminMenu(user)
{
    PMenu menu = createMenu("Menu Principal 🍔", "Escoge alguna opción ✅", 4,
                            "🪙 Cargar Precios", NULL, NULL,
                            "✏️ Modificar Precios", ModificarPrecios, NULL,
                            "🪪 Agregar Personal", NULL, NULL,
                            "💻 Generar Reportes", NULL, NULL);

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
            ModificarPrecios();
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
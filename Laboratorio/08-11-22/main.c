#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdarg.h>
#include <time.h>

#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include <string.h>
#include <sys/select.h>
#include <sys/time.h>

struct termios mode;

#define PRODUCTOS 5

// UI
#define NEW_SCREEN() printf("\e[?1049h")
#define CLOSE_SCREEN() printf("\e[?1049l")

#define VLINE "│"
#define HLINE "─"
#define TLLINE "╭"
#define TRLINE "╮"
#define BLLINE "╰"
#define BRLINE "╯"

#define MENUVLINE "▏"

#define RESET "\e[0m"
#define NONE ""

// Tipos
#define BOLD "\e[1m"
#define DIM "\e[2m"
#define ITALIC "\e[3m"
#define INVERSE "\e[7m"

// MISC
#define HIDE_CURSOR "\e[?25l"
#define SHOW_CURSOR "\e[?25h"
#define CLEAR "\e[2J"

#define STDOUTPUT NULL

// Posición del Cursor
void noEcho()
{
#ifdef _WIN32
    HANDLE console = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(console, &mode);
    SetConsoleMode(console, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
#endif

#ifdef __linux__
    tcgetattr(0, &mode);
    mode.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &mode);
#endif
}

void echo()
{
#ifdef _WIN32
    HANDLE console = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(console, &mode);
    SetConsoleMode(console, mode | (ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
#endif

#ifdef __linux__
    tcgetattr(0, &mode);
    mode.c_lflag |= (ICANON | ECHO);
    tcsetattr(0, TCSANOW, &mode);
#endif
}

void gotoxy(int x, int y)
{
    printf("\e[%d;%dH", y, x);
}

typedef struct _MENU
{
    int X;
    int Y;
    int ROWS;
    char **opciones;
    char **descripcion;
    int selected;
} MENU;

// Colores
#define STR(X) #X
#define BRGB(R, G, B) "\e[48;2;" STR(R) STR(;) STR(G) STR(;) STR(B) STR(m)
#define FRGB(R, G, B) "\e[38;2;" STR(R) STR(;) STR(G) STR(;) STR(B) STR(m)

typedef struct _producto
{
    int id;
    char nombre[20];
    char descripcion[50];
    float precio;
    int estrellas;
    struct _productos *siguiente;
    struct _productos *anterior;
} Producto;

typedef struct DLL
{
    Producto *root;
} DLL;

float total = 0;
int productost = 0;

Producto getProduct(int id, DLL *lista)
{
    Producto *temp = lista->root;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return *temp;
        }
        temp = (Producto *)temp->siguiente;
    }
}

Producto getProductoByIndex(int index, DLL *lista)
{
    Producto *temp = lista->root;
    int i = 0;
    while (temp != NULL)
    {
        if (i++ == index)
        {
            return *temp;
        }
        temp = (Producto *)temp->siguiente;
    }
}

void appendProduct(Producto *data, DLL *lista)
{
    Producto *temp = lista->root;
    if (temp == NULL)
    {
        lista->root = data;
        return;
    }
    while (temp->siguiente != NULL)
    {
        temp = (Producto *)temp->siguiente;
    }
    temp->siguiente = (struct _productos *)data;
    temp = (Producto *)temp->siguiente;
    temp->siguiente = NULL;
}

void updateMenu(MENU *menu, DLL *lista)
{
    printf(CLEAR);
    for (int i = 0, x = 0; i < menu->ROWS; i++)
    {
        printf("\e[%i;%iH"
               "%s"
               "%s "
               "%s" RESET,
               menu->X + i + x++, menu->Y,                            // Posicion
               menu->selected == i ? BOLD FRGB(185, 251, 192) : NONE, // Color
               menu->selected == i ? MENUVLINE : " ",                 // Caracter de seleccion
               menu->opciones[i]);
        printf("\e[%i;%iH"
               "%s"
               "%s "
               "%s" RESET,
               menu->X + i + x++, menu->Y,
               menu->selected == i ? DIM FRGB(185, 251, 192) : NONE,
               menu->selected == i ? MENUVLINE : " ",
               menu->descripcion[i]); // Cantidad de caracteres, texto
    }

    {
        // print the info of the selected product in the right side
        Producto p = getProduct(menu->selected + 1, lista);
        printf("\e[%i;%iH"
               "%s"
               "%s "
               "%s" RESET,
               menu->X, menu->Y + 20,
               BOLD FRGB(185, 251, 192),
               MENUVLINE,
               "Informacion del producto");

        printf("\e[%i;%iH"
               "%s"
               "%s "
               "%s" RESET,
               menu->X + 1, menu->Y + 20,
               BOLD FRGB(185, 251, 192),
               MENUVLINE,
               "Nombre: ");

        printf("\e[%i;%iH"
               "%s"
               "%s "
               "%s" RESET,
               menu->X + 2, menu->Y + 20,
               BOLD FRGB(185, 251, 192),
               MENUVLINE,
               "Descripcion: ");

        printf("\e[%i;%iH"
               "%s"
               "%s "
               "%s" RESET,
               menu->X + 3, menu->Y + 20,
               BOLD FRGB(185, 251, 192),
               MENUVLINE,
               "Precio: ");

        printf("\e[%i;%iH"
               "%s"
               "%s "
               "%s" RESET,
               menu->X + 4, menu->Y + 20,
               BOLD FRGB(185, 251, 192),
               MENUVLINE,
               "Estrellas: ");

        printf("\e[%i;%iH"
               "%s"
               "%s" RESET,
               menu->X + 1, menu->Y + 30,
               BOLD FRGB(185, 251, 192),
               p.nombre);

        printf("\e[%i;%iH"
               "%s"
               "%s" RESET,
               menu->X + 2, menu->Y + 30,
               BOLD FRGB(185, 251, 192),
               p.descripcion);

        printf("\e[%i;%iH"
               "%s"
               "%f" RESET,
               menu->X + 3, menu->Y + 30,
               BOLD FRGB(185, 251, 192),
               p.precio);

        printf("\e[%i;%iH"
               "%s"
               "%i" RESET,
               menu->X + 4, menu->Y + 30,
               BOLD FRGB(185, 251, 192),
               p.estrellas);
    }

    {
        // print the current total at the bottom of the screen
        printf("\e[%i;%iH"
               "%s"
               "%s "
               "%s" RESET,
               menu->X + 10, menu->Y + 20,
               BOLD FRGB(185, 251, 192),
               MENUVLINE,
               "Total: ");

        printf("\e[%i;%iH"
               "%s"
               "%.2f" RESET,
               menu->X + 10, menu->Y + 30,
               BOLD FRGB(185, 251, 192),
               total);

        printf("\e[%i;%iH"
               "%s"
               "%i" RESET,
               menu->X + 10, menu->Y + 40,
               BOLD FRGB(185, 251, 192),
               productost);
    }
}

void focusMenu(MENU *menu, DLL *lista)
{
    updateMenu(menu, lista);
    // Leemos el teclado non-canonical mode

    while (1)
    {
        updateMenu(menu, lista);
        // echo();
        char c = 0;
        noEcho();
        if ((c = getchar()) == '\033')
        {              // ESC
            getchar(); // Omitimos el 2do [
            switch ((c = getchar()))
            {
            case 'A':
                if (menu->selected != 0)
                    menu->selected -= 1;
                break;

            case 'B':
                if (menu->selected != menu->ROWS - 1)
                    menu->selected += 1;
                break;
            case 'D':
                menu->selected = -1;
                echo();
                {
                    printf(CLEAR);

                    // print the current total at the bottom of the screen
                    float t = total * 0.10;
                    printf("\e[%i;%iH"
                           "%s"
                           "%s(%i): %.2f + %.2f = %.2f" RESET,
                           menu->X + 10, menu->Y + 20,
                           BOLD FRGB(185, 251, 192),
                           "Total: ", productost, total,t,total+t );

                    getchar();
                    return;
                }
                break;
            }
            // En caso de update, actualizamos visualmente el manu
            echo();
            updateMenu(menu, lista);
        }
        else if (c == 10)
        {
            updateMenu(menu, lista);
            echo();
            {
                total += getProduct(menu->selected + 1, lista).precio;
                productost++;
            }
        }
    }
    updateMenu(menu, lista);
    echo();
    // Regresamos index seleccionado
}

int main()
{
    DLL lista;
    {
        Producto productos[] = {
            {1, "Producto 1", "Descripcion 1", 10.0, 5},
            {2, "Producto 2", "Descripcion 2", 20.0, 4},
            {3, "Producto 3", "Descripcion 3", 30.0, 3},
            {4, "Producto 4", "Descripcion 4", 40.0, 2},
            {5, "Producto 5", "Descripcion 5", 50.0, 1}};

        for (int i = 0; i < PRODUCTOS; i++)
            appendProduct(&productos[i], &lista);
    }

    {
        // Inicializamos la consola
        setlocale(LC_ALL, "");
        NEW_SCREEN();
        printf(CLEAR);
        printf(HIDE_CURSOR);
    }

    {
        MENU listado;
        listado.X = 1;
        listado.Y = 1;
        listado.ROWS = PRODUCTOS;

        listado.opciones = malloc(sizeof(char *) * PRODUCTOS);
        listado.descripcion = malloc(sizeof(char *) * PRODUCTOS);

        for (int i = 0; i < PRODUCTOS; i++)
        {
            listado.opciones[i] = getProductoByIndex(i, &lista).nombre;
            listado.descripcion[i] = getProductoByIndex(i, &lista).descripcion;
        }

        listado.selected = 0;

        focusMenu(&listado, &lista);
    }

    CLOSE_SCREEN();
}
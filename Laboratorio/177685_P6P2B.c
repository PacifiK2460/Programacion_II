#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#include "../include/colors.h"
#include "../include/string.h"
#include "../include/menu.h"

int rangedrand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

typedef struct Datap
{
    int longitud;
    int vocales[5];
    wchar_t *palabra_ordenada;
} Datap;

void leerPalabras(wchar_t **ptrPal, int nPal)
{
    int i;
    for (i = 0; i < nPal; i++)
    {
        /*
            Leemos la palabra bajo un buffer temporal
        */
        wchar_t temp[1000];
        wprintf(L"Ingresa la palabra " BOLD "%d/%d: " RESET, i + 1, nPal);
        wscanf(L"%ls", temp);

        /*
            Obtenemos el tamaño de la palabra y reservamos memoria
            para la palabra en el arreglo de punteros
        */
        int len = wcslen(temp);
        ptrPal[i] = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));
        wcscpy(ptrPal[i], temp);
    }
}

void ordenarPalabra(wchar_t *palabra)
{
    /*
        Ordenamos la palabra usando el algoritmo de burbuja
    */
    int len = wcslen(palabra);
    int i, j;
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (palabra[i] > palabra[j])
            {
                wchar_t temp = palabra[i];
                palabra[i] = palabra[j];
                palabra[j] = temp;
            }
        }
    }
}

void analizarPalabras(wchar_t **ptrPal, Datap *ptrDatap, int nPal)
{
    int i;
    for (i = 0; i < nPal; i++)
    {
        // Obtenemos la longitud de la palabra
        ptrDatap[i].longitud = wcslen(ptrPal[i]);

        // Inicializamos el arreglo de vocales
        ptrDatap->vocales[0] = 0;
        ptrDatap->vocales[1] = 0;
        ptrDatap->vocales[2] = 0;
        ptrDatap->vocales[3] = 0;
        ptrDatap->vocales[4] = 0;

        // Obtenemos la palabra ordenada y la ordenamos
        ptrDatap[i].palabra_ordenada = (wchar_t *)calloc((ptrDatap[i].longitud + 1), sizeof(wchar_t));
        wcscpy(ptrDatap[i].palabra_ordenada, ptrPal[i]);
        ordenarPalabra(ptrDatap[i].palabra_ordenada);

        // Contamos las vocales
        int j;
        for (j = 0; j < ptrDatap[i].longitud; j++)
        {
            if (ptrPal[i][j] == L'a' || ptrPal[i][j] == L'A')
            {
                ptrDatap[i].vocales[0]++;
            }
            else if (ptrPal[i][j] == L'e' || ptrPal[i][j] == L'E')
            {
                ptrDatap[i].vocales[1]++;
            }
            else if (ptrPal[i][j] == L'i' || ptrPal[i][j] == L'I')
            {
                ptrDatap[i].vocales[2]++;
            }
            else if (ptrPal[i][j] == L'o' || ptrPal[i][j] == L'O')
            {
                ptrDatap[i].vocales[3]++;
            }
            else if (ptrPal[i][j] == L'u' || ptrPal[i][j] == L'U')
            {
                ptrDatap[i].vocales[4]++;
            }
        }
    }
}

void generaFig(int size)
{
    wprintf(BOLD L"Como la palabra es par: una figura por que si\n");
    int squareSize = size, margin = 0, mid = size/2;

    // Mientras podamos dibujar un cuadrado, lo hacemos
    while (squareSize > 0)
    {
        int i, j;
        // Imprimimos filas
        for (i = 0; i < squareSize; i++)
        {
            // Imprimimos espacios
            for (j = 0; j < margin; j++)
            {
                wprintf(L"   ");
            }

            // Imprimimos asteriscos
            for (j = 0; j < squareSize; j++)
            {
                // En caso de ser las esquinas o el centro, imprimimos un espacio
                if ((i == 0 && j == 0) || (i == 0 && j == squareSize - 1) ||
                    (i == squareSize - 1 && j == 0) || (i == squareSize - 1 && j == squareSize - 1) ||
                    (i == mid && j == mid))
                {
                    wprintf(L"   ");
                }
                else
                {
                    // En caso contrario, imprimimos un asterisco
                    wprintf(L" * ");
                }
            }
            if (squareSize > 1)
                wprintf(L"\n");
        }

        // Reducimos el tamaño del cuadrado y aumentamos el margen, asi como la mitad
        squareSize -= 2;
        mid--;
        margin++;
    }
    wprintf(L"*");
    wprintf(L"\n" RESET);
}

void imprimirAnalisis(wchar_t **ptrPal, Datap *ptrDatap, int nPal)
{
    wprintf(L"Número de Palabras: " BOLD "%d\n" RESET, nPal);
    { // Imprimimos cada palabra en la lista
        int i;
        for (i = 0; i < nPal; i++)
        {
            wprintf(L"%d: " BOLD L"%ls\n" RESET, i + 1, ptrPal[i]);
        }
    }

    wprintf(L"\n");

    {
        /*
            Hacemos conteo de la longitud maxima de todas las palabras en la tabla,
            esto para poder imprimir el primer borde de la tabla
        */
        int maxLongitud = 0;
        {
            /*
                Debido a que las palabras van a ser de un tamaño arbitrario,
                debemos de encontrar la palabra mas larga para poder imprimir
                la tabla alieada
            */
            int i;
            for (i = 0; i < nPal; i++)
            {
                if (ptrDatap[i].longitud > maxLongitud)
                {
                    maxLongitud = ptrDatap[i].longitud;
                }
            }

            /*
                Si nuestra palabra mas larga es menor al tamaño del encabezado
                de la tabla, entonces debemos de aumentar el tamaño de la palabra
            */
            if (maxLongitud < 6)
            {
                maxLongitud = 7;
            }
        }

        // Numero de caracteres del borde de la tabla
        int tableBorder = (maxLongitud + 1) + (15) + (7) + maxLongitud + 1;
        // Palabra + vocales + tamaño + palabra ordenada

        int i;
        for (i = 0; i < nPal; i++)
        {
            wprintf(CLEAR_SCREEN);
            wprintf(BOLD L"ANÁLISIS DE PALABRAS\n" RESET);
            // Encabezado de la tabla
            wprintf(L"%-*ls  a  e  i  o  u TAMAÑO PALABRA ORDENADA\n", maxLongitud, L"PALABRA");
            int j;
            for (j = 0; j < tableBorder; j++)
            {
                wprintf(L"─");
            }
            wprintf(L"\n");

            wprintf(
                L"%-*ls "
                L"% 2d % 2d % 2d % 2d % 2d "
                L"% 7d "
                L"%ls\n",
                maxLongitud, ptrPal[i],
                ptrDatap[i].vocales[0],
                ptrDatap[i].vocales[1],
                ptrDatap[i].vocales[2],
                ptrDatap[i].vocales[3],
                ptrDatap[i].vocales[4],
                ptrDatap[i].longitud,
                ptrDatap[i].palabra_ordenada);

            // Al ser impar, imprimimos la fuigura correspondiente
            if (ptrDatap[i].longitud % 2)
            {
                generaFig(ptrDatap[i].longitud);
            }

            // Esperamos a que el usuario presione una tecla para continuar
            wprintf(DIM L"Presione cualquier tecla para continuar...");
            getwchar();
        }
    }
}

int main()
{
    // Inicializamos la semilla del generador de numeros aleatorios
    // y configuramos el locale para que acepte caracteres unicode (a.k.a la ñ)
    setlocale(LC_ALL, "");
    srand(time(NULL));
    wprintf(BOLD L"Martinez Lara Santiago de la cruz" RESET L" | " BOLD L"177685\n" RESET);

    wchar_t **ptrPal = 0;
    Datap *ptrDatap = 0;
    int nPal = rangedrand(3, 6);
    ptrPal = (wchar_t **)calloc(nPal, sizeof(wchar_t *));
    ptrDatap = (Datap *)calloc(nPal, sizeof(Datap));

    leerPalabras(ptrPal, nPal);
    analizarPalabras(ptrPal, ptrDatap, nPal);
    imprimirAnalisis(ptrPal, ptrDatap, nPal);
}
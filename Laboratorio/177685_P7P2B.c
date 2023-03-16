#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUMERO_DEL_USUARIO 4
#define NUMERO_DE_LANZAMIENTOS 4

#define BOLD "\033[1m"
#define DIM "\033[2m"
#define RESET "\033[0m"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"

typedef struct User
{
    char *name;
    char *uuid;
    int numeros[NUMERO_DEL_USUARIO];
    int ganadas;
    int numeros_acertados[NUMERO_DE_LANZAMIENTOS];
} User;

char *generateUUID()
{
    char *uuid = (char *)calloc(37, sizeof(char));

    int i;
    for (i = 0; i < 36; i++)
    {
        if (i == 8 || i == 13 || i == 18 || i == 23)
        {
            uuid[i] = '-';
        }
        else if (i == 14)
        {
            uuid[i] = '4';
        }
        else
        {
            uuid[i] = rand() % 16;
            if (i == 19)
            {
                uuid[i] = (uuid[i] & 0x3) | 0x8;
            }
            uuid[i] = uuid[i] < 10 ? uuid[i] + '0' : uuid[i] + 'A' - 10;
        }
    }
    uuid[36] = '\0';
    return uuid;
}

typedef struct node
{
    User *data;
    struct node *next;
} node;

typedef struct Llist
{
    node *head;
    node *tail;
    int size;
} Llist;

int append(Llist *list, User *data)
{
    // Añadir a la lista de acuerdo a la los juegos ganados
    node *tmp = list->head;
    if (tmp == NULL)
    {
        list->head = (node *)calloc(1, sizeof(node));
        list->head->data = data;
        list->head->next = NULL;
        list->tail = list->head;
        list->size++;
        return 1;
    }

    node *prev = NULL;
    while (tmp != NULL)
    {
        if (tmp->data->ganadas < data->ganadas)
        {
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = tmp;
    list->size++;
}

int rangedRand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int checkForDuplicateName(Llist *list, char *name)
{
    node *current = list->head;
    while (current != NULL)
    {
        if (strncmp(current->data->name, name, 1000) == 0)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

char *inputName(Llist *list)
{
    do
    {
        printf("Ingresa el nombre de Usuario: " BOLD);
        char buffer[1000];
        int res = fgets(buffer, sizeof(buffer), stdin);

        printf(RESET);

        if (res)
        {
            if (checkForDuplicateName(list, buffer))
                continue;
            else
            {
                char *dest = (char *)calloc(strlen(buffer) + 1, sizeof(char));
                strncpy(dest, buffer, strlen(buffer) - 1);
                return dest;
            }
        }
        else
        {
            printf(RED BOLD "Error al leer el nombre de usuario.\n" RESET);
            exit(EXIT_FAILURE);
        }
    } while (1);
}

int inputNumber()
{
    char buffer[1000];
    int res = fgets(buffer, sizeof(buffer), stdin);

    printf(RESET);

    if (res)
    {
        int num = atoi(buffer);
        return num;
    }
    else
    {
        printf(RED BOLD "Error al leer el nombre de usuario.\n" RESET);
        exit(EXIT_FAILURE);
    }
}

int numberExists(int *arr, int size, int num)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == num)
            return 1;
    }
    return 0;
}

int createUser(Llist *list)
{
    User *newUser = (User *)calloc(1, sizeof(User));
    newUser->name = inputName(list);
    newUser->uuid = generateUUID();

    {
        int i;
        for (i = 0; i < NUMERO_DEL_USUARIO; i++)
        {
            printf("Ingresa el numero %d: " BOLD, i + 1);
            int tmp = inputNumber();
            printf(RESET);
            if (tmp < 2 || tmp > 12)
            {
                printf(RED "Ingresa un numero entre 2 y 12" RESET "\n");
                i--;
            }

            newUser->numeros[i] = tmp;
        }
    }

    {
        int i;
        for (i = 0; i < NUMERO_DE_LANZAMIENTOS - 1; i++)
        {
            int *tmpN = newUser->numeros_acertados;
            int tmp;
            do
            {
                tmp = rangedRand(1, 12);
                if (numberExists(newUser->numeros_acertados, NUMERO_DEL_USUARIO, tmp))
                    printf(YELLOW "El numero " BOLD "%d" RESET YELLOW " ya fue generado, se generara otro" RESET "\n", tmp);
                else
                    break;
            } while (1);

            if (numberExists(newUser->numeros, NUMERO_DEL_USUARIO, tmp))
            {
                printf(GREEN "El numero " BOLD "%d" RESET GREEN " fue generado y es correcto" RESET "\n", tmp);
                *tmpN++ = tmp;
                newUser->ganadas++;
            }
        }
    }

    printf(BOLD "RECUENTO:\n" RESET);
    printf("Usuario: " BOLD "%s" RESET DIM " (%s)\n" RESET, newUser->name, newUser->uuid);
    printf("Numeros insertados: " BOLD "%d " RESET, NUMERO_DEL_USUARIO);
    {
        int i;
        printf(DIM "[ " RESET);
        for (i = 0; i < NUMERO_DEL_USUARIO; i++)
        {
            printf("%d ", newUser->numeros[i]);
        }
        printf(DIM "]" RESET "\n");
    }
    printf("Numeros acertados: " BOLD "%d " RESET, newUser->ganadas);
    {
        int i;
        printf(DIM "[ " RESET);
        for (i = 0; i < NUMERO_DEL_USUARIO; i++)
        {
            printf("%d ", newUser->numeros_acertados[i]);
        }
        printf(DIM "]" RESET "\n");
    }

    if (append(list, newUser) != 1)
    {
        printf(RED "Error al agregar el usuario a la lista" RESET);
        exit(EXIT_FAILURE);
    }

    printf(DIM "Presione <ENTER> para continuar..." RESET);
    getchar();
    return 1;
}

int main()
{
    srand(time(NULL));

    Llist *list = (Llist *)calloc(1, sizeof(Llist));

    do
    {
        if (createUser(list) != 1)
        {
            printf(RED "Error al crear el usuario" RESET);
            exit(EXIT_FAILURE);
        }

        printf("Desea crear otro usuario? s = <ENTER>, n = <CTRL-C>\n");
        getchar();
    } while (1);

    printf(BOLD "Usuarios: " RESET);
    int i;
    node *current = list->head;
    for (i = 0; i < list->size; i++)
    {
        User *newUser = current->data;
        printf("\tUsuario: " BOLD "%s" RESET "DIM (%s)\n" RESET, newUser->name, newUser->uuid);
        printf("\tNumeros insertados: " BOLD "%d " RESET, NUMERO_DEL_USUARIO);
        {
            int i;
            printf(DIM "\t[ " RESET);
            for (i = 0; i < NUMERO_DEL_USUARIO; i++)
            {
                printf("%d ", newUser->numeros[i]);
            }
            printf(DIM "]" RESET "\n");
        }
        printf("\tNumeros acertados: " BOLD "%d " RESET, newUser->ganadas);
        {
            int i;
            printf(DIM "\t[ " RESET);
            for (i = 0; i < NUMERO_DEL_USUARIO; i++)
            {
                printf("%d ", newUser->numeros[i]);
            }
            printf(DIM "]" RESET "\n");
        }
        current = current->next;
    }
    getchar();
}
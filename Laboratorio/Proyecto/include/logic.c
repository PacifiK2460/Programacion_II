#include "logic.h"

int loginScreen()
{
    char *username = input("Ingrese su nombre de usuario: ", BUFFER_SIZE);
    char *password = input("Ingrese su contraseña: ", BUFFER_SIZE);

    PUser user = Usuarios.login(username, password);
    if (user == NULL)
    {
        alertScreen("Usuario o contraseña incorrectos", ERR);
        return 0;
    }

    alertScreen("Bienvenido", INFO);

    // Run "juego.exe" and the return value will be the score
    int score = system("juego.exe");

    user->puntos += score;
    if (!Usuarios.serealizar())
    {
        alertScreen("Error al guardar los datos", ERR);
        return 0;
    }
}
int registerScreen()
{
    // Register a new user, checking if the username is already taken
    char *username = NULL, *password = NULL;

    do
    {
        username = input("Ingrese su nombre de usuario: ", BUFFER_SIZE);

        int i = 0;
        for (PUser user = (PUser)getNode(&Usuarios.usuarios, i); user != NULL; i++)
        {
            if (strcmp(user->username, username) == 0)
            {
                alertScreen("El nombre de usuario ya existe", ERR);
                free(username);
                username = NULL;
                break;
            }
        }
    } while (username != NULL);

    password = input("Ingrese su contraseña: ", BUFFER_SIZE);

    PUser user = (PUser)malloc(sizeof(User));
    strcpy(user->username, username);
    strcpy(user->password, password);

    if (addNode(&Usuarios.usuarios, user) == 0)
    {
        alertScreen("Error al guardar los datos", ERR);
        return 0;
    }

    if (!Usuarios.serealizar())
    {
        alertScreen("Error al guardar los datos", ERR);
        return 0;
    }

    alertScreen("Usuario registrado con éxito", INFO);

    return loginScreen();
}

void listScores(){
    // Con un menu, mostrar los usuarios ordenados y su puntaje

    Menu puntajes = {
        .title = "Puntajes",
        .description = "Seleccione un usuario para ver su puntaje",
        .selectedOption = 0
    };

    for(int i = 0; i < Usuarios.usuarios.size; i++){
        PUser user = (PUser)getNode(&Usuarios.usuarios, i);
        char *option = (char*)malloc(sizeof(char) * (strlen(user->username) + 20));
        strcpy(option, user->username);
        if(addOption(&puntajes, option) == 0){
            alertScreen("Error al crear el menu", ERR);
            return;
        }
    }

    showMenu(&puntajes);
}

int showScoresScreen()
{
    // Imprimir los usuarios ordenados por puntaje de mayor a menor
    // Imprimir los usuarios ordenados por puntaje de manor a mayor
    // Buscar por nombre de usuario

    // Le preguntamos al usuario el tipo de orden por medio de un menu

    Menu orden = {
        .title = "Ordenar por",
        .description = "Seleccione el tipo de orden",
        .selectedOption = 0};

    {
        if (addOption(&orden, "Puntaje de mayor a menor") == 0)
        {
            alertScreen("Error al crear el menu", ERR);
            return 0;
        }

        if (addOption(&orden, "Puntaje de menor a mayor") == 0)
        {
            alertScreen("Error al crear el menu", ERR);
            return 0;
        }

        if (addOption(&orden, "Nombre de usuario") == 0)
        {
            alertScreen("Error al crear el menu", ERR);
            return 0;
        }

        if (addOption(&orden, "Salir") == 0)
        {
            alertScreen("Error al crear el menu", ERR);
            return 0;
        }
    }

    showMenu(&orden);

    switch (orden.selectedOption)
    {
    case 0:
        // Ordenar por puntaje de mayor a menor
        for (int i = 0; i < Usuarios.usuarios.size; i++)
        {
            for (int j = 0; j < Usuarios.usuarios.size - 1; j++)
            {
                PUser user1 = (PUser)getNode(&Usuarios.usuarios, j);
                PUser user2 = (PUser)getNode(&Usuarios.usuarios, j + 1);

                if (user1->puntos < user2->puntos)
                {
                    swapNodes(&Usuarios.usuarios, j, j + 1);
                }
            }
        }

        listScores();
        break;
    case 1:
        // Ordenar por puntaje de menor a mayor
        for (int i = 0; i < Usuarios.usuarios.size; i++)
        {
            for (int j = 0; j < Usuarios.usuarios.size - 1; j++)
            {
                PUser user1 = (PUser)getNode(&Usuarios.usuarios, j);
                PUser user2 = (PUser)getNode(&Usuarios.usuarios, j + 1);

                if (user1->puntos > user2->puntos)
                {
                    swapNodes(&Usuarios.usuarios, j, j + 1);
                }
            }
        }
        listScores();
        break;
    case 2:
        // Preguntamos el nombre de usuario a buscar
        {
            char *username = input("Ingrese el nombre de usuario a buscar: ", BUFFER_SIZE);

            // Buscamos el usuario
            int i = 0;
            for (PUser user = (PUser)getNode(&Usuarios.usuarios, i); user != NULL; i++)
            {
                if (strcmp(user->username, username) == 0)
                {
                    // Imprimimos el usuario
                    printf(CLEAR_SCREEN);
                    char username[BUFFER_SIZE];
                    strcpy(username, user->username);

                    char points[BUFFER_SIZE];
                    sprintf(points, "%d", user->puntos);

                    // We get the size of the terminal to print the user in the center
                    CONSOLE_SCREEN_BUFFER_INFO csbi;
                    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
                    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

                    print_in_the_middle(username, height / 2 - 1);
                    print_in_the_middle(points, height / 2);

                    holdScreen();
                    break;
                }
            }
        }
        break;
    case 3:
        return 1;
    }
}
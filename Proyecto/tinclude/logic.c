#include "logic.h"

void splashScreen()
{
    // HANDLE hStdout;
    // hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    // // Read the file and print it to the console
    // wchar_t msgBuf[BUF_SIZE];
    // size_t cchStringSize;
    // DWORD dwChars;

    // FILE *fp;
    // fp = _wfopen(L"ascii-art.ans", L"r");
    // while (fgetws(msgBuf, 255, fp) != NULL)
    // {
    //     StringCchLengthW(msgBuf, BUF_SIZE, &cchStringSize);
    //     WriteConsole(hStdout, msgBuf, (DWORD)cchStringSize, &dwChars, NULL);
    // }
    // fclose(fp);

    return;
}

void MainMenu(InputHandler input, POutputSubsciption output)
{
    Menu menu = {
        .title = "Escoge una opción 🤔",
        .description = "Hamburguesas Don Chuy 🍔🍟",
        .output = output};

    addMenuOption(&menu, "Cargar precios 🤑", "Carga los precios de la base de datos 🆙", NULL);
    addMenuOption(&menu, "Modificar precios ✏️", "Modifica los precios de la base de datos 🍔", NULL);
    addMenuOption(&menu, "Agregar usuarios 🤠", "Agrega nuevos usuarios al sistema 💻", NULL);
    addMenuOption(&menu, "Generar reportes 📊", "Genera reportes de ventas 📈", NULL);
    addMenuOption(&menu, "Salir 🚪", "Salir del programa 🚪", NULL);

    showMenu(&menu);
}
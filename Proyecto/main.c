#include "../libs/proyecto/auth.h"
#include "../libs/proyecto/routes.h"

#include <stdio.h>
#include <wchar.h>
#include <locale.h>


int main() {
    setlocale(LC_CTYPE, "");
    wchar_t star[] = L"🔥";
    wprintf(L"%ls\n", star);

    Result result = loadAllUsers();

    switch (result.Error_state) {
        case OK:
            wprintf(L"OK\n");
            break;
        case MALLOC_FAULT:
            wprintf(L"MALLOC_FAULT\n");
            break;
        case FILE_NOT_FOUND:
            wprintf(L"FILE_NOT_FOUND\n");
            break;
        case FILE_PERMISSION_DENIED:
            wprintf(L"FILE_PERMISSION_DENIED\n");
            break;
        case FILE_OPEN_ERROR:
            wprintf(L"FILE_OPEN_ERROR\n");
            break;
        default:
            wprintf(L"UNKNOWN ERROR\n");
            break;
    }
}
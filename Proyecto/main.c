#include "../libs/proyecto/routes.h"
#include "../libs/proyecto/auth.h"

#include <stdio.h>
#include <wchar.h>
#include <locale.h>


int main() {
    setlocale(LC_CTYPE, "");

    Result usersLoad = loadAllUsers();
    Result routesLoad = loadAllRoutes();

    if(usersLoad.Error_state != OK){
        wprintf(L"📛 Error loading users (%d): ", usersLoad.Error_state);
        printf("%s\n", strerror_l(usersLoad.Error_state, LC_CTYPE));
        return 1;
    }
    if(routesLoad.Error_state != OK){
        wprintf(L"📛 Error loading routes (%d): ", usersLoad.Error_state);
        printf("%s\n", strerror_l(usersLoad.Error_state, LC_CTYPE));
        return 1;
    }
}
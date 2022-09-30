#include "../libs/proyecto/routes.h"
#include "../libs/proyecto/auth.h"

#include <stdio.h>
#include <wchar.h>
#include <locale.h>


int main() {
    setlocale(LC_CTYPE, "");

    {// Load routes and users
        Result usersLoad = loadAllUsers();
        Result routesLoad = loadAllRoutes();

        if(usersLoad.Error_state != OK){
            wprintf(L"📛 Error loading users (%d): ", usersLoad.Error_state);
            return 0;
        }
        if(routesLoad.Error_state != OK){
            wprintf(L"📛 Error loading routes (%d): ", usersLoad.Error_state);
            return 0;
        }
    }

    
}
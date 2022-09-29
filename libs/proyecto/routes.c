#include "routes.h"

#define ROUTES_FILE "routes.db"

LList* routes;

void freeRoutes(){
    while(LList_size(routes) > 0){
        Route* route = LList_remove_at(routes, 0);
        free(route->name);
        free(route->destination);
        free(route->scheduled_times);
        free(route);
    }
    free(routes);
}

void freeUserRoutes(const struct User* user){
    while(LList_size(user->queued_routes) > 0){
        Route* route = LList_remove_at(user->queued_routes, 0);
        free(route->name);
        free(route->destination);
        free(route->scheduled_times);
        free(route);
    }
}

Result loadAllRoutes(){
    Result result;
    
    routes = LList_new();
    if(routes == 0){
        result.Error_state = MALLOC_FAULT;
        return result;
    }

    FILE* file = fopen(ROUTES_FILE, "r");
    if (file == 0) {
        // check for errors produced by fopen
        if (errno == ENOENT) {
            // if the file was not found, create it
            file = fopen(ROUTES_FILE, "a+");
            if (file == 0) {
                if(errno == EACCES) {
                    result.Error_state = FILE_PERMISSION_DENIED;
                } else {
                    result.Error_state = FOPEN_FAULT;
                }
            } else {
                result.Error_state = OK;
            }
        } else if(errno == EACCES){
            result.Error_state = FILE_PERMISSION_DENIED;
        } else {
            result.Error_state = FILE_OPEN_ERROR;
        }
        
        // We were able to open the file, but there was an error.
        if(result.Error_state != OK){
            freeRoutes();
            return result;
        }
    }

    int number_of_routes = 0;
    if(fwscanf(file, L"%d", &number_of_routes) != 1){
        result.Error_state = FILE_READ_ERROR;
        freeRoutes();
        return result;
    }
    if(fwscanf(file, L"\n") != 0){
        result.Error_state = FILE_READ_ERROR;
        freeRoutes();
        return result;
    }

    for(int i = 0; i < number_of_routes; i++){
        Route* route = malloc(sizeof(Route));
        if(route == 0){
            result.Error_state = MALLOC_FAULT;
            freeRoutes();
            return result;
        }

        route->name = malloc(sizeof(wchar_t) * 100);
        if(route->name == 0){
            result.Error_state = MALLOC_FAULT;
            freeRoutes();
            return result;
        }
        if(fwscanf(file, L"%s", route->name) != 1){
            result.Error_state = FILE_READ_ERROR;
            freeRoutes();
            return result;
        }

        route->destination = malloc(sizeof(wchar_t) * 100);
        if(route->destination == 0){
            result.Error_state = MALLOC_FAULT;
            freeRoutes();
            return result;
        }
        if(fwscanf(file, L"%s", route->destination) != 1){
            result.Error_state = FILE_READ_ERROR;
            freeRoutes();
            return result;
        }

        int number_of_scheduled_times = 0;
        if(fwscanf(file, L"%d", &number_of_scheduled_times) != 1){
            result.Error_state = FILE_READ_ERROR;
            freeRoutes();
            return result;
        }

        route->scheduled_times = LList_new();
        for(int j = 0; j < number_of_scheduled_times; j++){
            Time* time = malloc(sizeof(Time));
            if(time == 0){
                result.Error_state = MALLOC_FAULT;
                freeRoutes();
                return result;
            }
            
            if(fwscanf(file, L"%02d:%02d", &time->day, &time->hour) != 2){
                result.Error_state = FILE_READ_ERROR;
                freeRoutes();
                return result;
            }
            LList_add(route->scheduled_times, time);
        }

        if(fwscanf(file, L"\n") != 0){
            result.Error_state = FILE_READ_ERROR;
            freeRoutes();
            return result;
        }

        LList_add(routes, route);
    }
}
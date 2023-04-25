#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "menu.h"
#include "objects.h"

#include "ansi.h"
#include "users.h"
#include "tui.h"
#include "list.h"

extern ListadoDePersonal Personal;
extern ListadoDeProductos Productos;
extern ListadoDePedidos Pedidos;

extern ListaDeUsuarios Usuarios;

void splashScreen();
PUser loginScreen();

void adminMenu(PUser user);
void userMenu(PUser user);

void loadDatabase();

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "menu.h"
#include "objects.h"

#include "ansi.h"
#include "tui.h"
#include "list.h"

extern ListadoDePersonal Personal;
extern ListadoDeProductos Productos;
extern ListadoDePedidos Pedidos;

void splashScreen();
PPersonal loginScreen();

void adminMenu(PPersonal user);
void userMenu(PPersonal user);

void loadDatabase();

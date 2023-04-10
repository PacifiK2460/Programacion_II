#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "ansi.h"
#include "users.h"
#include "tui.h"
#include "list.h"
#include "menu.h"
#include "products.h"

extern List users;
extern List pedidos;

void splashScreen();
PUser loginScreen();

void adminMenu(user);
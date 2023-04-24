#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "menu.h"

#include "ansi.h"
#include "users.h"
#include "tui.h"
#include "list.h"
#include "objects.h"

void splashScreen();
PUser loginScreen();

void adminMenu(PUser user);
void userMenu(PUser user);


void loadDatabase();

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#include "constants.h"
#include "list.h"
#include "tui.h"
#include "menu.h"
#include "objects.h"

extern ListadoDeUsuarios Usuarios;

int loginScreen();
int registerScreen();
int showScoresScreen();
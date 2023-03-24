#pragma once
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <stdbool.h>

#include "menu.h"
#include "IO.h"

#define BUF_SIZE 255

void splashScreen();

void MainMenu(InputHandler input, POutputSubsciption output);
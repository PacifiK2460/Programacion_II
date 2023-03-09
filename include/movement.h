#pragma once

// ANSI escape codes to move the cursor
#define MOVE_UP L"\033[1A"
#define MOVE_DOWN L"\033[1B"
#define MOVE_RIGHT L"\033[1C"
#define MOVE_LEFT L"\033[1D"

// ANSI escape codes to clear the screen
#define CLEAR_SCREEN L"\033[2J"

// ANSI escape codes to clear the line
#define CLEAR_LINE L"\033[2K"

// ANSI escape code to move to x,y 
#define MOVE_TO(x,y) L"\033[" #y L";" #x L"H"

#define HIDE_CURSOR L"\033[?25l"
#define SHOW_CURSOR L"\033[?25h"
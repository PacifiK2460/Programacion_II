#pragma once

// ANSI escape codes to move the cursor
#define MOVE_UP "\033[1A"
#define MOVE_DOWN "\033[1B"
#define MOVE_RIGHT "\033[1C"
#define MOVE_LEFT "\033[1D"

// ANSI escape codes to clear the screen
#define CLEAR_SCREEN "\033[2J"

// ANSI escape codes to clear the line
#define CLEAR_LINE "\033[2K"

// ANSI escape code to move to x,y 
#define MOVE_TO(x,y) "\033[" #y ";" #x "H"

#define HIDE_CURSOR "\033[?25"
#define SHOW_CURSOR "\033[?25h"
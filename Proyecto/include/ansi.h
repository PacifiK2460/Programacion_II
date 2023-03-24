#pragma once

#define BG_RGB(R,G,B) "\x1b[48;2;" #R ";" #G ";" #B "m"
#define FG_RGB(R,G,B) "\x1b[38;2;" #R ";" #G ";" #B "m"

#define CURSOR_UP(N) "\x1b[" #N "A"
#define CURSOR_DOWN(N) "\x1b[" #N "B"
#define CURSOR_FORWARD(N) "\x1b[" #N "C"
#define CURSOR_BACKWARD(N) "\x1b[" #N "D"

#define CURSOR_NEXT_LINE(N) "\x1b[" #N "E"
#define CURSOR_PREVIOUS_LINE(N) "\x1b[" #N "F"

#define CURSOR_GOTO(N,M) "\x1b[" #N ";" #M "H"

#define CURSOR_SAVE "\x1b[s"
#define CURSOR_RESTORE "\x1b[u"

#define CURSOR_HIDE "\x1b[?25l"
#define CURSOR_SHOW "\x1b[?25h"

#define CLEAR_SCREEN "\x1b[2J"
#define CLEAR_LINE "\x1b[2K"

#define RESET "\x1b[0m"

#define BOLD "\x1b[1m"
#define DIM "\x1b[2m"
#define UNDERLINE "\x1b[4m"
#define BLINK "\x1b[5m"
#define REVERSE "\x1b[7m"
#define HIDDEN "\x1b[8m"

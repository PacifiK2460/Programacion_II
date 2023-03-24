#include "IO.h"

POutputSubsciption subscribeOutput(POutputSubscribers outputSubscriber, void (*Render)(void* RenderArgs), void* RenderArgs){
    POutputSubsciption output = (POutputSubsciption)calloc(1,sizeof(OutputSubsciption));

    CONSOLE_SCREEN_BUFFER_INFO terminal_info;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &terminal_info);

    output->with = terminal_info.srWindow.Right - terminal_info.srWindow.Left + 1;
    output->height = terminal_info.srWindow.Bottom - terminal_info.srWindow.Top + 1;

    output->output = (char*)calloc(output->with * output->height, sizeof(char));

    output->Render = Render;
    output->RenderArgs = RenderArgs;

    addNode(&outputSubscriber->subscribers, output);

    return output;
}
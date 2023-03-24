#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <stdbool.h>

#include "include/logic.h"
#include "include/IO.h"
#include "include/menu.h"

#define MAX_THREADS 3
#define BUF_SIZE 255

void ErrorHandler(LPCTSTR lpszFunction);
DWORD WINAPI InitInput();
DWORD WINAPI InitOutput();
DWORD WINAPI InitLogic();

OutputSubscribers outputSubscriber;
InputHandler inputSubscription;

// https://learn.microsoft.com/en-us/windows/win32/procthread/creating-threads
int _tmain()
{
    // App Initialization
    { // Input / Output
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);

        HANDLE hStdout;

        // Make sure there is a console to receive input.
        hStdout = GetStdHandle(STD_INPUT_HANDLE);
        if (hStdout == INVALID_HANDLE_VALUE)
            return 1;

        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hStdout == INVALID_HANDLE_VALUE)
            return 1;

        return 0;
    }

    DWORD dwThreadIdArray[MAX_THREADS];
    HANDLE hThreadArray[MAX_THREADS];

    // Create the thread to begin execution on its own.
    hThreadArray[0] = CreateThread(
        NULL,                 // default security attributes
        0,                    // use default stack size
        InitInput,            // thread function name
        NULL,                 // argument to thread function
        0,                    // use default creation flags
        &dwThreadIdArray[0]); // returns the thread identifier

    hThreadArray[1] = CreateThread(
        NULL,                 // default security attributes
        0,                    // use default stack size
        InitOutput,           // thread function name
        NULL,                 // argument to thread function
        0,                    // use default creation flags
        &dwThreadIdArray[1]); // returns the thread identifier

    hThreadArray[2] = CreateThread(
        NULL,                 // default security attributes
        0,                    // use default stack size
        InitLogic,            // thread function name
        NULL,                 // argument to thread function
        0,                    // use default creation flags
        &dwThreadIdArray[2]); // returns the thread identifier

    // Wait until all threads have terminated.
    WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);

    // Close all thread handles and free memory allocations.
    for (int i = 0; i < MAX_THREADS; i++)
    {
        CloseHandle(hThreadArray[i]);
    }

    getchar();
    return 0;
}

DWORD WINAPI InitInput()
{
}

DWORD WINAPI InitOutput()
{
    int layers = 0;
    layers = outputSubscriber.subscribers.size;

    for(int i = 0; i < layers; i++){
        
    }

}

DWORD WINAPI InitLogic()
{
    // Program Start
    splashScreen();

    POutputSubsciption MenuOutput = subscribeOutput(&outputSubscriber);
    MainMenu(inputSubscription, MenuOutput);

    return 0;
}

void ErrorHandler(LPCTSTR lpszFunction)
{
    // Retrieve the system error message for the last-error code.

    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError();

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0, NULL);

    // Display the error message.

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
                                      (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
    StringCchPrintf((LPTSTR)lpDisplayBuf,
                    LocalSize(lpDisplayBuf) / sizeof(TCHAR),
                    TEXT("%s failed with error %d: %s"),
                    lpszFunction, dw, lpMsgBuf);
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

    // Free error-handling buffer allocations.

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}
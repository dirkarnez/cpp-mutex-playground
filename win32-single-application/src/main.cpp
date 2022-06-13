#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    LPCTSTR sz = L"my.mutex.name";

    // ensure only one running instance
    HANDLE hMutexHandle = CreateMutex(NULL, TRUE, sz);
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        std::cout << "ERROR_ALREADY_EXISTS" << std::endl;
        std::cin.get();
        return EXIT_FAILURE;
    }
    
    // rest of the program
    std::cout << "Hello world!" << std::endl;
    std::cin.get();
    
    ReleaseMutex(hMutexHandle);
    CloseHandle(hMutexHandle);

    return EXIT_SUCCESS;
}
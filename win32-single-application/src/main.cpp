#define _WIN32_WINNT 0x0600

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <synchapi.h>

int main(int argc, char *argv[])
{
    LPCTSTR sz = L"my.mutex.name";

    // ensure only one running instance
    HANDLE hMutexHandle = CreateMutexW(NULL, 0, sz);
    std::cout << hMutexHandle << std::endl;
    if (hMutexHandle != NULL) {
        std::cout << "Not null" << std::endl;
        // rest of the program
        std::cout << "Hello world!" << std::endl;


        // this is a blocking function
        DWORD  dwWaitResult = WaitForSingleObject( 
            hMutexHandle,    // handle to mutex
            INFINITE);  // no time-out interval

             switch (dwWaitResult) 
        {
            // The thread got ownership of the mutex
            case WAIT_OBJECT_0: 
                 std::cout << "WAIT_OBJECT_0" << std::endl;
                // __try { 
                //     // TODO: Write to the database
                //     printf("Thread %d writing to database...\n", 
                //             GetCurrentThreadId());
                //     dwCount++;
                // } 

                // __finally { 
                //     // Release ownership of the mutex object
                //     if (! ReleaseMutex(ghMutex)) 
                //     { 
                //         // Handle error.
                //     } 
                // } 
                break; 

            // The thread got ownership of an abandoned mutex
            // The database is in an indeterminate state
            case WAIT_ABANDONED: 
                std::cout << "WAIT_ABANDONED" << std::endl;
                break;
        }
        std::cin.get();
        
        ReleaseMutex(hMutexHandle);
        CloseHandle(hMutexHandle);
    } 
    // else {
    //     // std::cout << "Null" << std::endl;
    //     // if (GetLastError() == ERROR_ALREADY_EXISTS)
    //     // {
    //     //     std::cout << "ERROR_ALREADY_EXISTS" << std::endl;
    //     //     //HANDLE hMutex = OpenMutex(SYNCHRONIZE, FALSE, sz);
    //     //     std::cin.get();
    //     //     return EXIT_FAILURE;
    //     // }
    // }


    return EXIT_SUCCESS;
}
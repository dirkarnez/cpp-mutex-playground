cpp-mutex-playground
====================
### To debug in VSCode
- Open (single-click) the built .exe in VSCode and press <kbd>F5</kbd>

### TODOs
- [ ] study how to replace dangling mutex belongs to crashed / terminated process by new mutex
  - [c++ - interprocess::named_upgradable_mutex - remains locked if process is killed - Stack Overflow](https://stackoverflow.com/questions/8501888/interprocessnamed-upgradable-mutex-remains-locked-if-process-is-killed)
    - [boost-single-application](boost-single-application)
    - [win32-single-application](win32-single-application)
  - **UPDATE**
    - `atexit` in normal termination (<kbd>Ctrl</kbd> + <kbd>C</kbd>) can clean up mutex
    - Signal handlers may also work for normal termination
      - [How to use signal handlers in C language?](https://linuxhint.com/signal_handlers_c_programming_language/)
    - Anyway, process killing cannot trigger any cleaning, dangling mutex still there
  - **UPDATE 2023**
    - OS can tell us if a system mutex is dangling:
      - 1. Obtain a handle to the mutex: If you know the name of the mutex, you can use the `OpenMutex` function to obtain a handle to it. This function takes the desired access rights and the name of the mutex as parameters and returns a handle to the mutex if it exists.
      
      ```cpp
      HANDLE hMutex = OpenMutex(SYNCHRONIZE, FALSE, L"MutexName");
      ```
      
      - 2. Check if the handle is valid: The `OpenMutex` function will return a valid handle if the mutex exists and you have the necessary access rights. You can check if the handle is valid by comparing it to the `NULL` value.
      
      ```cpp
      if (hMutex != NULL)
      {
          // Mutex exists and handle is valid
          // The mutex is still active
      }
      else
      {
          // Mutex does not exist or handle is invalid
          // The mutex is not active
      }
      ```
      
      - 3. Close the handle: After you have finished checking the mutex's status, it's important to close the handle using the `CloseHandle` function to release system resources.
      
      ```cpp
      CloseHandle(hMutex);
      ```
  - **UPDATE 2024**
      - don't trust chatgpt code above
      - [**C++多线程之使用Mutex和Critical_Section_std::mutex ccriticalsection-CSDN博客**](https://blog.csdn.net/xdrt81y/article/details/17005235)
        - query mutex state function can be non-waiting
      - [使用 Mutex 物件 - Win32 apps | Microsoft Learn](https://learn.microsoft.com/zh-tw/windows/win32/sync/using-mutex-objects)
        - implemented and working
        - this article tells everything
          - We can query mutex state

By following these steps, you can determine if a mutex is still active on Windows using the Win32 API. Remember to handle errors appropriately and ensure that you have the necessary access rights to open the mutex.
- [ ] compare boost mutex to std::mutex

### Reference
- [Synchronization mechanisms - 1.79.0](https://www.boost.org/doc/libs/1_79_0/doc/html/interprocess/synchronization_mechanisms.html)
- [Locking in C++](http://web.archive.org/web/20140214123807/http://home.roadrunner.com/~hinnant/mutexes/locking.html#Introduction)
- [Synchronization - 1.79.0](https://www.boost.org/doc/libs/1_79_0/doc/html/thread/synchronization.html)

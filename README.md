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
- [ ] compare boost mutex to std::mutex

### Reference
- [Synchronization mechanisms - 1.79.0](https://www.boost.org/doc/libs/1_79_0/doc/html/interprocess/synchronization_mechanisms.html)
- [Locking in C++](http://web.archive.org/web/20140214123807/http://home.roadrunner.com/~hinnant/mutexes/locking.html#Introduction)
- [Synchronization - 1.79.0](https://www.boost.org/doc/libs/1_79_0/doc/html/thread/synchronization.html)
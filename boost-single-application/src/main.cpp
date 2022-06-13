#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    using namespace std;
    using namespace boost::interprocess;

    const char* mutex_name = "my.mutex.name";
    try {
        // named_mutex::remove(mutex_name);
        // cin.get();
        named_mutex mutex(open_or_create, mutex_name);
        scoped_lock<named_mutex> lock(mutex, try_to_lock); // add try_to_lock to stop waiting to unlock
        
        if(lock){
            cout << "hi it is locked" << endl;
            cin.get();
            named_mutex::remove(mutex_name);
            return EXIT_SUCCESS;
        } else {
            cout << "sorry it is locked by other process" << endl;
            cin.get();
            return EXIT_FAILURE;
        }
    } catch(interprocess_exception &ex){
        cout << ex.what() << endl;
        cin.get();
        return EXIT_FAILURE;
    }
}
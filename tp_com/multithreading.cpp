/*
    multithreading entirely depends on the OS

    for linux: POSIX (pthred.h)
    compile w/ -lpthread tag
*/

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

void *wait (void *t)
{
    int i;
    long tid;

    tid = (long) t;
    
    sleep(1);
    cout << "Sleeping in thread " << tid << endl;
    cout << "Thread w/ id: " << tid << " exiting" << endl;

    pthread_exit(NULL);
}

/*
struct thread_data
{
    int thread_id;
    char *message;
};
*/
/* 
void *PrintHello (void *threadarg)
{
    // long tid;
    // tid = (long) threadid;
    // cout << "Hello World! Thread ID, " << tid << endl;
    // // pthread_exit(status)
    // pthread_exit(NULL);

    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;

    cout << "Thread ID: " << my_data->thread_id << endl;
    cout << "Message: " << my_data->message << endl;

    pthread_exit(NULL);
}
*/

int main ()
{
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void *status;
    // struct thread_data td[NUM_THREADS];
    int rc, i;

    // Init and set thread joinable
    /*
        pthread_join(threadid, status)
        pthread_detach(threadid)

        pthread_join() subroutine blocks the calling thread until specified threadid thread terminates
        When thread created, can be joinable or detached
        only the threads initalized as joinable can be joined
    */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "main() : creating thread, " << i << endl;
        // pthread_create(thread, attr, start_routine, arg)
        // thread: identifier for thread
        // attr: set thread attributes (object or NULL)
        // start_routine: C++ routine that the thread will execute
        // arg: must be passed by reference as a pointer cast of type void, or NULL
     
     
        // td[i].thread_id = i;
        // td[i].message = (char*)"This is message";
        // rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
     
        rc = pthread_create(&threads[i], NULL, wait, (void *)i);
        if (rc)
        {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);    
        }
    }
    
    // free attribute and wait for the other threads
    pthread_attr_destroy(&attr);
    for (i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], &status);
        if (rc)
        {
            cout << "Error: unable to join " << rc << endl;
            exit(-1);
        }

        cout << "Main: completed thread id: " << i << endl;
        cout << "Exiting w/ status: " << status << endl;
    }
    
    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);
}
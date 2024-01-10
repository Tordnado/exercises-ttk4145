// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>

int count = 1000000, i = 0;
pthread_mutex_t lock_1;

// Note the return type: void*
void* incrementingThreadFunction(){
    // TODO: increment i 1_000_000 times
    for (size_t n = 0; n < count-100; n++) {
        // pthread_mutex_lock(&lock_1);
        i++;
        // pthread_mutex_unlock(&lock_1);
    }
    return NULL;
}

void* decrementingThreadFunction(){
    // TODO: decrement i 1_000_000 times
    for (size_t m = 0; m < count; m++) {
        // pthread_mutex_lock(&lock_1);
        i--;
        // pthread_mutex_unlock(&lock_1);
    }
    return NULL;
}


int main(){
    // TODO: 
    // start the two functions as their own threads using `pthread_create`
    // Hint: search the web! Maybe try "pthread_create example"?
    
    // Code inspired from https://gist.github.com/ankurs/179778
    pthread_t thread_1, thread_2;
    
    pthread_create(&thread_1, NULL, incrementingThreadFunction(), "increment i");
    pthread_create(&thread_2, NULL, decrementingThreadFunction(), "decrement i");    

    // TODO:
    // wait for the two threads to be done before printing the final result
    // Hint: Use `pthread_join`    

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    // pthread_mutex_destroy(&lock_1); 
    // pthread_mutex_destroy(&lock_2);
    
    printf("The magic number is: %d\n", i);
    return 0;
}

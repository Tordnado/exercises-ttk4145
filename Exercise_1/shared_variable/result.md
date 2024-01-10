Task 3: 

To increment or decrement the variable i stored in the memory, the two threads have to do several operations. First they have to read the old value from the memory, then increased or decreased it by 1, and lastly write the new value back to memory. 

Because the threads share one processor, they need to work around each other. This means that one of the threads can be interupted by the other, say before is was able to write the new value of i. This means the two threads can have different numbers, and depending on wich process that writes to the variable i last, the number that is printet will be whatever the thread wrote to the memory.


Task 4:

Read about the differences at https://stackoverflow.com/questions/2065747/pthreads-mutex-vs-semaphore.

They seem to be very alike, but semaphores (sem_t) can be unlocked by other threads than the one that locked it, mutual exlusion (mutex_t) cannot. In our example, it did not matter, so i choose the mutex.


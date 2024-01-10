Exercise 1 - Theory questions
-----------------------------

### Concepts

What is the difference between *concurrency* and *parallelism*?
> *Your answer here*
> Concurrency is when several tasks are running in between each other. It's an illusion of multiple tasks running in parallel because of a very fast switching between them in the CPU. Two tasks can't run at the same time in a single-core CPU. Parallelism is when tasks actually run in parallel in multiple CPUs.

What is the difference between a *race condition* and a *data race*? 
> *Your answer here* 
> A data race happens when two threads access the same mutable object without synchronization, while a race condition happens when the order of events affects the correctness of the program. A data race can cause a race condition, but not always. A race condition can also occur without a data race.
 
*Very* roughly - what does a *scheduler* do, and how does it do it?
> *Your answer here* 
> It keeps track of processes, and chooses which process that runs at any given time. It can be preemptive, and allocate resources for a fixed amount of time before it switches to other running processes. It can also be non-preemptive, where the resources cannot be taken from a process until it completes execution.

### Engineering

Why would we use multiple threads? What kinds of problems do threads solve?
> *Your answer here*
> Threads are able to run multiple processes simultaniously, and useful for systems that need to be monitor, calculate and take action in real time systems.

Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they, and why would we rather use them over threads?
> *Your answer here*
> Because coroutines are lightweight compared to threads, as they don't require creating and managing additional system resources. This makes coroutines more efficient in terms of memory usage

Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
> *Your answer here*
> I'd say both. It overcomes challenging code problems, but comes with it's own challenges as well.

What do you think is best - *shared variables* or *message passing*?
> *Your answer here*
> I think message passing might be better overall.



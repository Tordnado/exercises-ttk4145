// Use `go run foo.go` to run your program

package main

import (
    . "fmt"
    "runtime"
    // "time"
)

var i, count int = 0, 1000000

func incrementing(operation chan string, work_done chan bool) {
    //TODO: increment i 1000000 times
    for n := 0; n < count-100; n++ {
        operation <- "increment"
	}
    work_done <- true
}

func decrementing(operation chan string, work_done chan bool) {
    //TODO: decrement i 1000000 times
    for m := 0; m < count; m++ {
        operation <- "decrement"
	}
    work_done <- true
}

func server(operation chan string) {
    for {
        select {
        case op := <-operation:
            if op == "increment" {
                i++
            } else if op == "decrement" {
                i--
            }
        default:
            // Do nothing
        }
    }
}

func main() {
    // What does GOMAXPROCS do? What happens if you set it to 1? 
    // GOMAXPROCS sets the maximum number of CPUs that can be executing simultaneously. If it is set to 1, the script prints "1", 
    runtime.GOMAXPROCS(2)
	
    operation := make(chan string)
    work_done := make(chan bool)
    
    // TODO: Spawn both functions as goroutines
    go incrementing(operation, work_done)
    go decrementing(operation, work_done)
    
    go server(operation)
	
    // We have no direct way to wait for the completion of a goroutine (without additional synchronization of some sort)
    // We will do it properly with channels soon. For now: Sleep.
    //time.Sleep(1000*time.Millisecond) 
    
    // Wait for the goroutines to finish
    <-work_done
    <-work_done

    Println("The magic number is:", i)
}

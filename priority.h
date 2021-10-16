// FILE: priority.h
// Coder: Lottie and Dan
// Purpose: priority header file
//
#ifndef PRIORITY_H_INCLUDED
#define PRIORITY_H_INCLUDED

#include "adt.h"

// Coder(s): Lottie and Dan
// Purpose: driver for priority
// Pre: the queue are the processes to calculate waitTime from and preempt and verbose to check if they need to be done
// Post: returns the average wait time
int priority_avg_wait(deque<Queue> q, int numberOfProcessses, bool preempt, bool verbose);

// Coders: Lottie and Dan
// Purpose: non-preemptive priority algorithm
// Pre: q are the processes and verbose to see if it needs to be printed
// Post: average wait time is calc and returned
int priority_avg_wait_noPre(deque<Queue> q, int numberOfProcessses, bool verbose);

// Coders: Lottie and Dan
// Purpose: non-preemptive priority algorithm
// Pre: q are the processes and verbose to see if it needs to be printed
// Post: average wait time is calc and returned
int priority_avg_wait_pre(deque<Queue> q, int numberOfProcessses, bool verbose);

// Coder(s): Dan
// Purpose: updates what processes are ready based on running time
// Pre: processes are the original list of processes, queue of ready processes to update, running time to know how to update it
// Post: returns updated ready Queue
deque<Queue> prepReadyQueue(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime);

// Coder(s): Dan 
// Purpose: finds the process with the lowest priority
// Pre: queue of processes to find the lowest priority
// Post: process with the lowest priority
deque<Queue> lowestPriority (deque<Queue> readyQueue);

 
#endif 

// FILE: priority.h
// Coder: Lottie and Dan
// Purpose: priority header file
//
#ifndef PRIORITY_H_INCLUDED
#define PRIORITY_H_INCLUDED

#include "adt.h"

// Coder(s): 
// Purpose: 
// Pre: 
// Post: 
int priority_avg_wait(deque<Queue> q, int numberOfProcessses, bool preempt, bool verbose);

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

// FILE: roundRobin.h
// Coder: Lottie
// Purpose: Initialize functions for RR
//
#ifndef REDROBIN_H_INCLUDED
#define REDROBIN_H_INCLUDED

#include "adt.h"

// Coder: Lottie
// Purpose: finds the average wait time using the round robin algorithm
// Pre: queue are the processes, quanta is quanta, and verbose to see if verbose needs to be printed or not
// Post: average wait time
int rr_avg_wait(deque <Queue> q, bool verbose, int quanta);
 
// Coder: Dan
// Purpose: updates what processes are ready based on running time
// Pre: processes are the original list of processes, queue of ready processes to update, running time to know how to update it
// Post: returns updated ready Queue
deque<Queue> readyQueueMakerRR(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime);

#endif 

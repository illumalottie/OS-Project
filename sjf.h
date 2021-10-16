// FILE: sjf.h
// Coder:
// Purpose:
//
#ifndef SJF_H_INCLUDED
#define SJF_H_INCLUDED

#include "adt.h"

// Coder(s): Lottie and Dan
// Purpose: driver for shortest job algorithm
// Pre: the queue are the processes to calculate waitTime from and preempt and verbose to check if they need to be done
// Post: returns the average wait time
int sjf_avg_wait(deque <Queue> q, bool preempt, bool verbose);

// Coders: Lottie and Dan
// Purpose: non-preemptive shortest job algorithm
// Pre: q are the processes and verbose to see if it needs to be printed
// Post: average wait time is calc and returned 
int sjf_avg_wait_noPre(deque <Queue> q, bool verbose);

// Coders: Lottie and Dan
// Purpose: preemptive shortest job algorithm
// Pre: q are the processes and verbose to see if it needs to be printed
// Post: average wait time is calc and returned 
int sjf_avg_wait_pre(deque <Queue> q, bool verbose);

// Coder: Dan
// Purpose: updates what processes are ready based on running time
// Pre: processes are the original list of processes, queue of ready processes to update, running time to know how to update it
// Post: returns updated ready Queue
deque<Queue> readyQueueMaker(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime);

// Coder: Dan
// Purpose: finds the Queue with the shortest time
// Pre: list of ready processes to find the process to do first/next
// Post: process with the shortest burst time
deque<Queue> shortestTime(deque<Queue> readyQueue);

#endif 

// FILE: priority.h
// Coder: Lottie and Dan
// Purpose: priority header file
//
#ifndef PRIORITY_H_INCLUDED
#define PRIORITY_H_INCLUDED

#include "adt.h"

int priority_avg_wait(deque<Queue> q, int numberOfProcessses, bool preempt, bool verbose);
deque<Queue> prepReadyQueue(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime);
dequeue<Queue> lowestPriority (dequeue<Queue> readyQueue;


#endif 

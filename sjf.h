// FILE: sjf.h
// Coder: Dan and Lottie
// Purpose: header file for sjf process
//
#ifndef SJF_H_INCLUDED
#define SJF_H_INCLUDED

#include "adt.h"

int sjf_avg_wait(deque <Queue> q, int numberOfProcesses, bool preempt, bool verbose);
deque<Queue> readyQueueMaker(deque <Queue>& processes, deque <Queue>& readyQueue, int runningTime);
deque<Queue> shortestTime(deque<Queue> readyQueue);

#endif 

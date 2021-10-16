// FILE: roundRobin.h
// Coder: Lottie
// Purpose: Initialize functions for RR
//
#ifndef REDROBIN_H_INCLUDED
#define REDROBIN_H_INCLUDED

#include "adt.h"

int rr_avg_wait(deque <Queue> q, bool verbose, int quanta);
deque<Queue> readyQueueMakerRR(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime);

#endif 

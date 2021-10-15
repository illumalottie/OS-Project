// FILE: fcfs.h
// Coder:
// Purpose:
//
#ifndef FCFS_H_INCLUDED
#define FCFS_H_INCLUDED

#include "adt.h"

// Coder: J Yong
// Purpose: finds the avg wait time for fcfs
// Pre: q is where the total wait time is being pulled from
// Post: fcfs average wait time
int fcfs_avg_wait(deque<Queue> q);

#endif

// FILE: fcfs.cpp
// Coder:
// Purpose: First come first serve
#include "fcfs.h"
#include "adt.h"

int fcfs_avg_wait (deque<Queue> q, int processCnt) {
  int totalWait = 0;
  deque<Queue> gant = q;
  
  while (!gant.empty()) {
    totalWait = totalWait + gant.front().total_CPU_burst;
    gant.pop_front();
  }

  int avg_wait = totalWait/processCnt;
  return avg_wait; 
}

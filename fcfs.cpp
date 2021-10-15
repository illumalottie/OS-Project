// FILE: fcfs.cpp
// Coder:
// Purpose: First come first serve
#include "fcfs.h"
#include "adt.h"

int fcfs_avg_wait (deque<Queue> q, int processCnt) {
  int totalWait = 0;
  deque<Queue> gant = q;
  
  for (int i = 1; i < processCnt; i++) {
    waitTime = waitTime + q[i-1].total_CPU_burst;
    totalWait = totalWait + waitTime;
  }
  int avg_wait = totalWait/processCnt;
  return avg_wait; 
}

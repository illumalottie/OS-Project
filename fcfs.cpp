// FILE: fcfs.cpp
// Coder:
// Purpose: First come first serve
#include "fcfs.h"
#include "adt.h"

int fcfs_avg_wait (deque<Queue>& q, int processCnt) {
  int time = 0;
  int totalWait;
  
  for (int i = 1; i < processCnt; i++) {
    time = time + q[i-1].total_CPU_burst;
    q[i].waitTime  = time + q[i].waitTime; //changes Wait Time in the deque 
    totalWait = totalWait + q[i].waitTime;
  }
  
  int avg_wait = totalWait/processCnt;
  return avg_wait; 
}

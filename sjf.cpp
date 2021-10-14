// FILE: sjf.cpp
// Coder:
// Purpose: First come first serve
#include "sjf.h"
 
int sjf_avg_wait(deque<Queue> q, int numberOfProcessses, bool preempt){
  int runningTime = 0;
  int shortTime = 0;
  int initalSize = q.size();
  int queueSize = q.size();
  deque<Queue> processes = q;
  deque<Queue> readyQueue;
  deque<Queue> terminated;
  Queue running;


  while(terminated.size() < initalSize){
    
  processes = readyQueueMaker(processes, readyQueue, runningTime);
  readyQueue = shortestTime(readyQueue);
  running = readyQueue.front();
  readyQueue.pop_front();
  
  while(running.total_CPU_burst > 0){
    --running.total_CPU_burst;
    ++runningTime;
    for(int p = 0; p < readyQueue.size(); p++){
      ++readyQueue[p].waitTime;
    }

    if (running.total_CPU_burst == 0){
      terminated.push_front(running);
    }
    
   processes = readyQueueMaker(processes, readyQueue, runningTime);
    
  }
  terminated.push_front(running);
  }
}

deque<Queue>  readyQueueMaker(deque <Queue>& processes, deque <Queue>& readyQueue, int runningTime){

  deque<Queue> ah;
  for(int i = 0; i < processes.size(); i++){
    if(processes[i].arrival_time == runningTime){
      readyQueue.push_back(processes[i]);
    }
    else {
      ah.push_back(processes[i]);
    }
  }

  return ah;
}

deque<Queue> shortestTime(deque<Queue> readyQueue){
  int shortTime = readyQueue.front().total_CPU_burst;
  deque<Queue> newReadyQueue;
  Queue shortest;

  
  for(int i = 0; i < readyQueue.size(); i++){
    if(readyQueue[i].total_CPU_burst < shortTime){
      shortest = readyQueue[i];
    }
  }

  newReadyQueue.push_front(shortest);

  for(int i = 0; i < readyQueue.size(); i++){
    if (readyQueue[i].p_id != shortest.p_id){
    newReadyQueue.push_back(readyQueue[i]);
    }
  }
  return newReadyQueue; 
}

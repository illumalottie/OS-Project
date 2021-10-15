// FILE: sjf.cpp
// Coder: Dan Aossey & Lottie
// Purpose: First come first serve
#include "priority.h"
 
int sjf_avg_wait(deque<Queue> q, int numberOfProcessses, bool preempt){
  int runningTime = 0;
  int shortTime = 0;
  int avgWait = 0;
  int initalSize = q.size();
  int queueSize = q.size();
  deque<Queue> processes = q;
  deque<Queue> readyQueue;
  deque<Queue> terminated;
  Queue running;
  while(terminated.size() < initalSize){
    processes = prepReadyQueue(processes, readyQueue, runningTime);
     if (readyQueue.size() > 0){
    readyQueue = lowestPriority(readyQueue);
    cout << endl << "ready queue is" << readyQueue.front().p_id << endl;
    if ( readyQueue.size() > 0){ 
      running = readyQueue.front();
    }
    cout << running.total_CPU_burst << endl;
    if(readyQueue.size() > 0){ 
      readyQueue.pop_front();
      while(running.total_CPU_burst > 0){
	--running.total_CPU_burst;
	++runningTime;
	processes = prepReadyQueue(processes, readyQueue, runningTime);
	for(int p = 0; p < readyQueue.size(); p++){
	  ++readyQueue[p].waitTime;
	}
      }
        if (running.total_CPU_burst == 0){
	  terminated.push_front(running);
	}
	processes = prepReadyQueue(processes, readyQueue, runningTime);
    }
     }
     else {
       ++runningTime;
     }
  }
  for (int i = 0; i < terminated.size(); i++){
    avgWait = avgWait + terminated[i].waitTime;
  }
  avgWait = avgWait/terminated.size();    
  return avgWait;
}
deque<Queue>  prepReadyQueue(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime){
  deque<Queue> ah;
  for(int i = 0; i < processes.size(); i++){
    if(processes[i].arrival_time == runningTime){
      readyQueue.push_back(processes[i]);
    }
    else {
      ah.push_front(processes[i]);
    }
  }
  return ah;
}
// lowestPriority fn - returns a deque with the process holding the lowest priority value at the front
deque<Queue> lowestPriority(deque<Queue> readyQueue){
  int shortTime = readyQueue.front().total_CPU_burst;
  deque<Queue> newReadyQueue;
  Queue shortest;
// runs based on the side of the readyQueue comparing each element and saving the lowest in the shortest var
  for(int i = 0; i < readyQueue.size(); i++){
    if(readyQueue[i].total_CPU_burst <= shortTime){
      shortest = readyQueue[i];
	shortTime = shortest.total_CPU_burst;
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

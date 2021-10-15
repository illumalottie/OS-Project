// FILE: priority.cpp
// Coder: Lottie and Dan
// Purpose: priority sort function
#include "priority.h"
 // priority_avg_wait fn - returns an int value representing the average wait time of an inputed process using priority, can operate with preemption on or off
int priority_avg_wait(deque<Queue> q, int numberOfProcessses, bool preempt, bool verbose){
  int runningTime = 0;
  int shortTime = 0;
  int avgWait = 0;
  int initalSize = q.size();
  int queueSize = q.size();
  deque<Queue> processes = q;
  deque<Queue> readyQueue;
  deque<Queue> terminated;
  Queue running;
	// while runs as long as the terminated que is smaller than the size of the inputed queue
  while(terminated.size() < initalSize){
	  // processes is our "new" queue, readyQueueMaker returns a dequeu with all the elemets of the original que not inserted into the ready queue during the fn
    processes = prepReadyQueue(processes, readyQueue, runningTime);
     if (readyQueue.size() > 0){
    readyQueue = lowestPriority(readyQueue);
      running = readyQueue.front();
    }
	  // checks if there are elemets in the ready que and if not skips everything and just incrimints the time
    cout << running.total_CPU_burst << endl;
    if(readyQueue.size() > 0){  
      readyQueue.pop_front();
	    // while loop runs based on a processes burst time while updating runtime
      while(running.total_CPU_burst > 0){
	--running.total_CPU_burst;
	++runningTime;
	processes = prepReadyQueue(processes, readyQueue, runningTime);
	      // update the wait value of every process in the ready que for each cycle
	for(int p = 0; p < readyQueue.size(); p++){
	  ++readyQueue[p].waitTime;
	}
      }
	    // checks if a process has finished running and adds it to the terminated que
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
// calculates wait time based on the stored wait in every process 
  for (int i = 0; i < terminated.size(); i++){
    avgWait = avgWait + terminated[i].waitTime;
  }
  avgWait = avgWait/terminated.size();
// verbose adds extra output of all the processes in the order they terminated and their total wait time
	if(verbose){
	for (int i = 0; i < terminated.size(); i++){
	cout << endl << "Process: " << terminated[i].p_id << " (wait " << terminated[i].waitTime << ")";
	}
  return avgWait;
}
// prepReadyQueue fn - returns a deque of all the proccesses not added to the ready queue while updating the ready queue via refrence
deque<Queue>  prepReadyQueue(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime){
  deque<Queue> ah;
	//loops for the total number of processes adding the element to the ready queue or ah which returns as the "new" queue
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
// lowestPriority fn - returns a deque with the element that has the lowest priority number first
deque<Queue> lowestPriority(deque<Queue> readyQueue){
  int lowPriority = readyQueue.front().priority;
  deque<Queue> newReadyQueue;
  Queue lowest;
	// loops for the number of elements in the ready queue updating if an element has a lower priority number
  for(int i = 0; i < readyQueue.size(); i++){
    if(readyQueue[i].priority <= shortTime){
      lowest = readyQueue[i];
	lowPriority = lowest.priority;
    }
  }
	// puts the lowestPriority value process at the start of a fn and then adds the rest of the readyQueue to the end of that queue while leaving out the duplicate lowestpriority process
  newReadyQueue.push_front(shortest);
  for(int i = 0; i < readyQueue.size(); i++){
    if (readyQueue[i].p_id != lowest.p_id){
    newReadyQueue.push_back(readyQueue[i]);
    }
  }
  return newReadyQueue; 
}

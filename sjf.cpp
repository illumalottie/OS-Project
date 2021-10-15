// FILE: sjf.cpp
// Coder: Dan Aossey & Lottie
// Purpose: First come first serve function
#include "sjh.h"
// sjf_avg_wait fn - returns an int value representing the average wait time of an inputed process, can operate with preemption on or off
int sjf_avg_wait(deque<Queue> q, int numberOfProcessses, bool preempt, bool verbose){
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
    processes = readyQueueMaker(processes, readyQueue, runningTime);
     if (readyQueue.size() > 0){
    readyQueue = shortestTime(readyQueue);
    running = readyQueue.front();
    }
// checks if there are elemets in the ready que and if not skips everything and just incrimints the time
    if(readyQueue.size() > 0){ 
      readyQueue.pop_front();
// while loop runs based on a processes burst time while updating runtime
      while(running.total_CPU_burst > 0){
	--running.total_CPU_burst;
	++runningTime;
	processes = readyQueuemaker(processes, readyQueue, runningTime);
// update the wait value of every process in the ready que for each cycle
	for(int p = 0; p < readyQueue.size(); p++){
	  ++readyQueue[p].waitTime;
	}
      }
// checks if a process has finished running and adds it to the terminated que
        if (running.total_CPU_burst == 0){
	  terminated.push_front(running);
	}
	processes = readyQueueMaker(processes, readyQueue, runningTime);
    }
     }
     else {
       ++runningTime;
     }
  }
// calculates wait time based on the stared wait in every process 
  for (int i = 0; i < terminated.size(); i++){
    avgWait = avgWait + terminated[i].waitTime;
  }

if(verbose){
	for (int i = 0; i < terminated.size(); i++){
	cout << endl << "Process: " << terminated[i].p_id << " (wait " << terminated[i].waitTime << ")";
	}
}

  avgWait = avgWait/terminated.size();    
  return avgWait;
}

// readyQueueMaker fn - returns an updated "new" queue and updates the readyqueu via refrence
deque<Queue>  readyQueueMaker(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime){
  deque<Queue> ah;
// loops throught every process in the deque seeing if and how many processes "arrive" at the curent time, each process is either put in the ready queue or in the "new" queue
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
// shortestTime fn - returns a deque with the process holding the lowest priority value at the front
deque<Queue> shortestTime(deque<Queue> readyQueue){
  int shortTime = readyQueue.front().total_CPU_burst;
  deque<Queue> newReadyQueue;
  Queue shortest;
// runs for loop based on the size of the readyQueue comparing each element and saving the lowest in the shortest var
  for(int i = 0; i < readyQueue.size(); i++){
    if(readyQueue[i].total_CPU_burst <= shortTime){
      shortest = readyQueue[i];
	shortTime = shortest.total_CPU_burst;
    }
  }
// puts the process with the shortest time at the front of the deque and adds all the other processes at the end of the dequeu
// you can't pop an element in the middle of a deque so we had to use the if statment to add everything that isnt the shortest process in deque
  newReadyQueue.push_front(shortest);
  for(int i = 0; i < readyQueue.size(); i++){
    if (readyQueue[i].p_id != shortest.p_id){
    newReadyQueue.push_back(readyQueue[i]);
    }
  }
  return newReadyQueue; 
}

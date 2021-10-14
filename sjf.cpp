// FILE: sjf.cpp
// Coder:
// Purpose: First come first serve
#include "sjf.h"
 
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

    processes = readyQueueMaker(processes, readyQueue, runningTime);
     if (readyQueue.size() > 0){
    readyQueue = shortestTime(readyQueue);
    cout << endl << "ready queue is" << readyQueue.front().p_id << endl;
    if ( readyQueue.size() > 0){ 
      running = readyQueue.front();
    }
    cout << "cheddae" << readyQueue.front().total_CPU_burst << endl;
    cout << "YOOOOOOOOOOOO" << endl;
    cout << running.total_CPU_burst << endl;
    if(readyQueue.size() > 0){  


      cout << endl << "shortest do be" << running.p_id << endl;

      readyQueue.pop_front();

      while(running.total_CPU_burst > 0){
	--running.total_CPU_burst;
	++runningTime;
	processes = readyQueueMaker(processes, readyQueue, runningTime);
	cout << "CHAAAAAAAAAAAD " << readyQueue.size() << endl;
	for(int p = 0; p < readyQueue.size(); p++){
	  ++readyQueue[p].waitTime;
	  cout <<"sammy" <<  readyQueue[p].waitTime << endl;
	}
      }
        if (running.total_CPU_burst == 0){
	  terminated.push_front(running);
	  cout << "carly" << terminated.front().p_id;
	}
      
	processes = readyQueueMaker(processes, readyQueue, runningTime);
    
    }

    
     }

     else {
       ++runningTime;
     }

  }
  
  for (int i = 0; i < terminated.size(); i++){
    avgWait = avgWait + terminated[i].waitTime;
    cout << endl << "mommy milkers" << terminated[i].p_id;
    cout << endl << "I am gonna kill myself" << terminated[i].waitTime << endl;
  }
  

  avgWait = avgWait/terminated.size();
       
  return avgWait;
}

deque<Queue>  readyQueueMaker(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime){

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

deque<Queue> shortestTime(deque<Queue> readyQueue){
  int shortTime = readyQueue.front().total_CPU_burst;
  deque<Queue> newReadyQueue;
  Queue shortest;


  
  for(int i = 0; i < readyQueue.size(); i++){
    if(readyQueue[i].total_CPU_burst <= shortTime){
      shortest = readyQueue[i];
	shortTime = shortest.total_CPU_burst;
	cout << "PEE" << shortTime << endl;
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

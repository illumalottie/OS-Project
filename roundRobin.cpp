// FILE: roundRobin.cpp
// Coder: Lottie (using other work from Dan & Lottie)
// Purpose: send processes through RR
#include "roundRobin.h"
//comments by Lottie
//purpose: roundRobin avg wait time
int rr_avg_wait(deque<Queue> q, bool verbose, int quanta){
  int runningTime = 0;
  int shortTime = 0;
  int avgWait = 0;
  int initalSize = q.size();
  int queueSize = q.size();
  deque<Queue> processes = q;
  deque<Queue> readyQueue;
  deque<Queue> terminated;
  Queue running;
  //get all initial queues
  processes = readyQueueMakerRR(processes, readyQueue, runningTime);
  //while loop to catch up to the first arrival time
  while(readyQueue.size() == 0){
    ++runningTime;
    processes = readyQueueMakerRR(processes, readyQueue, runningTime);
  }
  running = readyQueue.front();
  readyQueue.pop_front();
  running.quantaCount = 0;
  // while loop keeps repeating until every process has been terminated by checking thew size of the terminated queue
  while(terminated.size() < initalSize){
    --running.total_CPU_burst;
    ++runningTime;
    ++running.quantaCount;
    // increases the waitTime stored in each element of the ready queue for the avg wait time
    for(int p = 0; p < readyQueue.size(); p++){
      ++readyQueue[p].waitTime;
    }
  
    // checks if the current process is finished and whether or not to make a new ready queue
    if (running.total_CPU_burst == 0){ 
      terminated.push_front(running);
      //if not completely done, make another set of queues for the next go around
      if (terminated.size() !=  initalSize){
	processes = readyQueueMakerRR(processes, readyQueue, runningTime);
	running = readyQueue.front();
	readyQueue.pop_front();
	running.quantaCount = 0;
      }
    }
    // if the quantaCount matches the quanta, then the unfinished process is sent back to the ready queue to be finished later
    else if (running.quantaCount == quanta){
      running.quantaCount = 0;
      readyQueue.push_back(running);
      processes = readyQueueMakerRR(processes, readyQueue, runningTime);
      //a new running and ready is made for the next loop
      running = readyQueue.front();
      readyQueue.pop_front();
      running.quantaCount = 0;
    }
    //makes a new set of queues in case something new enters the ready queue and needs its waitTime incremented
    processes = readyQueueMakerRR(processes, readyQueue, runningTime);
    
  }
  //adds all collected waitTimes and takes the average to get the avgWait
  for (int i = 0; i < terminated.size(); i++){
    avgWait = avgWait + terminated[i].waitTime;
    if(verbose){
      cout << endl << terminated[i].p_id << " was terminated and had a wait time of " << terminated[i].waitTime;
    }
  }
  avgWait = avgWait/terminated.size();
  return avgWait;
}
//pre: gets the queue that was initially gathered from the file (processes), the readyQueue, and the runningTime
//post/purpose: updates readyQueue, returns leftover processes (temp) 
deque<Queue>  readyQueueMakerRR(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime){
  deque<Queue> temp;
  // checks if a process should be added from the "new" queue to the ready queue
  for(int i = 0; i < processes.size(); i++){
    if(processes[i].arrival_time == runningTime){
      readyQueue.push_back(processes[i]);
    }
    else {
      temp.push_front(processes[i]);
    }
  }
  return temp;
}

// FILE: sjf.cpp
// Coder: Lottie & Dan
// Purpose: Runs a queue through priority
#include "sjf.h"

int sjf_avg_wait(deque<Queue> q, int numberOfProcesses, bool preempt, bool verbose){
  if (preempt){
    return sjf_avg_wait_pre(q, numberOfProcesses, verbose);
  }
  return sjf_avg_wait_noPre(q, numberOfProcesses, verbose);
}
int sjf_avg_wait_noPre(deque<Queue> q, int numberOfProcessses, bool verbose){
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
    processes = readyQueueMaker(processes, readyQueue, runningTime);
    if (readyQueue.size() > 0){
      readyQueue = shortestTime(readyQueue);
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
	processes = readyQueueMaker(processes, readyQueue, runningTime);
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
  }
  return avgWait;
}

//priority_avg_wait_pre - returns the average wait time whith priority and preemption on
int sjf_avg_wait_pre(deque<Queue> q, int numberOfProcessses, bool verbose){
  int runningTime = 0;
  int shortTime = 0;
  int avgWait = 0;
  int initalSize = q.size();
  int queueSize = q.size();
  deque<Queue> processes = q;
  deque<Queue> readyQueue;
  deque<Queue> terminated;
  Queue running;
  processes = readyQueueMaker(processes, readyQueue, runningTime);
  // while loop keeps repeating untill every process has been terminated by checking thew size of thr terminated queue
  while(terminated.size() < initalSize){
    // checks if there is anything in thr readyQueue, if empty the total running time incremints and the ready queue is updated before the while loop starts over
    // if the condition is successful the ready queue will be updated by pushing the element we need to the front 
    if(readyQueue.size() > 0){
      readyQueue = shortestTime(readyQueue);
      running = readyQueue.front();
      readyQueue.pop_front();
      --running.total_CPU_burst;
      ++runningTime;
      // incremints the waitTime stored in each element of the ready queue for the avg wait time
      for(int p = 0; p < readyQueue.size(); p++){
	++readyQueue[p].waitTime;
      }
      /*
	cout << "here is the pid and then the wait time for rdq 1: " << readyQueue[0].p_id << " ";
	cout <<  readyQueue[0].waitTime << endl;
	cout << "here is the pid and then the wait time for rdq 2: " << readyQueue[1].p_id << " ";
	cout <<  readyQueue[1].waitTime << endl;
      */
      // checks if the current process is finished and goes into the terminated queue or intead goes back into the ready queue
      if (running.total_CPU_burst == 0){
	terminated.push_front(running);
      }
      else if (running.total_CPU_burst !=0){
	readyQueue.push_back(running);
      }
    }
    else{
      ++runningTime;
    } 
    processes = readyQueueMaker(processes, readyQueue, runningTime);
  }
  // uses a for loop based on the size of readyQueueMaker to add up all the waitTime values of the processes
  for (int i = 0; i < terminated.size(); i++){
    avgWait = avgWait + terminated[i].waitTime;
    cout << "HERE IS THE WAIT" << avgWait << endl;
    if(verbose){
      cout << endl << terminated[i].p_id << " was terminated and had a wait time of " << terminated[i].waitTime;
    }
  }
  avgWait = avgWait/terminated.size();
  return avgWait;
}

// makeReadyQueue - updates the current ready queue via refrence while returning an updated verison of the "new" queue
deque<Queue>  readyQueueMaker(deque <Queue> processes, deque <Queue>& readyQueue, int runningTime){
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

// lowestPriorityVal - returns an updated version of the ready queue with the first element now being the elemet with the lowest priority value
deque<Queue> shortestTime(deque<Queue> readyQueue){
  int shortTime = readyQueue.front().total_CPU_burst;
  deque<Queue> newReadyQueue;
  Queue shortest;
  // compares each element of the queue to find the one with the lowest priority value
  for(int i = 0; i < readyQueue.size(); i++){
    if(readyQueue[i].total_CPU_burst <= shortTime){
      shortest = readyQueue[i];
      shortTime = shortest.total_CPU_burst;
    }
  }
  // places the lowest priority value at the front of the new ready queue
  newReadyQueue.push_front(shortest);
  // places all the other ready queue elements in the updated ready queue while avoiding duplicating the lowest 
  for(int i = 0; i < readyQueue.size(); i++){
    if (readyQueue[i].p_id != shortest.p_id){
      newReadyQueue.push_back(readyQueue[i]);
    }
  }
  return newReadyQueue; 
}

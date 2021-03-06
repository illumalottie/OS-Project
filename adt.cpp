// FILE: adt.cpp 
// Coder: J Yong + Lottie Maynard
// Purpose: this can be deleted 
#include "adt.h"

// unfinished lines in the input file will break program
void read_File (deque<Queue>& q, string fileName) { 
	Queue newProcess;
	ifstream getInput;
	getInput.open(fileName);
	
	if (!getInput.is_open()) {
	  cout << endl << "Invalid File entered: Opening default file...";
	  getInput.open("sched.in");
  	}

	//if there's nothing in the deque, it'll segmentation fault in sortingHat
	getInput >> newProcess.p_id; 
	getInput >> newProcess.arrival_time;
	getInput >> newProcess.total_CPU_burst;
	getInput >> newProcess.priority;
	q.push_back(newProcess);
	
	//reads in p_id first so that it can start on the next line after pushing
	//a new process
	getInput >> newProcess.p_id; 
        while (!getInput.eof()) {
		getInput >> newProcess.arrival_time;
		getInput >> newProcess.total_CPU_burst;
		getInput >> newProcess.priority;
	
		sortingHat(q, newProcess); //for fcfs
		
		getInput >> newProcess.p_id; //checks if there is a next line
	} 
	
	getInput.close();
}

//this is why deque was used
void sortingHat(deque<Queue>& q, Queue newProcess) {
  deque<Queue> more_than_new;
  if (newProcess.arrival_time <= q.front().arrival_time) {
    q.push_front(newProcess);
  }
  else if (newProcess.arrival_time >= q.back().arrival_time) {
    q.push_back(newProcess);
  }
  else {
    while (newProcess.arrival_time < q.back().arrival_time) { //looking for an arrival time more than new arr time
      //moves aside Queues w. more arrival times 
      more_than_new.push_front(q.back());
      q.pop_back(); //pops the tail to compare with another tail
    }
    
    q.push_back(newProcess);
    
    while (!more_than_new.empty()) { //puts back Queues that were put on the side
      q.push_back(more_than_new.front());
      more_than_new.pop_front();
    }
  }
}

void for_Verbose(string fileName, string type, bool preemptive, int quanta, deque<Queue> q, int avg_wait) {
  cout << endl << "File Name: " << fileName
       << endl << "Scheduling Type: " << type
       << endl << "Quanta: " << quanta
       << endl << "Pre-emption(0 is false & 1 is true): " << preemptive
       << endl << "Number of processes: " <<  q.size()
       << endl << "Average Wait Time: " << avg_wait;
  printQ(q);
}

void printQ(deque<Queue> q)
{
  Queue temp;
  deque<Queue> t = q;
  while (!t.empty()) {
    temp = t.front();
    cout << endl << "P_id: " << temp.p_id
	 << " Arrival Time: " << temp.arrival_time
	 << " Total CPU Burst: " << temp.total_CPU_burst
	 << " Priority: " << temp.priority
	 << " Wait Time: " << temp.waitTime << endl;
    t.pop_front();
  }
  cout << endl;
}

bool did_user_forget(string c) { 
  if (c == "--type" || c == "--preemptive" || c == "--quanta" || c == "--file" || c == "--verbose") {
    return true; //yes they forgot
  }
  else {
    return false;
  }
}

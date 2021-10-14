// FILE: adt.cpp 
// Coder: J Yong + Lottie Maynard
// Purpose: this can be deleted 
#include "adt.h"

int read_File (deque<Queue>& q, string fileName) {
	int processCnt = 1; 
	Queue newProcess;
	ifstream getInput;
	getInput.open(fileName);
	
	if (!getInput.is_open()) {
	  cout << endl << "Invalid File entered: Going to default...";
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
	do { 
		getInput >> newProcess.arrival_time;
		getInput >> newProcess.total_CPU_burst;
		getInput >> newProcess.priority;
		cout << endl << " Pre " << q.front().arrival_time << " Post " << newProcess.arrival_time << endl;
	
		sortingHat(q, newProcess);
		
		processCnt++;
		getInput >> newProcess.p_id; //checks if there is a next line
	} while (!getInput.eof());
	
	getInput.close();
	return processCnt;
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

//Debugging 
void printQ(deque<Queue> q)
{
  Queue temp;
  deque<Queue> t = q;
  while (!t.empty()) {
    temp = t.front();
    cout << endl << temp.p_id << " " << temp.arrival_time << " " << temp.total_CPU_burst << " " << temp.priority;
    t.pop_front();
  }
  cout << '\n';
}

bool did_user_forget(string c) {
  if (c == "--type" || c == "--preemptive" || c == "--quanta" || c == "--file" || c == "--verbose") {
    return true; //yes they forgot
  }
  else {
    return false;
  }
}

bool valid_type (string c) {
  if (c == "FCFS" || c == "SJF" || c == "Priority" || c == "RR" || c == "fcfs" || c == "sjf" || c == "rr")
    {
      return true; //it is valid
    }
  else {
    return false;
  }
} 

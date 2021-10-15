// FILE: driver.cpp
// Coders: Group 3 - Joey Yong, Lottie Maynard, and Dan
// Purpose: Simulates the scheduling for a CPU
//  INPUT: input file "input.in" 
//         p_id  arrival_time  total_CPU_burst  Priority
//         
//         --type {FCFS|SJF|Priority|RR}
//         --type preemptive (not is the default)
//         --quanta#(10 is the default)
//         --file NAME (sched.in is the default)
//         --verbose (not is the default) for the extra info 
//
//  OUTPUT: average wait time for each process
//  SOURCES: 
//  printQ is a version of showdq https://www.geeksforgeeks.org/deque-cpp-stl/
//  using struct for a queue/deque https://stackoverflow.com/questions/25074741/how-do-i-store-and-get-a-queue-of-structure
//  Used deque because it's more flexible than queue https://www.cplusplus.com/reference/deque/deque/push_front/
//  catch error from stoi https://www.cplusplus.com/reference/stdexcept/invalid_argument/
//
//  Side-Quests: detect unfinished lines

#include <iostream>
#include "fcfs.h"
#include "sjf.h"
#include "priority.h"
#include "roundRobin.h"
#include "adt.h"

using namespace std;

int main(int argc, char **argv) {
  deque<Queue> q; 
  string com[100], fileName, type = "FCFS";
  char f;
  int flagCnt = 0, quanta = 10;
  bool preemptive = false;
  bool verbose = false;
  
  // For flags: 
  //	Lottie wrote the frame
  //	Joey filled in the frame 
  while (--argc > 0) { //stores flags into a string array
    com[flagCnt] = argv[1];
    cout << com[flagCnt] << endl;
    ++argv;
    ++flagCnt;
  }
  cout << endl;
  
  for (int i = 0; i < flagCnt; i++) {
    if(com[i] == "--type"){
      if (did_user_forget(com[i + 1]) == false) {
	      i++; 
	      type = com[i];
      }
    }
    else if(com[i] == "--preemptive") {
      preemptive = true;
    }
    else if(com[i] == "--quanta") {
      if (did_user_forget(com[i + 1]) == false) {
	      i++;
	      try {quanta = stoi(com[i]);}
        	//catches the user trying to convert a not-integer-representing string
	      catch (exception &err) { //for the exception http://cplusplus.com/forum/beginner/253696/
	        cerr << "Invalid Quanta: defaulting to 10\n";
	      }
      }
    }
    else if(com[i] == "--file"){
      if (did_user_forget(com[i + 1]) == false) {
	      i++;
	      fileName = com[i];
      }
    }
    else if(com[i] == "--verbose"){
      verbose = true;
    }
    else {
	    i++; //ignore a non-flag
    }
  }
  
  if (type == "SJF" || type == "sjf") {

  }
  else if (type == "RR" || type == "rr") {

  }
  else if (type == "Priority" || type == "priority") {

  }
  else { //defaults to fcfs
  	avg_wait = fcfs_avg_wait(q);
  }
  	
  if (verbose == true) {
    for_Verbose(fileName, type, preemptive, quanta, q, avg_wait, processCnt); 
  }
  else {
    cout << endl << "Average Wait Time: " << avg_wait << endl;
  }
	
  return 0;
}

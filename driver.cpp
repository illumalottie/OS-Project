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
//  using struct for a queue/deque https://stackoverflow.com/questions/25074741/how-do-i-store-and-get-a-queue-of-structure
//  Used deque because it's more flexible than queue https://www.cplusplus.com/reference/deque/deque/push_front/
//  catch error from stoi https://www.cplusplus.com/reference/stdexcept/invalid_argument/

//  Side-Quests: detect unfinished lines, empty files?
//
#include <iostream>
#include "fcfs.h"
#include "sjf.h"
#include "priority.h"
#include "roundRobin.h"
#include "adt.h"

using namespace std;

int main(int argc, char **argv) {
  deque<Queue> q; //maybe do the lexical definition he mentioned? thoughts? - lottie
  string com[100];
  char f;
  int i = 0;
  
  //THIS IS ALL TESTING 
  while (--argc >= 0) { //IT WORKS 
    if ((*++argv)[0] == '-') {
    //  while (f = *++argv[0]) {
    } 
    else { //not flag argv's
      com[i] = argv[0];
      cout << endl << com[i];
      if (com[i] == "yum") {
        cout << endl << "it works! YUM!";
      }
      i++;
    }
  }
  //
  
  int processCnt = read_File(q, "sched.in");
  cout << endl << "Number of processes: " << processCnt; //debug comment
  
  //i can pass in an Queue array and it brings back all the info from the file
  //below the couts are just tests to make sure it returns the right numbers - lottie

  Queue temp = q.front();
  cout << endl << "\nDEBUG"
       << endl << temp.p_id 
       << " " << temp.arrival_time << endl;
  
  printQ(q);
  return 0;
}

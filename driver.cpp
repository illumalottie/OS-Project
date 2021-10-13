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
//
//  Side-Quests: detect unfinished lines
//
#include <iostream>
#include "fcfs.h"
#include "sjf.h"
#include "priority.h"
#include "redRobin.h"
#include "adt.h"

using namespace std;

int main(int argc, char **argv) {
  Queue q[100]; //maybe do the lexical definition he mentioned? thoughts? - lottie

  read_File(q);

  //i can pass in an Queue array and it brings back all the info from the file
  //below the couts are just tests to make sure it returns the right numbers - lottie



  cout << q[0].p_id << endl;
  cout << q[1].p_id << endl;
  return 0;
}

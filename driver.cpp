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
#include "roundRobin.h"
#include "adt.h"

using namespace std;

int main(int argc, char **argv) {
  Queue q[100]; //maybe do the lexical definition he mentioned? thoughts? - lottie
  string com[100];
  char f;
  
  //THIS IS ALL TESTING 
  while (--argc >= 0) { //IT WORKS 
    //if ((*++argv)[0] == '-') {
    //  while (f = *++argv[0]) {
    // 
    //else { //not flag argv's
    //  *++argv[0];

    com[argc] = argv[argc];
    cout << endl << com[argc];
    if (com[argc] == "yum") {
      cout << endl << "it works! YUM!";
    }
    i++;
  }
  //
  
  read_File(q, "sched.in");

  //i can pass in an Queue array and it brings back all the info from the file
  //below the couts are just tests to make sure it returns the right numbers - lottie



  cout << q[0].p_id << endl;
  cout << q[1].p_id << endl;
  return 0;
}

// FILE: adt.h
// Coder:
// Purpose:
//
#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;


struct Queue {
  string p_id
  int priority;
  int arrival_time;
  int total_CPU_Burst;
}; 
  

// Coder(s): J Yong 
//           Lottie Maynard
// Purpose: reads in all input from file stream into a struct
// Pre: Queue struct to read file input in
//      fileName to open file
// Post: all input form file has been entered into a queue struct
//       and an the number of processes has been returned
int read_File (deque<Queue>& q, string fileName);

// Coder: J Yong
// Purpose: eval and inputs new Queues according to their arrival time
// Pre: deque<Queue> to put the new process in
//      newProcess - a Queue struct that has not been pushed into the q
// Post: newProcess is in the deque<Queue> q
void sortingHat(deque<Queue>& q, Queue newProcess);

// Coder: J Yong
// Purpose: print the queue
// Pre: deque to print
// Post: deque has been printed
// Note: can be deleted
void printQ(deque<Queue> q);
#endif

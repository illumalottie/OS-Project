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
#include <stack>
#include <vector>
using namespace std;


struct Queue {
  string p_id
  int priority;
  int arrival_time;
  int total_CPU_Burst;
}; 
  

// Coder: J Yong + Lottie Maynard
// Purpose: reads in all input from file stream into a struct
// Pre: Queue struct to read file input in
//      fileName to open file
// Post: all input form file has been entered into a queue struct
//       and an the number of processes has been returned
int read_File (queue<Queue>& q, string fileName);

#endif

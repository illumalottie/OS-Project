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
  int p_id, priority;
  float arrival_time;
  float total_CPU_Burst;
}; //queue; << the compiler was angry because I think it kept getting redefined per file it was included in, ur welcome to mess with it - lottie
  

// Coder: J Yong + Lottie Maynard
// Purpose: reads in all input from file stream into a struct
// Pre: Queue struct to read file input in
//      fileName to open file
// Post: all input form file has been entered into a queue struct
void read_File (Queue q[], string fileName);

#endif

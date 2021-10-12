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
// Purpose: reads in a line of input from file stream
// Pre: file stream
// Post: True if the file is open, and reads in all input from file into a struct
//       False if the file is closed
bool read_File (struct Queue q[]);

#endif

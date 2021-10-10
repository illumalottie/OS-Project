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
  int id, priority;
  float arrival_time;
  float total_CPU_Burst;
};
  
#endif

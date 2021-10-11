// FILE: adt.cpp 
// Coder: J Yong
// Purpose: this can be deleted 
#include "adt.h"

//id arr burst priority
bool read_File (struct Queue q) {
  int i = 0;
  ifstream inFile("input"); 
  if (!inFile.is_open()) {
    return false;
  }
  while (!inFile.eof()) { //fig how to look for unfinished lines?
     inFile >> q[i].p_id;
     inFile >> q[i].arrival_time;
     inFile >> q[i].total_CPU_burst;
     inFile >> q[i].priority; 
     i++;
  }
  return true;
  inFile.close();
}

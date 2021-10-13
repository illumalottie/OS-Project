// FILE: redRobin.h
// Coder:
// Purpose:
//
#ifndef REDROBIN_H_INCLUDED
#define REDROBIN_H_INCLUDED

#include "adt.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;


int roundRobin(Queue colleciton, int quantum, int numberOfProcesses);
bool checkFinished (Queue collection, int numberOfProcesses);

#endif 

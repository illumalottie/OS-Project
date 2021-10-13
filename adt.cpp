// FILE: adt.cpp 
// Coder: J Yong + Lottie Maynard
// Purpose: this can be deleted 
#include "adt.h"
#include <fstream>
#include <string>

using namespace std;

int read_File (Queue q[], string fileName) {
	int processCnt = 0;
	ifstream getInput;
	getInput.open(fileName); 
	if (!getInput.is_open()) {
		cout << "Invalid file entered: defaulting to sched.in";
		getInput.open("sched.in");
  	}
	while (!getInput.eof()) {
		getInput >> q[processCnt].p_id;
		getInput >> q[processCnt].arrival_time;
		getInput >> q[processCnt].total_CPU_burst;
		getInput >> q[processCnt].priority; 
		processCnt++;
	}
	getInput.close();
	return processCnt;
}

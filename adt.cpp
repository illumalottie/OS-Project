// FILE: adt.cpp 
// Coder: J Yong + Lottie Maynard
// Purpose: this can be deleted 
#include "adt.h"
#include <fstream>
#include <string>

using namespace std;

//id arr burst priority
void read_File (Queue q[], string fileName) {
	int i = 0;
	ifstream getInput;
	getInput.open(fileName); 
	if (!getInput.is_open()) {
		cout << "Invalid file entered: defaulting to sched.in";
		getInput.open("sched.in");
  	}
	while (getInput) {
		getInput >> q[i].p_id;
		getInput >> q[i].arrival_time;
		getInput >> q[i].total_CPU_burst;
		getInput >> q[i].priority; 
		i++;
	}
	getInput.close();
}

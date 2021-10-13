// FILE: adt.cpp 
// Coder: J Yong + Lottie Maynard
// Purpose: this can be deleted 
#include "adt.h"
#include <fstream>
#include <string>

using namespace std;

int read_File (queue<Queue>& q, string fileName) {
	int processCnt = 0;
	Queue newProcess;
	ifstream getInput;
	getInput.open(fileName); 
	if (!getInput.is_open()) {
		cout << "Invalid file entered: defaulting to sched.in";
		getInput.open("sched.in");
  	}
	getInput >> newProcess.p_id;
	do {
		getInput >> newProcess.arrival_time;
		getInput >> newProcess.total_CPU_burst;
		getInput >> newProcess.priority;
		cout << endl << " BAM " << newProcess.p_id << " " << newProcess.arrival_time << endl;
		q.push(newProcess);
		processCnt++;
		getInput >> newProcess.p_id; //checks if there is a next line
	} while (!getInput.eof());
	getInput.close();
	return processCnt;
}

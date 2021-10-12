// FILE: adt.cpp 
// Coder: J Yong + Lottie Maynard
// Purpose: this can be deleted 
#include "adt.h"
#include <fstream>
#include <string>

using namespace std;

//id arr burst priority
bool read_File (Queue q[]) {
int i = 0;
ifstream getInput;
getInput.open("input.txt"); 
	if (!getInput) {
	cout << "IT FAILED";
		return false;
  	}
	while (getInput) { //fig how to look for unfinished lines?
				//^^ what do you mean - lottie
		getInput >> q[i].p_id;
		getInput >> q[i].arrival_time;
		getInput >> q[i].total_CPU_burst;
		getInput >> q[i].priority; 
		i++;
	}
getInput.close();
return true;
}

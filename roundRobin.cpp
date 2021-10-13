// FILE: redRobin.cpp
// Coder:
// Purpose: 
#include "redRobin.h"

// roundRobin - runs the roundRobin schedule
int roundRobin(Queue colleciton, int quantum, int numberOfProcesses){
	
	// wait be the time it running
	float wait = 0.0;
	int currentProcess = 0;
	int averageWaitTime = 0;
	// uses the chechFinished function to see if it needs to stop
	while (checkFinished(collection, numberOfProcesses){
		// checks if the roundrobin has made it to the end of the list
		if (currentProcess == numberOfProcesses+1){
			currentProcess = 0;
		}
		// checks if enough time has passed for a process to go through the sort based on the startTime
		if (wait >= collection[currentProcess].arrival_Time){
			// runs for the length of a quantum and updates a processes burst tmie left and the total wait time
			for(int i=0; i < quantum; i++){
				if (collection[currentProcess].total_CPU_Burst != 0.0){
					--collection[currentProcess].total_CPU_Burst;
					++wait;
				}
			}
			//calculates wait time for the process after its quatum 
			colleciton[currentProcess].wait_Time = colleciton[currentProcess].wait_Time + (wait - colleciton[currentProcess].startTime) - colleciton[currentProcess].timeStoped;
			colleciton.timeStoped = wait;
			
		}
		// updates wait if no processes can start yet
		else{
			++wait;
		}
		
		++currentProcess;
	}
	
	for (int i=0; i < numberOfProcesses; i++){
		averageWaitTime = averageWaitTime + colleciton[i].wait_time;
	}
	
	averageWaitTime = averageWaitTime / numberOfProcesses;
	
	return averageWaitTime;
}

// checkFinished - is used by the while loop to see if every process is finished
bool checkFinished (Queue collection, int numberOfProcesses) {
	
	int checkValue = 0;
	// loops based on the number of processes in the array and updates the checkValue if the BurstTime is 0
	for (int i = 0; i < numberOfProcesses; i++){
		if(colleciton[i].total_CPU_Burst == 0){
			++checkValue;
		}
		
	}
	
	if (checkValue == numberOfProcesses){
		return false;
	}
	
	return true;
} 

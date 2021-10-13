
// FILE: driver.cpp
// Coders: Group 3 - Joey Yong, Lottie Maynard, and Dan
// Purpose:
//
//////SIDE QUESTS:
////// (1)



#include <iostream>
#include <string>
#include "fcfs.h"
#include "sjf.h"
#include "priority.h"
#include "roundRobin.h"
#include "adt.h"

using namespace std;

//string charToString(int argc, char **argv, string com[]){
//	int i = 0;
//	while (--argc >= 0 && (*++argv)[0] != '-'){
//		com[i] = argv[0];
//		i++;
//}
//	return com[i];
	
//}



//PROMPT GIVEN DEFAULTS
	//strings convert?


//Queue g[100]; //maybe do the lexical definition he mentioned? thoughts? - lottie

//read_File(g);

//i can pass in an Queue array and it brings back all the info from the file
//below the couts are just tests to make sure it returns the right numbers - lottie


/////////HAVE NOT TESTED FLAGS
//flags
//	-- type
//	--preemptive
//	--quanta
//	--file
//	--verbose


int main(int argc, char **argv) {

string type = "FCFS";
bool preemptive = false;
bool verbose = false;
int quanta = 10;
string fileName = "sched.in";

string com[100];
int i = 0;
	while (--argc >= 0) { //IT WORKS 
		com[i] = argv[0];
		++argv;
		++i;
	}
	int count = 0;
	while (count != i){

	if(com[count] == "--type"){
		type = com[++count];
		//need check fo valid type
}
	else if(com[count] == "--preemptive"){
		preemptive = true;
}
	else if(com[count] == "--quanta"){
		quanta = stoi(com[count + 1]);
}
	else if(com[count] == "--file"){
		fileName = com[++count];
}
	else if(com[count] == "--verbose"){
		verbose = true;
}
	++count;
}	


return 0;
}

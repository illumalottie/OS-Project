// FILE: driver.cpp
// Coders: Group 3 - Joey Yong, Lottie Maynard, and Dan
// Purpose:
//
#include <iostream>
#include "fcfs.h"
#include "sjf.h"
#include "priority.h"
#include "redRobin.h"
#include "adt.h"

using namespace std;

int main(void) {
Queue g[100]; //maybe do the lexical definition he mentioned? thoughts? - lottie

read_File(g);

//i can pass in an Queue array and it brings back all the info from the file
//below the couts are just tests to make sure it returns the right numbers - lottie



cout << g[0].p_id << endl;
cout << g[1].p_id << endl;
return 0;
}

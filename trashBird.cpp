//FILE: trashBird.cpp
//#include <iostream>
//#include <deque>
//#include<math.h>
#include "roundRobin.h"
//using namespace std;


    //deque<int> burst;
    //burst.push_back(15);
    //burst.push_back(20);
    //burst.push_back(30);
void trashBird(deque<Queue>& q, int quanta) {
    deque<Queue> ready = q;
    deque<int> w; //more easier to push things than an array
    int time = 0, wait;
    float r;
    int increment, burst;
    int curr, totalWait = 0;

    while (!ready.empty()) {
        curr = ready.front();
        burst = curr.total_CPU_burst
        while (curr != 0) {
            //finds out how many cycles are needed before the process is finished
            //and the remainder to find the total time
            if (burst != quanta){
                r = (float)burst/(float)quanta;
                increment = (int)r;
            }
            else {
                increment = 0;
            }
            cout << endl << endl << "curr: " << curr << " remainder: " << r << " increment: " << increment << endl;
            for (int x = 0; x < increment; x++) {
                if (ready.size() != 1) {
                    for (int i = 0; i < ready.size(); i++) {
                        cout << endl << "Before: " << ready[i];
                        ready[i] = ready[i] - quanta;
                        cout << endl << "After: " << ready[i];
                    }
                }
                else { //only one process left
                }
            }
            if (ready.front() == 0) { //patch for an issue when the last proces for more than one increment
                ready.front() = 10;
                increment = increment - 1;
            }
            increment = increment * ready.size() * quanta;
            wait = time + increment;
            time = wait + ready.front();
            w.push_back(wait);
            cout << endl << "WAIT: " << w.back();
            curr = 0;
            cout << endl << "increment: " << increment << " wait: " << wait << " time: " << time;
        }
        ready.pop_front();
    }
    
    //adds all the wait times could also change q's waittimes
    for (int i = 0; i < q.size(); i++) {
       cout << endl << i << " " << w[i] << " ";
       totalWait = totalWait + w[i];
       cout << totalWait << endl;
    }
    int avg = totalWait/burst.size();
    cout << " AVG: " << avg << endl;
}

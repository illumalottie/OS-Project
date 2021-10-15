//FILE: trashBird.cpp
#include <iostream>
#include <deque>
#include<math.h>

using namespace std;

int main(void) {
    deque<int> burst;
    burst.push_back(15);
    burst.push_back(20);
    burst.push_back(30);

    deque<int> ready = burst;
    deque<int> w;
    int time = 0, wait;
    float r;
    int increment, quanta = 10;
    int curr, totalWait = 0;

    while (!ready.empty()) {
        curr = ready.front();
        while (curr != 0) {
            //finds out how many cycles are needed before the process is finished
            //and the remainder to find the total time
            if (curr != quanta){
                r = (float)curr/(float)quanta;
                increment = (int)r;
            }
            else {
                increment = 0;
            }
            cout << endl << endl << "curr: " << curr << " remainder: " << r << " increment: " << increment << endl;
            for (int x = 0; x < increment; x++) {
                for (int i = 0; i < ready.size(); i++) {
                    cout << endl << "Before: " << ready[i];
                    ready[i] = ready[i] - quanta;
                    cout << endl << "After: " << ready[i];
                }
            }
            if (ready.front() == 0) {
                ready.front() = 10;
                increment = 1;
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
    for (int i = 0; i < burst.size(); i++) {
       cout << endl << i << " " << w[i] << " ";
       totalWait = totalWait + w[i];
       cout << totalWait << endl;
    }
    int avg = totalWait/burst.size();
    cout << " AVG: " << avg << endl;
}

cpuScheduler : driver.o adt.o fcfs.o sjf.o priority.o roundRobin.o 
	g++ driver.o adt.o fcfs.o sjf.o priority.o roundRobin.o -o cpuScheduler 

driver.o : driver.cpp fcfs.cpp fcfs.h sjf.cpp sjf.h priority.cpp priority.h roundRobin.cpp roundRobin.h adt.cpp adt.h
	g++ -c driver.cpp

fcfs.o : fcfs.cpp fcfs.h
	g++ -c fcfs.cpp 

sjf.o : sjf.cpp sjf.h 
	g++ -c sjf.cpp 

priority.o : priority.cpp priority.h
	g++ -c priority.cpp 

roundRobin.o : roundRobin.cpp roundRobin.h
	g++ -c roundRobin.cpp 

adt.o : adt.cpp adt.h
	g++ -c adt.cpp

cpuScheduler : driver.o adt.o fcfs.o sjf.o priority.o redRobin.o adt.o 
	g++ driver.o adt.o fcfs.o sjf.o priority.o redRobin.o adt.o -o cpuScheduler 

driver.o : driver.cpp fcfs.cpp fcfs.h sjf.cpp sjf.h priority.cpp priority.h redRobin.cpp redRobin.h adt.cpp adt.h
	g++ -c driver.cpp

fcfs.o : fcfs.cpp fcfs.h adt.cpp adt.h
	g++ -c fcfs.cpp 

sjf.o : sjf.cpp sjf.h adt.cpp adt.h
	g++ -c sjf.cpp 

priority.o : priority.cpp priority.h adt.cpp adt.h
	g++ -c priority.cpp 

redRobin.o : redRobin.cpp redRobin.h adt.cpp adt.h
	g++ -c redRobin.cpp 

adt.o : adt.cpp adt.h
	g++ -c adt.cpp

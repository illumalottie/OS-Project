cpuScheduler : driver.o fcfs.o sjf.o priority.o redRobin.o
	g++ -o cpuScheduler driver.o fcfs.o sjf.o priority.o redRobin.o

driver.o : driver.cpp fcfs.h sjf.h priority.h redRobin.h adt.h
	g++ -c driver.cpp

fcfs.o : fcfs.cpp fcfs.h adt.h
	g++ -c fcfs.cpp 

sjf.o : sjf.cpp sjf.h adt.h
	g++ -c sjf.cpp 

priority.o : priority.cpp priority.h adt.h
	g++ -c priority.cpp 

redRobin.o : redRobin.cpp redRobin.h adt.h
	g++ -c redRobin.cpp 

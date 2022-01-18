/* Multi_thread.h */
#ifndef MT_H
#define MT_H
#include <iostream>
#include <fstream>
#include <thread>
#include <process.h>
#include <string>
#include "HeapPrioQ.h"
#include "SimParam.h"
using namespace std;

enum THREAD_FLAG {
	INITIALIZE,
	RUN, TERMINATE
};

typedef struct
{
	mutex* mtxThrdMon;
	int numGenData;
	int numProcData;
	int genData_Array[NUM_DATA];
	int procData_Array[NUM_DATA];
} ThreadMon;
typedef struct
{
	mutex* pCS_main;
	HeapPrioQueue<int>* pPriQ;
	int max_round;
	int targetNumData;
	int* pDataArray;
	ThreadMon* pThrdMon;
} ThreadParam;
void Thread_DataGen(ThreadParam* pParam);
void Thread_DataProc(ThreadParam* pParam);
#endif // !MT_H
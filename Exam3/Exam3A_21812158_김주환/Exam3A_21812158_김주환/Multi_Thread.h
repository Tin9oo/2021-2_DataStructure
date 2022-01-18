/* Multi_Thread.h */
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <thread>
#include <process.h>
#include <string>
#include "TA_CirQ.h"
#include "T_Array.h"
#include "SimParam.h"
using namespace std;
enum ROLE {
	EVENT_GENERATOR,
	EVENT_HANDLER
};
enum THREAD_FLAG {
	INITIALIZE,
	RUN, TERMINATE
};
typedef struct ThreadStatusMonitor
{
	int numGenData;
	int numProcData;
	int genDataArray[TOTAL_NUM_DATA]; // used for monitoring only
	int procDataArray[TOTAL_NUM_DATA]; // used for monitoring only
	THREAD_FLAG* pFlagThreadTerminate;
} ThreadStatusMonitor;
typedef struct
{
	mutex* pMTX_main;
	mutex* pMTX_thrd_mon;
	TA_CirQ<int>* pTA_CirQ;
	int myAddr;
	int maxRound;
	int targetGenData;
	int* dataList;
	ThreadStatusMonitor* pThrdMon;
} ThreadParam;
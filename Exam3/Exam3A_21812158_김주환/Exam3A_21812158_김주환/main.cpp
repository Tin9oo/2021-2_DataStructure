/* main.cpp */
/* Description
* 
* Programmed by J. H. Kim
* Last updated : 2021-11-20 */
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <thread>
#include <mutex>
#include "Multi_Thread.h"
#include "T_Array.h"
#include "TA_CirQ.h"
// #include "ConsoleDisplay.h"
#include "SimParam.h"
// #include <time.h>
#include <conio.h>
using namespace std;

#define ELEMENTS_PER_LINE 10
#define NUM_ELEMENTS_PER_ROUND 7
int dataList[TOTAL_NUM_DATA] = { 0, 1, 2, 3, 4, 14, 13, 12, 11, 10, 5, 6, 7, 8, 9, 19, 18, 17, 16, 15 };
void main()
{
	TA_CirQ<int, Event> heapPriQ_Event(30, string("HeapPriorityQueue_Event"));
	Event* pEvent, * pEv_min_elasped_time, * pEv_max_elapsed_time;
	int myAddr = 0;
	int pkt_event_handler_addr, eventPriority;
	ThreadParam_Event thrdParam_EventGen, thrdParam_EventHndlr;
	HANDLE hThrd_EventGenerator, hThrd_EventHandler;

	mutex cs_main; // 콘솔 출력에 대한 임계구역
	mutex cs_thrd_mon; // 공유자원 관리에 대한 임계구역

	ThreadStatusMonitor thrdMon;
	HANDLE consHndlr;
	THREAD_FLAG eventThreadFlag = RUN;
	int count, numEventGenerated, numEventProcessed;
	int num_events_in_PrioQ;
	TA_CirQ<int> TA_CirQ_int(QUEUE_SIZE, string("TA_CirQ of Integer"));
	
	/* Create and Activate Thread_EventHandler */
	thrdMon.numEventProcessed = 0;
	thrdParam_EventHndlr.role = EVENT_HANDLER;
	thrdParam_EventHndlr.myAddr = 1; // link address
	thrdParam_EventHndlr.pCS_main = &cs_main;
	thrdParam_EventHndlr.pCS_thrd_mon = &cs_thrd_mon;
	thrdParam_EventHndlr.pPriQ_Event = &heapPriQ_Event;
	thrdParam_EventHndlr.maxRound = MAX_ROUND;
	thrdParam_EventHndlr.QP_freq = QP_freq;
	thrdParam_EventHndlr.pThrdMon = &thrdMon;
	thread thrd_dataProc(Thread_DataProc, &thrdParam_procData);
	
	/* Create and Activate Thread_EventGen */
	thrdMon.numEventGenerated = 0;
	thrdParam_EventGen.role = EVENT_GENERATOR;
	thrdParam_EventGen.myAddr = 0; // my Address
	thrdParam_EventGen.pCS_main = &cs_main;
	thrdParam_EventGen.pCS_thrd_mon = &cs_thrd_mon;
	thrdParam_EventGen.pPriQ_Event = &heapPriQ_Event;
	thrdParam_EventGen.targetEventGen = NUM_EVENTS_PER_GEN;
	thrdParam_EventGen.maxRound = MAX_ROUND;
	thrdParam_EventGen.QP_freq = QP_freq;
	thrdParam_EventGen.pThrdMon = &thrdMon;
	thread thrd_EvGen(EventGen, &thrdParam_EventGen); // Event 생성 Thread 실행
	thread thrd_dataGen(Thread_DataGen, &thrdParam_genData);
	
	fout << "Testing " << TA_CirQ_int.getName() << endl;
	for (int i = 0; i < MAX_ROUNDS; i++)
	{
		mtx_main.lock();
		cout << "Round (" << setw(3) << i << ") : totalDataProcessed = " << setw(3)
			<< thrdMon.numProcData << endl;
		mtx_main.unlock();
		if (thrdMon.numProcData >= TOTAL_NUM_DATA)
		{
			thrd_flag = TERMINATE;
			break;
		}

		Sleep(100);
	}
	thrd_dataGen.join();
	thrd_dataProc.join();
	cout << "Number of generated data = " << thrdMon.numGenData << endl;
	cout << "GeneratedDataList =\n" << endl;
	for (int i = 0; i < TOTAL_NUM_DATA; i++)
	{
		cout << setw(3) << thrdMon.genDataArray[i];
	}
	cout << endl;
	cout << "Number of processed data = " << thrdMon.numProcData << endl;
	cout << "ProcessedDataList =\n" << endl;
	for (int i = 0; i < TOTAL_NUM_DATA; i++)
	{
		cout << setw(3) << thrdMon.procDataArray[i];
	}
	cout << endl;
}
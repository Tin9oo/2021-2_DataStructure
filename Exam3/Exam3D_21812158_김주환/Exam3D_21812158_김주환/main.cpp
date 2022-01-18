/* main.cpp */
/* Description
* Multi Thread Heap Priority Queue
* Programmed by J. H. Kim
* Last updated : 2021-11-20 */
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <thread>
#include <mutex>
#include "Multi_Thread.h"
#include "HeapPrioQ.h"
#include "SimParam.h"
#include <conio.h>

using namespace std; 
#define INITIAL_CBT_CAPA 100
int dataArray[NUM_DATA] = { 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
int main()
{
	HeapPrioQueue<int> heapPriQ_Event(30, string("HeapPriorityQueue_Event"));
	int* pEvent, * pEv_min_elasped_time, * pEv_max_elapsed_time;
	int myAddr = 0;
	int pkt_event_handler_addr, eventPriority;
	ThreadParam thrdParam_EventGen, thrdParam_EventHndlr;

	mutex cs_main; // 콘솔 출력에 대한 임계구역
	mutex cs_thrd_mon; // 공유자원 관리에 대한 임계구역

	ThreadMon thrdMon;
	THREAD_FLAG eventThreadFlag = RUN;
	int count, numEventGenerated, numEventProcessed;
	int num_events_in_PrioQ;
	int eventProcessed[NUM_DATA];
	
	HeapPrioQueue<int> HeapPriQ_int(INITIAL_CBT_CAPA, string("Heap_Priority_Queue_Int"));
	thrdMon.numGenData = thrdMon.numProcData = 0;

	/* Create and Activate Thread_DataProcessor */
	thrdMon.numProcData = 0;
	thrdParam_EventHndlr.pCS_main = &cs_main;
	thrdParam_EventHndlr.pPriQ = &heapPriQ_Event;
	thrdParam_EventHndlr.max_round = MAX_ROUND;
	thrdParam_EventHndlr.pThrdMon = &thrdMon;
	thrdParam_EventHndlr.pThrdMon->mtxThrdMon = &cs_thrd_mon; // ?
	thread thrd_DataProc(Thread_DataProc, &thrdParam_EventHndlr); // Event 처리 Thread 실행
	cs_main.lock();
	cout << "Thread_EventGen is created and activated ...\n";
	cs_main.unlock();

	/* Create and Activate Thread_DataGenerator */
	thrdMon.numGenData = 0;
	thrdParam_EventGen.pCS_main = &cs_main;
	thrdParam_EventGen.pPriQ = &heapPriQ_Event;
	thrdParam_EventGen.targetNumData = NUM_DATA; // ?
	thrdParam_EventGen.max_round = MAX_ROUND;
	thrdParam_EventGen.pThrdMon = &thrdMon;
	thrdParam_EventGen.pThrdMon->mtxThrdMon = &cs_thrd_mon;

	thread thrd_DataGen(Thread_DataGen, &thrdParam_EventGen); // Event 생성 Thread 실행
	cs_main.lock();
	cout << "Thread_EventGen is created and activated ...\n";
	cs_main.unlock();
	
	for (int round = 0; round < MAX_ROUND; round++)
		{
			if ((thrdMon.numGenData >= NUM_DATA) && (thrdMon.numProcData >= NUM_DATA))
				break;
			Sleep(100);
		}
	thrd_DataGen.join();
	cs_main.lock();
	cout << "Thread_DataGenerator is terminated !!" << endl;
	cs_main.unlock();
	thrd_DataProc.join();
	cs_main.lock();
	cout << "Thread_DataProcessor is terminated !!" << endl;
	cs_main.unlock();
	cout << "Generated data : ";
	for (int i = 0; i < NUM_DATA; i++)
	{
		cout << setw(3) << thrdMon.genData_Array[i];
	}
	cout << endl;
	cout << "Processed data : ";
	for (int i = 0; i < NUM_DATA; i++)
	{
		cout << setw(3) << thrdMon.procData_Array[i];
	}
	cout << endl;
	return 0;
} // end main();
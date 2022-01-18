/* main.cpp */
/* Description
* 멀티 스레드 구현
* 우선순위 Heap Queue 구현
* Programmed by J. H. Kim
* Last updated : 2021-11-05 */
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <thread>
#include <mutex>
#include "Multi_Thread.h"
#include "HeapPrioQ_CS.h"
#include "Event.h"
#include "ConsoleDisplay.h"
#include "SimParams.h"
#include <time.h>
#include <conio.h>
using namespace std;

void main() {
	// 시간 관련 변수
	LARGE_INTEGER QP_freq, t_before, t_after;
	LONGLONG t_diff;
	double elapsed_time, min_elapsed_time, max_elapsed_time;
	double avg_elapsed_time, total_elapsed_time;

	HeapPrioQ_CS<int, Event> heapPriQ_Event(30, string("HeapPriorityQueue_Event"));
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
	Event eventProcessed[TOTAL_NUM_EVENTS];

	consHndlr = initConsoleHandler();
	QueryPerformanceFrequency(&QP_freq); // 주파수
	srand(time(NULL));
	thrdMon.pFlagThreadTerminate = &eventThreadFlag;
	thrdMon.totalEventGenerated = 0;
	thrdMon.totalEventProcessed = 0;
	for (int ev = 0; ev < TOTAL_NUM_EVENTS; ev++) {
		thrdMon.eventProcessed[ev].setEventNo(-1); // mark as not-processed
		thrdMon.eventProcessed[ev].setEventPri(-1);
	}

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
	thread thrd_EvProc(EventProc, &thrdParam_EventHndlr); // Event 처리 Thread 실행
	cs_main.lock();
	printf("Thread_EventGen is created and activated ...\n");
	cs_main.unlock();

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
	cs_main.lock();
	printf("Thread_EventGen is created and activated ...\n");
	cs_main.unlock();

	/* periodic monitoring in main() */
	for (int round = 0; round < MAX_ROUND; round++) {
		cs_main.lock();
		cls(consHndlr);
		gotoxy(consHndlr, 0, 0);
		printf("Thread monitoring by main() ::\n");
		printf(" round(%2d): current total_event_gen (%2d), total_event_proc(%2d)\n",
			round, thrdMon.totalEventGenerated, thrdMon.totalEventProcessed);
		printf("\n*****************************\n");
		numEventGenerated = thrdMon.numEventGenerated;
		printf("Events generated (current total = %2d)\n ", numEventGenerated);
		count = 0;
		for (int ev = 0; ev < numEventGenerated; ev++) {
			pEvent = &thrdMon.eventGenerated[ev];
			if (pEvent != NULL) {
				cout << *pEvent << " ";
				if (((ev + 1) % EVENTS_PER_LINE) == 0)
					printf("\n ");
			}
		} //end for
		printf("\n");
		printf("\n*****************************\n");
		num_events_in_PrioQ = heapPriQ_Event.size();

		printf("Events currently in Priority_Queue (%d) : \n", num_events_in_PrioQ);
		heapPriQ_Event.fprint(cout);

		printf("\n\n*****************************\n");
		numEventProcessed = thrdMon.totalEventProcessed;
		printf("Events processed (current total = %d): \n ", numEventProcessed);
		count = 0;
		total_elapsed_time = 0.0;
		for (int ev = 0; ev < numEventProcessed; ev++) {
			pEvent = &thrdMon.eventProcessed[ev];
			if (pEvent != NULL) {
				pEvent->printEvent_proc();
				if (((ev + 1) % EVENTS_PER_LINE) == 0)
					printf("\n ");
			}
			if (ev == 0) {
				min_elapsed_time = max_elapsed_time = total_elapsed_time =
					pEvent->getEventElapsedTime(); // in milli-second
				pEv_min_elasped_time = pEv_max_elapsed_time = pEvent;
			}
			else {
				if (min_elapsed_time > pEvent->getEventElapsedTime()) {
					min_elapsed_time = pEvent->getEventElapsedTime(); // in milli-second
					pEv_min_elasped_time = pEvent;
				}
				if (max_elapsed_time < pEvent->getEventElapsedTime()) {
					max_elapsed_time = pEvent->getEventElapsedTime(); // in milli-second
					pEv_max_elapsed_time = pEvent;
				}
				total_elapsed_time += pEvent->getEventElapsedTime();
			}
		} //end for showing eventProcessed
		printf("\n");
		if (numEventProcessed > 0) {
			printf("numEventProcessed = %d\n", numEventProcessed);
			printf("min_elapsed_time = %8.2lf[ms]; ", min_elapsed_time);
			cout << *pEv_min_elasped_time << endl;
			printf("max_elapsed_time = %8.2lf[ms]; ", max_elapsed_time);
			cout << *pEv_max_elapsed_time << endl;
			avg_elapsed_time = total_elapsed_time / numEventProcessed;
			printf("avg_elapsed_time = %8.2lf[ms]; \n", avg_elapsed_time);
		}
		if (numEventProcessed >= TOTAL_NUM_EVENTS) {
			eventThreadFlag = TERMINATE; // set 1 to terminate threads
			cs_main.unlock();
			break;
		} //end if
		cs_main.unlock();
		Sleep(100);
	} //end for (int round = 0; ...)
	thrd_EvProc.join();
	thrd_EvGen.join();
	printf("Hit any key to terminate : ");
	_getch();
}
/* Thread_EventHandler.cpp */
#include <Windows.h>
#include "Multi_Thread.h"
#include "HeapPrioQ_CS.h"
#include "Event.h"
#include <mutex>
using namespace std;

using std::this_thread::sleep_for;
void EventProc(ThreadParam_Event* pParam) {
	// ����ü ����
	HeapPrioQ_CS<int, Event>* pPriQ_Event = pParam->pPriQ_Event;
	int myRole = pParam->role;
	int myAddr = pParam->myAddr;
	int maxRound = pParam->maxRound;
	int targetEventGen = pParam->targetEventGen;
	LARGE_INTEGER QP_freq = pParam->QP_freq;
	ThreadStatusMonitor* pThrdMon = pParam->pThrdMon;

	T_Entry<int, Event>* pEntry;
	Event event, * pEvent, * pEventProc;
	int event_no = 0;
	int eventPriority = 0;
	int event_gen_count = 0;
	int num_pkt_processed = 0;
	LARGE_INTEGER t_gen, t_proc; // event ó�� �ð�
	LONGLONG t_diff;
	double elapsed_time;

	for (int round = 0; round < maxRound; round++) {
		if (*pThrdMon->pFlagThreadTerminate == TERMINATE)
			break; // Thread ����

		// Queue�� �̺�Ʈ�� �ִ� ���
		if (!pPriQ_Event->isEmpty()) {
			pEntry = pPriQ_Event->removeHeapMin();
			event = pEntry->getValue();
			pParam->pCS_thrd_mon->lock(); // �����ڿ� ���� mutex
			event.setEventHandlerAddr(myAddr);
			QueryPerformanceCounter(&t_proc); // ó�� �ð� ����
			event.setEventProcTime(t_proc);
			t_gen = event.getEventGenTime(); // ���� �ð� �ҷ�����
			t_diff = t_proc.QuadPart - t_gen.QuadPart; // ���� �ð� - ó�� �ð�
			elapsed_time = ((double)t_diff / QP_freq.QuadPart); // in second
			event.setEventElaspsedTime(elapsed_time * 1000); // in milli-second
			pThrdMon->eventProcessed[pThrdMon->totalEventProcessed] = event;
			pThrdMon->numEventProcessed++;
			pThrdMon->totalEventProcessed++;
			pParam->pCS_thrd_mon->unlock();
		} // end if
		sleep_for(std::chrono::milliseconds(100 + rand() % 100));
	} // end for
}
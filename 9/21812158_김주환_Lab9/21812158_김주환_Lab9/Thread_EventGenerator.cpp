/* Thread_EventGenerator.cpp */
#include <Windows.h>
#include "Multi_Thread.h"
#include "HeapPrioQ_CS.h"
#include "Event.h"
#include "SimParams.h"
using namespace std;
using std::this_thread::sleep_for;
void EventGen(ThreadParam_Event* pParam) {
	// 구조체 변수 가져옴
	HeapPrioQ_CS<int, Event>* pPriQ_Event = pParam->pPriQ_Event;
	int myRole = pParam->role;
	int myAddr = pParam->myAddr;
	int maxRound = pParam->maxRound;
	int targetEventGen = pParam->targetEventGen;
	LARGE_INTEGER QP_freq = pParam->QP_freq;
	ThreadStatusMonitor* pThrdMon = pParam->pThrdMon;

	T_Entry<int, Event>* pEntry, entry_event;
	Event event, * pEvent;
	int event_no = 0;
	int event_priority = 0;
	int event_gen_count = 0;
	int event_handler_addr;
	LARGE_INTEGER t_gen; // 이벤트 생성 시간

	for (int round = 0; round < maxRound; round++) {
		if (event_gen_count >= targetEventGen) {
			if (*pThrdMon->pFlagThreadTerminate == TERMINATE)
				break; // Thread 종료
			else {
				sleep_for(std::chrono::milliseconds(500));
				continue;
			}
		}
		
		// Event 초기화
		event_no = event_gen_count + NUM_EVENTS_PER_GEN * myAddr;
		event_priority = targetEventGen - event_gen_count - 1;
		event.setEventNo(event_no);
		event.setEventPri(event_priority);
		event.setEventGenAddr(myAddr);
		event.setEventHandlerAddr(-1); // event handler is not defined yet !!
		QueryPerformanceCounter(&t_gen); // 시간 측정
		event.setEventGenTime(t_gen);
		event.setEventStatus(GENERATED);

		// T_Entry 초기화
		entry_event.setKey(event.getEventPri());
		entry_event.setValue(event);

		// 삽입을 실패한 경우
		while (pPriQ_Event->insert(entry_event) == NULL) {
			pParam->pCS_main->lock(); // 콘솔 출력 관련 mutex
			cout << "PriQ_Event is Full, waiting ..." << endl;
			pParam->pCS_main->unlock();
			sleep_for(std::chrono::milliseconds(100));
		}
		pParam->pCS_main->lock(); // 콘솔 출력 관련 mutex
		cout << "Successfully inserted into PriQ_Event " << endl;
		pParam->pCS_main->unlock();
		pParam->pCS_thrd_mon->lock(); // 공유자원 관련 mutex
		pThrdMon->eventGenerated[pThrdMon->totalEventGenerated] = event;
		pThrdMon->numEventGenerated++;
		pThrdMon->totalEventGenerated++;
		pParam->pCS_thrd_mon->unlock();
		event_gen_count++;
		//Sleep(100 + rand() % 300);
		sleep_for(std::chrono::milliseconds(10));
	}
}
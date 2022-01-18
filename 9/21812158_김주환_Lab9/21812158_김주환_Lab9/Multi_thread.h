/* Multi_thread.h */
#ifndef MULTI_THREAD_H
#define MULTI_THREAD_H
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <thread>
#include <process.h>
#include <string>
#include "HeapPrioQ_CS.h"
#include "Event.h"
#include "SimParams.h"
using namespace std;
enum ROLE {
	EVENT_GENERATOR,
	EVENT_HANDLER
};
enum THREAD_FLAG {
	INITIALIZE,
	RUN, TERMINATE
};

// 모니터링 관련 구조체
typedef struct ThreadStatusMonitor {
	int numEventGenerated; // 생성 이벤트 수
	int numEventProcessed; // 처리 이벤트 수
	int totalEventGenerated; // 총 생성 이벤트 수
	int totalEventProcessed; // 총 처리 이벤트 수
	// used for monitoring only
	Event eventGenerated[TOTAL_NUM_EVENTS]; // 생성된 이벤트
	Event eventProcessed[TOTAL_NUM_EVENTS]; // 처리된 이벤트
	THREAD_FLAG* pFlagThreadTerminate; // Thread 실행 여부 결정
} ThreadStatusMonitor;

// Thread에 전달되는 파라메터 관련 구조체
typedef struct ThreadParam {
	mutex* pCS_main; // 콘솔 출력 mutex
	mutex* pCS_thrd_mon; // 공유자원 관리에 대한 mutex

	HeapPrioQ_CS<int, Event>* pPriQ_Event; // Heap Priority Queue의 포인터

	FILE* fout;
	ROLE role;
	int myAddr; // Thread 주소
	int maxRound;
	int targetEventGen; // 이벤트를 얼마나 생성할지 결정
	LARGE_INTEGER QP_freq; // used in measurements
	ThreadStatusMonitor* pThrdMon; // 모니터링
} ThreadParam_Event;

void EventGen(ThreadParam_Event* pParam);
void EventProc(ThreadParam_Event* pParam);
#endif
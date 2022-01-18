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

// ����͸� ���� ����ü
typedef struct ThreadStatusMonitor {
	int numEventGenerated; // ���� �̺�Ʈ ��
	int numEventProcessed; // ó�� �̺�Ʈ ��
	int totalEventGenerated; // �� ���� �̺�Ʈ ��
	int totalEventProcessed; // �� ó�� �̺�Ʈ ��
	// used for monitoring only
	Event eventGenerated[TOTAL_NUM_EVENTS]; // ������ �̺�Ʈ
	Event eventProcessed[TOTAL_NUM_EVENTS]; // ó���� �̺�Ʈ
	THREAD_FLAG* pFlagThreadTerminate; // Thread ���� ���� ����
} ThreadStatusMonitor;

// Thread�� ���޵Ǵ� �Ķ���� ���� ����ü
typedef struct ThreadParam {
	mutex* pCS_main; // �ܼ� ��� mutex
	mutex* pCS_thrd_mon; // �����ڿ� ������ ���� mutex

	HeapPrioQ_CS<int, Event>* pPriQ_Event; // Heap Priority Queue�� ������

	FILE* fout;
	ROLE role;
	int myAddr; // Thread �ּ�
	int maxRound;
	int targetEventGen; // �̺�Ʈ�� �󸶳� �������� ����
	LARGE_INTEGER QP_freq; // used in measurements
	ThreadStatusMonitor* pThrdMon; // ����͸�
} ThreadParam_Event;

void EventGen(ThreadParam_Event* pParam);
void EventProc(ThreadParam_Event* pParam);
#endif
/* Thread_DataProc.cpp */
#include <Windows.h>
#include "Multi_Thread.h"
#include "TA_CirQ.h"
#include <mutex>
using namespace std; 

void Thread_DataProc(ThreadParam* pParam)
{
	TA_CirQ<int>* pTA_CirQ = pParam->pTA_CirQ;
	int myAddr = pParam->myAddr;
	int maxRound = pParam->maxRound;
	int targetGenData = pParam->targetGenData;
	ThreadStatusMonitor* pThrdMon = pParam->pThrdMon;
	int* pDeQ_data;
	int deQ_data;
	pParam->pMTX_main->lock();
	cout << "Thread_DataProc is activated now ..." << endl;
	pParam->pMTX_main->unlock();
	for (int round = 0; round < maxRound; round++)
	{
		if (*pThrdMon->pFlagThreadTerminate == TERMINATE)
			break;

		// Queue에 이벤트가 있는 경우
		if (!pTA_CirQ->isEmpty()) {
			pDeQ_data = pTA_CirQ->dequeue();
			deQ_data = *pDeQ_data;
			pParam->pMTX_thrd_mon->lock(); // 공유자원 관련 mutex
			pThrdMon->procDataArray[pThrdMon->numProcData] = deQ_data;
			pThrdMon->numProcData++;
			pParam->pMTX_thrd_mon->unlock();
		} // end if
		
		Sleep(50 + rand() % 50);
	} // end for
}
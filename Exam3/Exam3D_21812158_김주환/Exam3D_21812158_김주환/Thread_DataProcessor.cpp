/* Thread_DataProcessor.cpp */
#include <Windows.h>
#include <mutex>
#include "Multi_Thread.h"
#include "HeapPrioQ.h"
#define THREAD_EXIT_CODE 0
void Thread_DataProc(ThreadParam * pParam)
{
	HeapPrioQueue<int>* pPriQ = pParam->pPriQ;
	mutex* pCS_main = pParam->pCS_main;
	int maxRound = pParam->max_round;
	int target_num_data = pParam->targetNumData;
	ThreadMon* pThrdMon = pParam->pThrdMon;

	int* pData_proc;
	
	pCS_main->lock();
	cout << "Thread_DataProc is activated now !!" << endl;
	pCS_main->unlock();
	for (int round = 0; round < maxRound; round++)
	{
		if (pThrdMon->numProcData >= target_num_data)
			break;
		if (!pPriQ->isEmpty())
		{
			pData_proc = pPriQ->removeHeapMin();
			if (pData_proc == NULL)
			{
				pCS_main->lock();
				cout << "Thread_DataProc:: removeHeapMin () ==> HeapPrioQ is Empty Now" << endl;
				pCS_main->unlock();
			}
			else
			{
				pCS_main->lock();
				cout << "Thread_DataProc:: removeHeapMin (" << setw(3) << *pData_proc << ")" << endl;
				pCS_main->unlock();
				pThrdMon->mtxThrdMon->lock();
				pThrdMon->procData_Array[pThrdMon->numProcData] = *pData_proc;
				pThrdMon->numProcData++;
				pThrdMon->mtxThrdMon->unlock();
			}
		} // end if
		Sleep(100);
	} // end for
}
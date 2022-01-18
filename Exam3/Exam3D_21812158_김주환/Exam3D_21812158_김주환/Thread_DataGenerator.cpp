/* Thread_DataGenenerator.cpp */
#include <Windows.h>
#include <mutex>
#include "HeapPrioQ.h"
#include "Multi_Thread.h"

#define THREAD_EXIT_CODE 0
void Thread_DataGen(ThreadParam* pParam)
{
	HeapPrioQueue<int>* pPriQ = pParam->pPriQ;
	mutex* pCS_main = pParam->pCS_main;
	int maxRound = pParam->max_round;
	int targetNumData = pParam->targetNumData;
	ThreadMon* pThrdMon = pParam->pThrdMon;

	int genData;
	int* pTxData_Array = pParam->pDataArray;

	
	pCS_main->lock();
	cout << "Thread_DataGen is activated now !!" << endl;
	pCS_main->unlock();
	for (int round = 0; round < maxRound; round++)
	{
		if (pThrdMon->numGenData >= targetNumData)
		{
			break;
		}
		genData = pTxData_Array[pThrdMon->numGenData];
		while (pPriQ->insert(genData) == NULL)
		{
			Sleep(50);
		}
		pCS_main->lock();
		cout << "Thread_DataGen:: insert (" << setw(3) << genData << ")" << endl;
		pCS_main->unlock();
		pThrdMon->mtxThrdMon->lock();
		pParam->pThrdMon->genData_Array[pParam->pThrdMon->numGenData] = genData;
		pParam->pThrdMon->numGenData++;
		pThrdMon->mtxThrdMon->unlock();
		Sleep(10);
	}
}
/* Thread_DataGen.cpp */
#include <Windows.h>
#include "Multi_Thread.h"
#include "TA_CirQ.h"
#include "SimParam.h"
using namespace std; 
using std::this_thread::sleep_for;
void Thread_DataGen(ThreadParam* pParam)
{
	TA_CirQ<int>* pTA_CirQ = pParam->pTA_CirQ;
	int myAddr = pParam->myAddr;
	int maxRound = pParam->maxRound;
	int targetGenData = pParam->targetGenData;
	ThreadStatusMonitor* pThrdMon = pParam->pThrdMon;
	int* pDeQ_data;
	int genData;
	pParam->pMTX_main->lock();
	cout << "Thread_DataGen is activated now ..." << endl;
	pParam->pMTX_main->unlock();
	for (int round = 0; round < maxRound; round++)
	{
		if (pThrdMon->numGenData >= targetGenData)
		{
			if (*pThrdMon->pFlagThreadTerminate == TERMINATE)
				break;
			else {
				sleep_for(std::chrono::milliseconds(500));
				continue;
			}
		}
		genData = pParam->dataList[pThrdMon->numGenData];
		pTA_CirQ->enqueue(genData);
		pParam->pMTX_thrd_mon->lock();
		pThrdMon->genDataArray[pThrdMon->numGenData] = genData;
		pThrdMon->numGenData++;
		pParam->pMTX_thrd_mon->unlock();
		Sleep(50 + rand() % 50);
	}
}
/* Evemt.h */
#ifndef E_H
#define E_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

enum EventStatus { GENERATED, ENQUEUED, PROCESSED, UNDEFINED };
#define MAX_EVENT_PRIORITY 100
#define NUM_EVENT_GENERATORS 10

class Event {
	friend ostream& operator<<(ostream& fout, const Event& e);
public:
	Event();
	Event(int event_id, int event_pri, string title, int gen_addr);
	void printEvent(ostream& fout);
	void setEventHandlerAddr(int evtHndlerAddr) { event_handler_addr = evtHndlerAddr; }
	void setEventGendAddr(int genAddr) { event_gen_addr = genAddr; }
	void setEventNo(int evtNo) { event_no = evtNo; }
	void setEventPri(int pri) { event_pri = pri; }
	void setEventStatus(EventStatus evtStatus) { eventStatus = evtStatus; }
	int getEventPri() { return event_pri; }
	int getEventNo() { return event_no; }
	bool operator>(Event& e) { return (event_pri > e.event_pri); }
	bool operator<(Event& e) { return (event_pri < e.event_pri); }
private:
	int event_no;
	string event_title;
	int event_gen_addr;
	int event_handler_addr;
	int event_pri;
	EventStatus eventStatus;
};

Event* genRandEvent(int evt_no);
#endif // !E_H

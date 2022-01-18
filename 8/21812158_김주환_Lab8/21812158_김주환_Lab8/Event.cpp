/* Event.cpp */
#include "Event.h"

Event::Event() {
	
}
Event::Event(int evt_id, int evt_pri, string title, int evtGenAddr) {
	event_no = evt_id;
	event_gen_addr = evtGenAddr;
	event_handler_addr = -1; // event handler is not defined at this moment
	event_pri = evt_pri; // event_priority
	event_title = title;
	eventStatus = GENERATED;
}
Event* genRandEvent(int evt_no)
{
	Event* pEv;
	int evt_prio;
	string title = " ";
	int evt_generator_id;
	evt_prio = rand() % MAX_EVENT_PRIORITY;
	evt_generator_id = rand() % NUM_EVENT_GENERATORS;
	pEv = (Event*) new Event(evt_no, evt_prio, title, evt_generator_id);
	return pEv;
}
void Event::printEvent(ostream& fout)
{
	fout << "Event(no:" << setw(3) << event_no << ", pri:" << setw(3) << event_pri;
	fout << ", gen:" << setw(3) << event_gen_addr << ", title:" << setw(3) << event_title << ")";
}
ostream& operator<<(ostream& fout, const Event& evt)
{
	fout << "Event(no:" << setw(3) << evt.event_no << ", pri:" << setw(3) << evt.event_pri;
	fout << ", gen:" << setw(3) << evt.event_gen_addr << ", title:" << setw(3) << evt.event_title << ")";
	return fout;
}
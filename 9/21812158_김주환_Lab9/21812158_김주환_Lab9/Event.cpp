/* Event.cpp */
#include "Event.h"
Event::Event() {
	event_no = 0;
	event_gen_addr = 0;
	event_handler_addr = -1; // event handler is not defined at this moment
	event_pri = 0; // event_priority
	eventStatus = GENERATED;
}
Event::Event(int evt_no, int evt_pri, int evtGenAddr) {
	event_no = evt_no;
	event_gen_addr = evtGenAddr;
	event_handler_addr = -1; // event handler is not defined at this moment
	event_pri = evt_pri; // event_priority
	eventStatus = GENERATED;
}
Event* genRandEvent(int evt_no) {
	Event* pEv;
	int evt_prio;
	int evt_generator_id;
	evt_prio = rand() % MAX_EVENT_PRIORITY;
	evt_generator_id = rand() % NUM_EVENT_GENERATORS;
	pEv = new Event(evt_no, evt_prio, evt_generator_id);
	return pEv;
}
void Event::printEvent_proc() {
	cout << "Ev(no:" << setw(2) << event_no << ", pri:" << setw(2) << event_pri;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << ", t_elapsed:" << setw(8) << t_elapsed_time_ms << ") ";
}
ostream& operator<<(ostream& fout, const Event& evt) {
	fout << "Ev(no:" << setw(3) << evt.event_no;
	fout << ", pri:" << setw(3) << evt.event_pri << ")";
	return fout;
}

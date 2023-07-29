#include <iostream>
#include <string>
#include <queue>
#include "funcs.h"
using namespace std;

//multi-level priority queue scheduling system.
int main()
{
	queue<int> p1;
	queue<int> p2;
	queue<int> p3;
	bool running = true;
	
	while (running) {

		cout << "----------------------------------------" << endl;
		int menuChoice = menu();
		int priority;
		int burstTime;
		int x;
		int c;

		//menu choice will be handled with switch statement
		switch (menuChoice) {

		case 1://add element

			priority = setPriority();
			burstTime = setBurstTime();

			//switch case-ception
			switch (priority) {
			case 1:
				p1.push(burstTime);
				break;
			case 2:
				p2.push(burstTime);
				break;
			case 3:
				p3.push(burstTime);
				break;
			}
			break;

		case 2://remove front element (this manually removes front element from a queue)
			//switch case-ception
			priority = setPriority();
			switch (priority) {
			case 1:
				p1.pop();
				break;
			case 2:
				p2.pop();
				break;
			case 3:
				p3.pop();
				break;
			}
			break;

		case 3://display queue (display all queues)
			display(p1, p2, p3);
			break;
		case 4://run system with specified method (c) for specified amount of time (x)
			c = setMethod();
			x = setRunTime();
			run(p1, p2, p3, x, c);
			break;
		case 5://help menu
			help();
			break;
		case 6: //quit program
			running = false;
			break;
		}
	}
}




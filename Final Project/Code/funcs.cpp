#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>
#include <time.h>
#include <windows.h>



using namespace std;

void display(queue<int> p1, queue<int> p2, queue<int> p3) {

	cout << "---------------------------------" << endl;
	cout << "Priority Queue One: " << endl;
	while (!p1.empty()) {
		cout << p1.front() << " ";
		p1.pop();
	}
	cout << "\nPriority Queue Two: " << endl;
	while (!p2.empty()) {
		cout << p2.front() << " ";
		p2.pop();
	}
	cout << "\nPriority Queue Three: " << endl;
	while (!p3.empty()) {
		cout << p3.front() << " ";
		p3.pop();
	}
	cout << "\n---------------------------------" << endl;
}

void run(queue<int>& p1, queue<int>& p2, queue<int>& p3, int x, int runType) {

	if (p1.empty() && p2.empty() && p3.empty()) {
		cout << "\nAll queues are empty" << endl;
	}
	else {
		display(p1, p2, p3);
		Sleep(2000);
	}

	if (runType == 1) {
		//in this version, we will run priority queue 1 until empty, then move on to the others
		while (!p1.empty() && x > 0) {
			//this catches when the front element still has burst time left, if so, decrease by one
			//and display again
			if (p1.front() > 0) {
				p1.front() -= 1;
				display(p1, p2, p3);
				Sleep(2000);
				x--;
			}
			//once the front element has no burst time left, remove it from the queue
			else if (p1.front() == 0) {
				p1.pop();;
			}
		}
		//one p1 is empty, move on to p2
		while (!p2.empty() && x > 0) {

			if (p2.front() > 0) {
				p2.front() -= 1;
				display(p1, p2, p3);
				Sleep(2000);
				x--;
			}
			//once the front element has no burst time left, remove it from the queue
			else if (p2.front() == 0) {
				p2.pop();
			}
		}
		//finally, move to p3 once everything else is empty
		while (!p3.empty() && x > 0) {

			if (p3.front() > 0) {
				display(p1, p2, p3);
				p3.front() -= 1;
				Sleep(2000);
				x--;
			}
			//once the front element has no burst time left, remove it from the queue
			else if (p3.front() == 0) {
				p3.pop();
			}
		}
	}
	else if (runType == 2) {
		//handle the time slicing
		int p1Time = x / 2;
		x -= p1Time;

		int p3Time = x / 2;
		x -= p3Time;

		int p2Time = x;

		//in this method, we try to divide the run time equally between queues,
		//50% goes to the first queue, 25% in the second and third queue
		//division is not always perfect, but we never go over or under the given runtime
		while (!p1.empty() && p1Time > 0) {
			//this catches when the front element still has burst time left, if so, decrease by one
			//and display again
			if (p1.front() > 0) {
				p1.front() -= 1;
				display(p1, p2, p3);
				Sleep(2000);
				p1Time--;
			}
			//once the front element has no burst time left, remove it from the queue
			else if (p1.front() == 0) {
				p1.pop();;
			}
		}
		//one p1 is empty, move on to p2
		while (!p2.empty() && p2Time > 0) {

			if (p2.front() > 0) {
				p2.front() -= 1;
				display(p1, p2, p3);
				Sleep(2000);
				p2Time--;
			}
			//once the front element has no burst time left, remove it from the queue
			else if (p2.front() == 0) {
				p2.pop();
			}
		}
		//finally, move to p3 once everything else is empty
		while (!p3.empty() && p3Time > 0) {

			if (p3.front() > 0) {
				p3.front() -= 1;
				display(p1, p2, p3);
				Sleep(2000);
				p3Time--;
			}
			//once the front element has no burst time left, remove it from the queue
			else if (p3.front() == 0) {
				p3.pop();
			}
		}
	}
}

int menu() {

	int userInput;
	bool running = true;

	while (running) {
		cout << "Menu: " << endl;
		cout << "  1 - Add process\n  2 - remove process\n  3 - Display queue\n"
			<< "  4 - Run Queue\n  5 - Help menu\n  6 - Quit program"
			<< "\nEnter selection: ";

		cin >> userInput;
		if (userInput <= 6 && userInput >= 1) {
			return userInput;
		}
		else {
			cout << "Invalid input" << endl;
			running = true;
		}
	}
}

void help() {

	int userInput;


	cout << "\nWhat do you need help with?" << endl;
	cout << "  1 - Help adding process\n  2 - Help deleting process" <<
		"\n  3 - Help display queues\n  4 - Help run queue\n  5 - Help with run method type";
	cout << "\nEnter Selection: ";
	cin >> userInput;

	if (userInput < 6 && userInput > 0) {
		switch (userInput) {
		case 1:
			cout << "To add an process to a queue, first enter the 'add process' option"
				<< "\nfrom the menu. You will be prompted to enter two things, the queue"
				<< "\nthat you want to enter (1, 2, or 3 with 1 being highest and 3 being lowest),"
				<< "\nand the burst time for that process (the amount of"
				<< "\ncycles until process competion)\n";
			break;
		case 2:
			cout << "\nThe 'delete process' option will remove the front process from the"
				<< "\nspecified queue. To delete a process, choose the option from the menu"
				<< "\nand enter the queue whose front element you wish to remove\n";
			break;
		case 3:
			cout << "\nTo display all queues, choose the 'display queue' option from the"
				<< "\nmenu\n";
			break;
		case 4:
			cout << "\nTo start running the process in the queues, choose the 'run queue'"
				<< "\noption from the menu. You will be prompted to enter the method type"
				<< "\nand run time\n";
			break;
		case 5:
			cout << "\nThere are two methods in which the scheduling is handled,"
				<< "\nthe first method, the fixed priority preemptive scheduling method,"
				<< "\nworks by clearing the highest priority queue first and working down."
				<< "\nin this method, the first queue must be empty before moving down."
				<< "\nThe second method, the time slicing method, divides the runtime between"
				<< "\nthe three queues. The first queue gets about half of the runtime,"
				<< "\nthe second and third queue get about a quarter each\n";
			break;
		}
	}
}

int setPriority() {

	bool running = true;

	while (running) {
		string userInput;
		cout << endl << "Select a queue to enter (1,2,or 3): ";
		cin >> userInput;
		if (userInput == "1") {
			return 1;
		}
		else if (userInput == "2") {
			return 2;
		}
		else if (userInput == "3") {
			return 3;
		}
		else {
			cout << "Invalid input" << endl;
			running = true;
		}
	}
}

int setBurstTime() {

	bool running = true;

	while (running) {
		int userInput;
		//im limiting cpu burst time for the sake of program complexity
		cout << endl << "Enter Cpu Burst time (1-9): ";
		cin >> userInput;
		//make sure the input is within our acceptable range
		if (userInput < 10 && userInput > 0) {
			return userInput;
		}
		//if not, notify user and loop until we get valid input
		else {
			cout << "Invalid input" << endl;
			running = true;
		}
	}
}

int setMethod() {

	int x;
	bool running = true;

	while (running) {
		cout << "Different Method Types: \n  1 - Fixed Priority Scheduling Method\n  2 - Time Slicing Method" << endl;
		cout << "Enter Selection: ";
		cin >> x;
		if (x < 3 && x > 0) {
			running = false;
			return x;
		}
		else {
			cout << "\nInvalid Input" << endl;
			running = true;
		}
	}
}

int setRunTime() {
	int x;
	bool running = true;

	while (running) {
		cout << "Enter Run Time (1-99): " << endl;
		cin >> x;
		if (x < 100 && x > 0) {
			running = false;
			return x;
		}
		else {
			cout << "\nInvalid Input" << endl;
			running = true;
		}
	}
}

#include <iostream>
#include <sstream>
#include <fstream>
#include <array>
#include <vector>
using namespace std;


int j = 0;

void readfile(string fileName, int intArray[99]) {

	string inRec;
	string tempNum;

	//open the files
	ifstream inFile(fileName);

	//check if files are open
	if (!inFile.is_open()) {
		cout << "File failed to open" << endl;
	}

	//loops through the file, saving the ints to a vector of ints
	
	while (getline(inFile, tempNum)) {
		//stoi() converts the string to int, since getline() wont work with ints
		intArray[j] = (stoi(tempNum));
		j++;
	}
}

void checkValue(int intArray[]) {

	int integer;
	
	//gets a value from the user to check for
	cout << "Enter an integer to search for: ";
	cin >> integer;

	//loops through the array until value is found
	for (int i = 0; i < sizeof(intArray) + 1; i++) {
		if (intArray[i] == integer) {
			//reports to the user once value is found
			cout << "Number was found at index " << i << endl;
		}
	}

}

void changeValue(int intArray[]) {

	int integer, index;

	//gets a value from the user to change 
	cout << "Enter an index to change: ";
	cin >> index;

	//gets an integer value that the user wants in place of current value
	cout << "Enter an integer you want to replace the current one: ";
	cin >> integer;

	//displays the new and old value to the user
	cout << "The old number at index " << index << " was " << intArray[index] << ".\nThe new number is " <<
		integer << ". " << endl;

	//changes the value in the array
	intArray[index] = integer;

}


void addValue(int intArray[]) {

	int integer;
	int i;
	int num;
	int newArray[99] = {};
	
	//gets a value that user wants to add to array
	cout << "Enter an integer to add to the array: ";
	cin >> integer;

	//adds user value to the array
	
	cout << "Your array is: " << endl;

	for (i = 0; i <= sizeof(intArray); i++) {
		num = intArray[i];
		newArray[i] = num;
	}
	newArray[i] = integer;
	

	for (int i = 0; i <= sizeof(intArray) + 1; i++) {
		cout << newArray[i] << endl;
	}



	cout << endl;
}

void removeValue(int intArray[]) {

	int index;

	//gets an index value the user wants removed from array
	cout << "Enter an index to remove: ";
	cin >> index;

	//replaces the integer at that index with a zero
	intArray[index] = 0;
	

}

void printArray(int intArray[99]) {
	
	cout << "Your array is: " << endl;

	for (int i = 0; i <= sizeof(intArray); i++) {
		cout << intArray[i] << endl;
	}
	
	
}
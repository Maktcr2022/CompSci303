//Homework1.cpp

#include <iostream>
#include "functions1.h"
using namespace std;

int main()
{
    //TODO : swap all vector related stuff to arrays, comment out as you go
    
    int intArray[99] = {};
    readfile("ints.txt", intArray);
    printArray(intArray);

    addValue(intArray);

    changeValue(intArray);
    printArray(intArray);
    
    removeValue(intArray);
    printArray(intArray);

    checkValue(intArray);
    
}


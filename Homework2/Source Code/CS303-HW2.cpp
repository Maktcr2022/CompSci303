// CS303-HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "functionsHW2.h"
#include "employee.h"
#include "nonprof.h"
#include "prof.h"

int main()
{
    
    NonProfessional Tom;
    Tom.setWR(Tom.calculateWR());
    cout << "Employee's weelky rate is: $" << Tom.getWR() << endl << endl;

    Tom.setVH(Tom.calculateVH());
    cout << "Employee's total Vacation Hours are: " << Tom.getVH() << endl << endl;

    Tom.setHI(Tom.calculateHI());
    cout << "Employee's total Health Insurance contribution is: " << Tom.getHI() << endl << endl;


    Professional Harry;
    Harry.setVH(25);
    Harry.setWR(Harry.calculateWR());
    cout << "Employee's weelky rate is: $" << Harry.getWR() << endl << endl;

    Harry.setVH(Harry.calculateVH());
    cout << "Employee's total Vacation Hours are: " << Harry.getVH() << endl << endl;
    
    Harry.setHI(Harry.calculateHI());
    cout << "Employee's total Health Insurance contribution is: " << Harry.getHI() << endl << endl;
    


    
    //vector<int> intVector;
    //readfile("inputFile.txt", intVector);

    //addValue(intVector);
    //printArray(intVector);

    //changeValue(intVector);
    //printArray(intVector);
    
    
}


#pragma once
#include <iostream>
#include "employee.h"
using namespace std;

class Professional : public Employee {

public:
	float calculateWeeklyRate() const;
	float calculateVacationHours() const;
	float calculateHealthInsurance() const;

};

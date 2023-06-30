#pragma once
#include <iostream>
#include "employee.h"
using namespace std;


class NonProfessional : public Employee {

public:

	float calculateWeeklyRate() const;
	float calculateVacationHours() const;
	float calculateHealthInsurance() const;

};
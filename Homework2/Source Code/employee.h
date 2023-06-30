#pragma once
#include <iostream>
using namespace std;

class Employee {
private:
	int weeklyRate;
	int vacationHours;
	int healthInsurance;

public:
	Employee();

	virtual float calculateWeeklyRate() const = 0;
	virtual float calculateVacationHours() const = 0;
	virtual float calculateHealthInsurance() const = 0;

	int getWeeklyRate() const;
	int getVacationHours() const;
	int getHealthInsurance() const;

	void setWeeklyRate(int);
	void setVacationHours(int);
	void setHealthInsurance(int);
};

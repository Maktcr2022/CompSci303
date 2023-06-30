#include <iostream>
#include "employee.h"
using namespace std;


//constructor
Employee::Employee() {
	weeklyRate = 0;
	vacationHours = 0;
	healthInsurance = 0;
}


//getters
int Employee::getWeeklyRate() const {
	return weeklyRate;
}
int Employee::getVacationHours() const {
	return vacationHours;
}
int Employee::getHealthInsurance() const {
	return healthInsurance;
}

//setters
void Employee::setWeeklyRate(int rate) {
	weeklyRate = rate;
}
void Employee::setVacationHours(int vacation) {
	vacationHours = vacation;
}
void Employee::setHealthInsurance(int heath) {
	healthInsurance = heath;
}
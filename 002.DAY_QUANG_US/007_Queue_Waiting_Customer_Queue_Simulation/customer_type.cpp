#include "customer_type.h"


customerType::customerType(int cN, int arrvTime, int wTime, int tTime)
{
	setCustomerInfo(cN, arrvTime, wTime, tTime);
}

void customerType::setCustomerInfo(int cN, int arrvTime, int wTime, int tTime)
{
	customerNumber = cN;
	arrivalTime = arrvTime;
	waitingTime = wTime;
	transactionTime = tTime;
}

int customerType::getWaitingTime() const
{
	return waitingTime;
}

void customerType::setWaitingTime(int time)
{
	waitingTime = time;
}

void customerType::incrementWaitingTime()
{
	waitingTime++;
}

int customerType::getArrivalTime() const
{
	return arrivalTime;
}

int customerType::getTransactionTime() const
{
	return transactionTime;
}

int customerType::getCustomerNumber() const
{
	return customerNumber;
}


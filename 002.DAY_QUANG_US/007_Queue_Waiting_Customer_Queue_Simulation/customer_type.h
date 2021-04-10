#ifndef CUSTOMER_TYPE_H
#define CUSTOMER_TYPE_H

class customerType
{
public:
	customerType(int cN = 0, int arrvTime = 0,
		int wTime = 0, int tTime = 0);
	void setCustomerInfo(int cN = 0, int inTime = 0,
		int wTime = 0, int tTime = 0);
	int getWaitingTime() const;
	void setWaitingTime(int time);
	void incrementWaitingTime();
	int getArrivalTime() const;
	int getTransactionTime() const;
	int getCustomerNumber() const;

private:
	int customerNumber;
	int arrivalTime;
	int waitingTime;
	int transactionTime;
};

#endif // !CUSTOMER_TYPE_H



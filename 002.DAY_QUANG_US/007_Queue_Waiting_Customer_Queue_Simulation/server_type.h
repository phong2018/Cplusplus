#ifndef SERVER_TYPE_H
#define SERVER_TYPE_H

#include <string>
#include "customer_type.h"

class serverType
{
public:
	serverType();
	bool isFree() const;
	void setBusy();
	void setFree();
	void setTransactionTime(int t);
	void setTransactionTime();
	int getRemainingTransactionTime() const;
	void decreaseTransactionTime();
	void setCurrentCustomer(customerType cCustomer);
	int getCurrentCustomerNumber() const;
	int getCurrentCustomerArrivalTime() const;
	int getCurrentCustomerWaitingTime() const;
	int getCurrentCustomerTransactionTime() const;

private:
	customerType currentCustomer;
	std::string status;
	int transactionTime;
};

#endif // !SERVER_TYPE_H


#ifndef SERVER_LIST_TYPE_H
#define SERVER_LIST_TYPE_H

#include <iostream>
#include "customer_type.h"
#include "server_type.h"


class serverListType
{
public:
	serverListType(int num = 1);
	~serverListType();
	int getFreeServerID() const;
	int getNumberOfBusyServers() const;
	void setServerBusy(int serverID, customerType cCustomer, int tTime);
	void setServerBusy(int serverID, customerType cCustomer);
	void updateServers(std::ostream& outFile);

private:
	int numOfServers;
	serverType* servers;
};

#endif // !SERVER_LIST_TYPE_H


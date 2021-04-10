#include <iostream>
#include <cmath>
#include "customer_type.h"
#include "server_list_type.h"
#include "waiting_customer_queue_type.h"


using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers,
	int& transTime, int& tBetweenCArrival)
{
	cout << "Enter the simulation time: ";
	cin >> sTime;
	cout << endl;
	cout << "Enter the number of servers: ";
	cin >> numOfServers;
	cout << endl;
	cout << "Enter the transaction time: ";
	cin >> transTime;
	cout << endl;
	cout << "Enter the time between customers arrival: ";
	cin >> tBetweenCArrival;
	cout << endl;
}


int main()
{
	int clock; //simulation time
	int time, numOfServers, transTime, betweenArrival; //simulation parameters
	int totalWaitTime = 0;
	int customersArrived = 0;
	int customersServed = 0;

	serverListType servers;
	waitingCustomerQueueType waitQueue;
	customerType customer;

	setSimulationParameters(time, numOfServers, transTime, betweenArrival);

	cout << endl;
	cout << "Simulation time: " << time << endl;
	cout << "Number of Servers:  " << numOfServers << endl;
	cout << "Transaction time: " << transTime << endl;
	cout << "Average time between customers: " << betweenArrival << endl << endl;

	srand (1);

	for (clock = 1; clock <= time; clock++)
   {

      p = (double)rand()/(RAND_MAX);

      if(p>exp(-lambda)){

      }

   }

   customersServed = customersServed + servers.getNumberOfBusyServers();

   cout << endl;
   cout << "Simulation run for " << time << " time units" << endl;
   cout << "Customers arrived: " << customersArrived << endl;
   cout << "Total number of customers who completed a transaction: " << customersServed << endl;
   cout << "Customers left in servers: " << servers.getNumberOfBusyServers() << endl;
   cout << "Customers left in queue: " << customersArrived - customersServed << endl;
   cout << "Total waiting time: " << totalWaitTime << endl;
   cout << "Average waiting time: " << (double)totalWaitTime/customersServed;

	return 0;
}

#include <iostream>
#include <cmath>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


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

	//srand (1);

	for (clock = 1; clock <= time; clock++)
   {
      servers.updateServers(cout);// sử dụng tham số cout để xuất

      if(!waitQueue.isEmptyQueue()){// nếu khách hàng đang đợi ko rỗng thì cập nhật thời gian đợi
        //cout<<"pt trong queue: "<<waitQueue.count<<endl;
        waitQueue.updateWaitingQueue();
      }

      // xét khách hàng có đến không
      float rn=rand();
      float p = rn/RAND_MAX;
      float t1=-1;
      t1=t1/betweenArrival;
      float t=exp(t1);
      //nếu có khác hàng đến thêm vào queue
      //If a customer arrives, increment the number of customers arrived by 1 and add the new customer to the queue
      //(use the correct parameters in the constructor!).
      if(p>t){
         customersArrived++;

      	customerType cust(customersArrived,clock,0,transTime);
      	waitQueue.addQueue(cust);
      	cout<<"Customer number "<<customersArrived<<" arrived at time unit "<<clock<<endl;
      	//-----
      	//cout<<"them cuss "<<count<<" luc: "<<clock<<endl;
         //cout<<waitQueue.queueFront<<"-"<<waitQueue.queueRear<<endl;
      	//cout<<"khach co den khong"<<endl;
      	// tang so luong bo vao queue

      }
      int serid=servers.getFreeServerID();

      //cout<<"serid"<<serid<<endl;

      if( serid>-1 && !waitQueue.isEmptyQueue() ){

         customerType cust;
	   	cust = waitQueue.front();
	   	totalWaitTime=totalWaitTime+cust.getWaitingTime();
		   waitQueue.deleteQueue();

		   servers.setServerBusy(serid,cust);

		   customersServed++;
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
/*
26.8 Waiting Customer Queue Simulation
In this exercise you will have to simulate a queuing system, as described in Data structures with C++, chapter 8. All the necessary classes are provided to you. Your job will be to use them in the main function to run the simulation.

Here is a summary of the available classes:

customerType: this class is used to create customer objects to add to the queue. It stores useful information about the customer such as customer number, arrival time, waiting time and transaction time.
queueType: the queue that customers join when they first arrive. queueType inherits from the abstract class queueADT, which has the only goal of stipulating the requisites of a queue class.
serverType: this class is used to create server objects. Customers go to servers to complete their transaction. Each server can serve only one customer at the time, so it is always set as either busy or free.
serverListType: a list of server created at the beginning of the simulation (the number of servers is part of the parameters). serverListType keeps track of what servers are available. A very important function of serverListType is updateServers, which is used at each iteration to determine if a server has become available.
waitingCustomerQueueType: this class inherits from the queueType class and adds only a method (beside the constructor), updateWaitingQueue(). This method is used to increment the waiting time of each customer in the queue.
You can look at each file for more details regarding the classes implementations and how they work.

The main function starts with the creation of the necessary variables for the simulation. These include a clock (a counter to simulate the passing of time), the simulation parameters (total simulation time, number of servers, transaction time, and average time between customers arrival), total waiting time, total customers arrived and total customers served. Additionally, you will need the queue (waitQueue), a list of servers (servers) and a customer object (customer).

The program then proceeds calling the function setSimulationParameters, which gets the parameters from cin, and sets a seed for the generation of random numbers used in the simulation.

Your task is to complete the for loop intentionally left blank. Each iteration of this for loop represents a time unit (e.g. 1 minute) of the simulation. In the loop, perform the following tasks (in the order they are listed):

Update the server list: this will decrement the transaction time of each busy server by one time unit (to represent the fact that they are spending time completing the customer's transaction). If a server completes a transaction, a message will be sent to the ofstream parameter (use cout as parameter to send messages to standard output).
If the waiting queue is not empty, call the function updateWaitingQueue. This will increase the waiting time of each customer in the queue by 1 unit.
If a customer arrives, increment the number of customers arrived by 1 and add the new customer to the queue (use the correct parameters in the constructor!).
To determine if a customer arrived, we will use the Poisson distribution, which will keep the correct average time between arrivals, but will be more realistic than having the customers arriving at regular intervals. The Poisson distribution helps us determine the probability of a customer arriving at a given minute, when we know that a customer is expected every n minutes. At each iteration compute a random number rnum between 0 and 1 and compare it with exp(-1/n), the probability of no event occurring. If rnum is greater, add a customer to the queue, and do nothing otherwise. It may help you to know that this command can be used to generate a random number between 0 and 1:

(double)rand()/(RAND_MAX);
Finally, if a server is free and the customer’s queue is nonempty, remove a customer from the front of the queue and send the customer to the free server. At this time, you also want to retrieve the waiting time from the customer and add it to totalWaitingTime, and increase the number of served customers (we consider a customer served the moment it reaches the a server).
If you complete the loop correctly, at the end of the simulation you will see some interesting data, including the average waiting time fore each served customer and how many are left in the queue.

To get the output in the test case, we used srand(1) and the following parameters:

simulation time = 100
servers = 1
transaction time = 5
time between arrival = 5
Once your program works, change the parameters to see how the behavior of the queue will change! (more or less servers, longer transaction times…)
*/

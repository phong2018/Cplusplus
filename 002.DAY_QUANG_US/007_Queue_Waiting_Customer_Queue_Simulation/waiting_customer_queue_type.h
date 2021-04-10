#ifndef WAITING_CUSTOMER_QUEUE_TYPE_H
#define WAITING_CUSTOMER_QUEUE_TYPE_H

#include "customer_type.h"
#include "queue_type.h"


class waitingCustomerQueueType : public queueType<customerType>
{
public:
	waitingCustomerQueueType(int size = 100);
	void updateWaitingQueue();
};

#endif // !WAITING_CUSTOMER_QUEUE_TYPE_H

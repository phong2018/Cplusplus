#ifndef QUEUE_TYPE_H
#define QUEUE_TYPE_H

#include <iostream>
#include <cassert>
#include "queueADT.h"

using namespace std;

template <class Type>
class queueType : public queueADT<Type>
{
public:
//	const queueType<Type>& operator=(const queueType<Type>&) {

//	}

	bool isEmptyQueue() const {
		return (count == 0);
	}

	bool isFullQueue() const {
		return (count == maxQueueSize);
	}

	void initializeQueue() {
		queueFront = 0;
		queueRear = maxQueueSize - 1;
		count = 0;
	}

	Type front() const {
		assert(!isEmptyQueue());
		return list[queueFront];
	}

	Type back() const {
		assert(!isEmptyQueue());
		return list[queueRear];
	}

	void addQueue(const Type& queueElement) {
		if (!isFullQueue())
		{
			queueRear = (queueRear + 1) % maxQueueSize; //use the
			count++;
			list[queueRear] = queueElement;
		}
		else
			cout << "Cannot add to a full queue." << endl;
	}

	void deleteQueue() {
		if (!isEmptyQueue())
		{
			count--;
			queueFront = (queueFront + 1) % maxQueueSize;
		}
		else
			cout << "Cannot remove from an empty queue" << endl;
	}

	queueType(int queueSize = 100) {
		if (queueSize <= 0)
		{
			cout << "Size of the array to hold the queue must "
				<< "be positive." << endl;
			cout << "Creating an array of size 100." << endl;
			maxQueueSize = 100;
		}
		else
			maxQueueSize = queueSize; //set maxQueueSize to

		queueFront = 0; //initialize queueFront
		queueRear = maxQueueSize - 1; //initialize queueRear
		count = 0;
		list = new Type[maxQueueSize];
	}

//	queueType(const queueType<Type>& otherQueue) {

//	}

	~queueType() {
		delete[] list;
	}

public:
	int maxQueueSize; //variable to store the maximum queue size
	int count; //variable to store the number of
	int queueFront; //variable to point to the first
	int queueRear; //variable to point to the last
	Type* list; //pointer to the array that holds
};

#endif // !QUEUE_TYPE_H


#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "List.h"
template <class T>
class Queue
{
	List<T> queueL;
public:
	Queue() {}
	~Queue() {}

	int size()
	{
		return queueL.getSize();
	}

	bool empty()
	{
		return queueL.empty();
	}

	const T& front()
	{
		return queueL.front();
	}

	void push(const T& item)
	{
		queueL.pushBack(item);
	}

	T pop()
	{
		T item = queueL.front();
		queueL.popFront();
		return item;
	}
	void clear()
	{
		queueL.clear();
	}
	void display_list()
	{
		for (List<T>::iterator first = queueL.begin(); first != queueL.end(); ++first)
			cout << *first << "\t";
		cout << endl;
	}
};

#endif // QUEUE_H_INCLUDED

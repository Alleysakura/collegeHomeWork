#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
template<class T>
class List
{
	class Node
	{
	public:
		T data;
		Node* prev;
		Node* next;
		Node(const T& d = T(), Node *p = NULL, Node *n = NULL) :data(d), prev(p), next(n) {}
	};

	Node* head;
	Node* tail;
	int size;
	void init()
	{
		size = 0;
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}
public:
	class const_iterator
	{
	protected:
		Node* current;
		T& retrieve()
		{
			return current->data;
		}
		const_iterator(Node* n) :current(n) {}
		friend class List<T>;
	public:
		const_iterator() :current(NULL) {}
		const T& operator*()
		{
			return retrieve();
		}
		const_iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		const_iterator operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}
		const_iterator& operator--()
		{
			current = current->prev;
			return *this;
		}
		const_iterator operator--(int)
		{
			const_iterator old = *this;
			--(*this);
			return old;
		}
		bool operator==(const const_iterator& rhs) const
		{
			return current == rhs.current;
		}
		bool operator!=(const const_iterator& rhs) const
		{
			return current != rhs.current;
		}
	};
	class iterator :public const_iterator
	{
	protected:
		explicit iterator(Node* n) :const_iterator(n) {}
		friend class List<T>;
	public:
		iterator() {}
		T& operator*()
		{
			return retrieve();
		}
		const T& operator*() const
		{
			return const_iterator::operator* ();
		}
		iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
		iterator& operator--()
		{
			current = current->prev;
			return *this;
		}
		iterator operator--(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
	};
public:
	List()
	{
		init();
	}
	List(const List& L)
	{
		init();
		operator=(L);
	}

	iterator begin()
	{
		return iterator(head->next);
	}
	iterator end()
	{
		return iterator(tail);
	}
	void pushBack(const T& item)
	{
		insert(end(), item);
	}

	~List()
	{
		delete head;
		delete tail;
	}


	const List& operator=(const List& L);
	iterator insert(iterator itr, T item);
	iterator erase(iterator itr);

	const_iterator begin() const
	{
		return iterator(head->next);
	}
	const_iterator end() const
	{
		return iterator(tail);
	}

	bool empty()
	{
		return size == 0;
	}
	T& front()
	{
		return *begin();
	}
	T& back()
	{
		return *--end();
	}

	const T& back() const
	{
		return *--end();
	}
	void popFront()
	{
		erase(begin());
	}
	void popBack()
	{
		erase(--end());
	}


};
#endif

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
/*
#include"List.h"
template<class T>
class Stack{
	List<T>stackL;
public:
	Stack(){}
	~Stack(){}
	int Size()const{ return stackL.Size(); }
	bool Empty()const{ return stackL.Empty(); }
	const T& Top()const{ return stackL.Back(); }
	T Pop(){ T item = stackL.Back(); stackL.Pop_back(); return item; }
	void Push(const T& item){ stackL.Push_back(item); }
	void Clear(){ stackL.Clear(); }
};

*/
#include "List.h"
template<class T>
class Stack{
	List<T> stackL;
public:
	Stack(){}
	~Stack(){}

	int getSize(){return stackL.getSize();}
	bool empty(){ return stackL.empty();}
	const T& top() const {
		return stackL.back();
	}

	T pop(){
		T item = stackL.back();
		stackL.popBack();
		return item;
	}

	void push(const T& item){
		stackL.pushBack(item);
	}

	void clear(){
		stackL.clear();
	}

};

#endif // STACK_H_INCLUDED

#ifndef BTNODELIB_H_INCLUDED
#define BTNODELIB_H_INCLUDED

#include<iostream>
#include"BTNode.h"
#include"Queue.h"
#include"Stack.h"

using namespace std;

template<class T>
typename List<T>::iterator List<T>::insert(iterator itr, T item) {
	Node* current = itr.current;
	current->prev->next = new Node(item, current->prev, current);
	current->prev = current->prev->next;
	size++;
	return iterator(current->prev);
}

template<class T>
typename List<T>::iterator List<T>::erase(iterator itr) {
	Node *p = itr.current;
	iterator re(p->next);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	size--;
	return(re);
}

//²ã´Î±éÀú
template<class T>
void Level(const BTNode<T>* t){
	if (t == NULL){
		return;
	}
	cout<<"Level : ";
	Queue<const BTNode<T>*> Q;
	Q.push(t);
	while (!Q.empty())
	{
		t = Q.pop();
		cout << t->data;
		if (t->left)
			Q.push(t->left);
		if (t->right)
			Q.push(t->right);
	}
}

template<class T>
void PrintBTree(const BTNode<T>*t , int screenwidth){
    if(t==NULL){
        return;
    }
    int level=0,offset=screenwidth/2
}


#endif // BTNODELIB_H_INCLUDED

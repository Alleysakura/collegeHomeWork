#include<iostream>
#include"BTNode.h"
#include"Queue.h"
using namespace std;
template<class T>
typename List<T>::iterator List<T>::insert(iterator itr, T item) 
{
	Node* current = itr.current;
	current->prev->next = new Node(item, current->prev, current);
	current->prev = current->prev->next;
	size++;
	return iterator(current->prev);
}

template<class T>
typename List<T>::iterator List<T>::erase(iterator itr) 
{
	Node *p = itr.current;
	iterator re(p->next);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	size--;
	return(re);
}

template<class T>
void Level(const BTNode<T>* t)
{
	if (t == NULL)
		return;
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

int main()
{
	BTNode<char> *nullp = NULL;
	BTNode<char> *fp = GetBTNode('F');
	BTNode<char> *dp = GetBTNode('D', fp);
	BTNode<char> *bp = GetBTNode('B', nullp, dp);
	BTNode<char> *ep = GetBTNode('E');
	BTNode<char> *cp = GetBTNode('C', nullp, ep);
	BTNode<char> *ap = GetBTNode('A', bp, cp);
	Level(ap);
	cout << endl;
	return 0;
}
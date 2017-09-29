#ifndef BTNODELIB_H_INCLUDED
#define BTNODELIB_H_INCLUDED

#include<iostream>
#include"BTNode.h"
#include"Queue.h"
#include"Stack.h"

using namespace std;

template<class T>
BTNode<T>* MakeLinked(const Vector<T>& L){
    if(L.Size()==0){
        return;
    }
    Queue<BTNode<T>*> Q;
    BTNode<T> *t=GetBTNode(L[0]);
    BTNode<T>*parent,*child;
    Q.push(t);
    int i=0,n=L.Size();
    while(!Q.empty()){
        parent = Q.pop();
        if(2*i+1<n&&L[2*i+1]!=T()){
            child = GetBTNode(L[2*i+1]);
            parent->left = child;
            Q.push(child);
        }
        if(2*i+2<n&&L[2*i+2]!=T()){
            child = GetBTNode(L[2*i+2]);
            parent->right = child;
            Q.push(child);
        }
        i++;
        while(i<n&&L[i]==T()){
            i++;
        }
        return (t);
    }
}

struct Location{
int xindent,ylevel;
};

void Gotoxy(int x,int y){
    static int level=0,indent = 0;
    if(y==0){
        indent=0;level=0;
    }
    if(level!=y){
        cout<<endl;
        indent=0;
        level++;
    }
    cout.width(x-indent);
    indent = x;
}


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
    int level=0,offset=screenwidth/2;
    Location fLoc,cLoc;
    Queue<const BTNode<T>*> Q;
    Queue<Location> LQ;
    fLoc.xindent=offset;
    fLoc.ylevel=level;
    Q.push(t);
    LQ.push(fLoc);
    while(!Q.empty()){
        t = Q.pop;
        fLoc = LQ.pop();
        Gotoxy(fLoc.xindent,fLoc.ylevel);
        cout<<t->data;
        if(fLoc.ylevel!=level){
            level++;offset=offset/2;
        }
        if(t->left){
            Q.push(t->left);
            cLoc.ylevel=fLoc.ylevel+1;
            cLoc.xindent=fLoc.xindent-offset/2;
            LQ.push(cLoc);
        }
        if(t->right){
            Q.push(t->right);
            cLoc.ylevel=fLoc.ylevel+1;
            cLoc.xindent=fLoc.xindent+offset/2;
            LQ.push(cLoc);
        }
    }
    cout<<endl;
}


#endif // BTNODELIB_H_INCLUDED

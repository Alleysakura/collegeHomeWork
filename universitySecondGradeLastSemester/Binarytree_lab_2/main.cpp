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

//层次遍历
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

//前序遍历
template<class T>
void SimPreorder(const BTNode<T>* t){
    if(!t){
        return;
    }
    cout<<"SimPreorder : ";
    Stack<const BTNode<T>*> S;
    while(t||!S.empty()){
        if(t){
            cout<<t->data;
            if(t->right){
                S.push(t->right);
            }
            t = t->left;
        }
        else{
            t = S.pop();
        }
    }
}

//中序遍历
template<class T>
void SimInorder(const BTNode<T>* t){
    if(!t){
        return;
    }
    cout<<"SimInorder : ";
    Stack<const BTNode<T>*> S;
    while(t||!S.empty()){
        if(t){
            S.push(t);
            t = t->left;
        }else{
            t = S.pop();
            cout<<t->data;
            t = t->right;
        }
    }
}

//后序遍历
template<class T>
void SimPostorder(const BTNode<T>* t){
    if(!t){
        return;
    }
    int tag;
    cout<<"SimPostorder : ";
    Stack<const BTNode<T>*> S;
    Stack<int> tagS;
    const BTNode<T>*temp;
    while(t||!S.empty()){
        if(t){
            S.push(t);tagS.push(1);
            t=t->left;
        }else{
            temp=S.pop();
            tag=tagS.pop();
            if(tag==1){
                S.push(temp);tagS.push(2);
                t=temp->right;
            }else{
                cout<<temp->data;
            }
        }
    }

}
int main()
{
    BTNode<char> *nullp=NULL;
    BTNode<char> *fp=GetBTNode('F');
    BTNode<char> *dp=GetBTNode('D',fp);
    BTNode<char> *bp=GetBTNode('B',nullp,dp);
    BTNode<char> *ep=GetBTNode('E');
    BTNode<char> *cp=GetBTNode('C',nullp,ep);
    BTNode<char> *ap=GetBTNode('A',bp,cp);
    Level(ap);
    cout<<endl;
    SimPreorder(ap);
    cout<<endl;
    SimInorder(ap);
    cout<<endl;
    SimPostorder(ap);
    cout<<endl;
    return 0;
}

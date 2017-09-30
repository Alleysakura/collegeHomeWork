#include <iostream>
#include"Tree.h"
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


int main()
{
    Tree<char> T(20);
    ifstream fin;
    fin.open("D:\\treein.txt",ios::in|ios::nocreate);
    if(!fin){
        cout<<"cant open D:\\treein.txt\n";
        exit(1);
    }
    fin>>T;
    ofstream fout;
    fout.open("D:\\treeout.txt",ios::out);
    if(!fout){
        cout<<"cant open D:\\treeout.txt\n";
        exit(1);
    }
    fout<<T;
    return 0;
}

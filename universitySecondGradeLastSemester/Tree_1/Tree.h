#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include"Tree.h"

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


template<class T>
class Tree{
    T * NA;
    List<int>* Hl;
    int root;
    int sizeN,sizeC;
    int maxN;
public:
    Tree(int n=100):root(-1),sizeN(0),sizeC(0),maxN(n){
        NA=new T[n];
        HL=new List<int>[n];
    }
    ~Tree(){
        delete []NA;
        delete []HL;
    }
    int Empty()const{
        return(sizeN==0);
    }
    int Full()const{
        return (sizeN==maxN);
    }
    int SizeN()const{
        return sizeN;
    }
    int SizeC()const{
        return sizeC;
    }
    int FindNode(const T& v)const;
    bool FindNode(T& v,int pos)const;
    bool InsertN(const T& node);
    bool InsertC(const T& parent,const T& child);
    void ReadTree(const char* filename);
    void WriteTree(const char* filename);
    friend ostream& operator<<(ostream& ostr,const Tree<T>& t);
    friend istream& operator>>(istream& istr,Tree<T>& t);
};


#endif // TREE_H_INCLUDED

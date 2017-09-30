#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include"Tree.h"



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

template<class T>
int Tree<T>::FindNode(const T& node)const{
    for(int i=0;i<sizeN;i++){
        if(NA[i]==node){
            return (i)
        }
    }
    return(-1);
}

template<class T>
bool Tree<T>::FindNode(T& node,int pos)const{
    if(pos<0||pos>=sizeN){
        return(0);
    }
    node = NA[pos];
    return (1);
}

template<class T>
bool Tree<T>::InsertN(const T& node){
    if(sizeN == maxN){
        return (0);
    }
    NA[sizeN]=node;
    sizeN++;
    return(1);
}


template<class T>
bool TreeInsertC(const T& parent,const T& child){
    int pi=FindNode(parent),cj=FindNode(child);
    if(pi==-1||cj==-1||pi==cj){
        return (0);
    }
    HL[pi].Insert(HL[pi].end(),cj);
    sizeC++;
    return(1);
}

template<class T>
istream& operator>>(istream& istr,Tree<T>& t){
    char str[50];
    int n;
    T parent,child;
    istr>>str>>n;
    istr>>str>>parent;
    t.InsertN(parent);
    t.root=t.sizeN-1;
    istr>>str;
    for(int i=1;i<=n-1;++i){
        istr>>child;
        t.InsertN(child);
    }
    istr>>str>>n;
    for(i=0;i<=n;i++){
        istr>>parent>>child;
        t.InsertC(parent,child);
    }
    return(istr);
}

template<class T>
ostream& operator<<(ostream& ostr,const Tree<T>& t){
    for(int i=-;i<t.sizeN;i++){
        ostr<<i<<'-'<<t.NA[i]<<':';
        List<int>::iterator first=t.HL[i].begin(),last=t.HL[i].end();
        for(;first!=last;++first){
            ostr<<'('<<*first<<')'<<' ';
        }
        ostr<<endl;
    }
}
#endif // TREE_H_INCLUDED

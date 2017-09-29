#include <iostream>
#include"BTNode.h"
#include"BTNodeLib.h"
#include"Vector.h"

using namespace std;

int main()
{

    Vector<char> L;
    char a[15]={'A','B','C','\0','D','\0','E','\0','\0','F'};
    for(int i=0;i<10;i++){
        L.pushBack(a[i]);
    }
    BTNode<char>* t=MakeLinked(L);
    PrintBTree(t,40);
    Level(t);
    return 0;
}

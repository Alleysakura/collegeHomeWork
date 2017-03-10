typedef int Type;
#include<iostream>
#include "seqlist_class.h"

using namespace std;

int main()
{
    Seqlist L(10);

    L.InsertRear(5);
    L.InsertRear(15);
    L.InsertRear(20);
    L.Insert(1,10);
    L.Erase(0);

    int n = L.Size();
    for (int i = 0; i < n; ++i) {
        cout<<L.Getdata(i)<<'\n';
    }
    L.Clear();
    return 0;
}

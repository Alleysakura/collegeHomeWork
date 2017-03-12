#include"seqlist.h"
#include<iostream>
using namespace std;
template<class T>
const T&Max(const T&x, const T&y)
{
	return x > y ? x : y;
}
void main()
{
	cout << Max(1, 2) << endl;
	cout << Max(2.122343, 3.323444) << endl;
}
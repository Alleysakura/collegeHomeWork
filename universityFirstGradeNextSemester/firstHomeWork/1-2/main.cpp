#include"seqlist.h"
#include<iostream>
using namespace std;
template <class T>
const T&max(const T&x, const T&y)
{
	return x > y ? x : y;
}
void main()
{
	Seqlist x, y;
	int i,a,b;
	IniList(&x, 10);
	IniList(&y, 10);
	cout << "input the data of x:" << endl;
	for (i = 0; i < 10; ++i)
	{
		cin >> a;
		InsertRear(&x, a);
	}
	cout << "input the numer of y:" << endl;
	for (i = 0; i < 10; ++i)
	{
		cin >> b;
		InsertRear(&y, b);
	}
	cout << max(1, 2) << endl;
	cout << max(2.030010, 3.122323) << endl;
	cout << max(x.data[2], y.data[2]) << endl;
}
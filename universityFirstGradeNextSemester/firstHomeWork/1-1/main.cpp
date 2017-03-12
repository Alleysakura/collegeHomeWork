#include"seqlist.h"
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
bool operator>(Seqlist l1, Seqlist l2);
int main()
{
	Seqlist l1, l2;
	int i = 0, a, b;
	IniList(&l1, 10);
	IniList(&l2, 10);
	cout << "input 10 integers for l1:" << endl;
	for (i = 0; i < 10; ++i)
	{
		cin >> a;
		InsertRear(&l1, a);
	}
	cout << "input 10 integers for l2:" << endl;
	for (i = 0; i < 10; ++i)
	{
		cin >> b;
		InsertRear(&l2, b);
	}
		if (l1> l2)
		{
			cout << "the biger one is l1" << endl;
		}
		else
		{
			cout << "the biger one is l2" << endl;
		}
}
bool operator>(Seqlist l1, Seqlist l2)
{
	int x;
	cout << "input the numer you want to compare:" << endl;
	cin >> x;
	if (l1.data[x] > l2.data[x])
		return 1;
	else
		return 0;
}
typedef int Data;
#include<stdlib.h>
#include<stdio.h>
typedef struct Seqlist
{
	Data *data;
	int size;
	int max;
}Seqlist;
void IniList(Seqlist *l, int n);/*׼����*/
void FreeList(Seqlist *l);/*����*/
void InsertRear(Seqlist *l, int item);/*β��*/
void Insert(Seqlist *l, int id, int item);/*����*/
void Erase(Seqlist *l, int id);/*��ɾ*/
void Clear(Seqlist *l);/*���*/

int Getdata(const Seqlist *l, int id);/*ȡֵ*/
int Size(const Seqlist *l);/*ȡ������*/
int Empty(Seqlist *l);/*�п�*/
int Full(Seqlist *l);/*����*/

/*����ʵ��*/
void IniList(Seqlist *l, int n)
{
	l->data = (int *)malloc(n * sizeof(int));
	if (l->data == NULL)
	{
		printf("Memory allocation error!\n");
		exit(1);
	}
	l->size = 0;
	l->max = n;
}

void FreeList(Seqlist *l)
{
	free(l->data);
}

void InsertRear(Seqlist *l, int item)
{
	if (l->size == l->max)
	{
		printf("InsertRear:list is full!\n");
		exit(1);
	}
	l->data[l->size] = item;
	l->size++;
}

void Insert(Seqlist *l, int id, int item)
{
	int i;
	if (id<0 || id>l->size || l->size == l->max)
	{
		printf("Erase:id is illegal or list is full!\n");
		exit(1);
	}
	for (i = l->size; i >= id; --i)
		l->data[i + 1] = l->data[i];
	l->data[id] = item;
	l->size++;
}

void Erase(Seqlist *l, int id)
{
	int i;
	if (id<0 || id>l->size -1|| l->size == 0)
	{
		printf("id is illegal or list is null!\n");
		exit(1);
	}
	for (i = id+1; i < l->size; ++i)
		l->data[i-1] = l->data[i];
	l->size--;
}

void Clear(Seqlist *l)
{
	l->size = 0;
}

int Getdata(Seqlist *l,int id)
{
	if (id<0 || id>l->size - 1)
	{
		printf("id is illegai or list is emoty!\n");
		exit(1);
	}
	return l->data[id];
}

int Size(const Seqlist *l)
{
	return l->size;
}

int Empty(Seqlist *l)
{
	return l->size == 0;
}

int Full(Seqlist *l)
{
	return l->size == l->max;
}
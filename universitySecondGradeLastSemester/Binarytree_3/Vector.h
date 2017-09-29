/*
#pragma once
#ifndef   _VECTOR_H
#define   _VECTOR_H  //防止头文件重复定义
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;
	template <class Type>
	class Vector
	{
	public:
		explicit Vector(void); //默认构造函数
		explicit Vector(int);//向量大小构造函数 防止通过隐式转换来调用这个构造函数
		explicit Vector(int, const Type&);//初始化大小，并赋初值
		Vector(const Vector&); //复制构造函数
		virtual ~Vector(void); //析构函数
							   //操作符重载函数
		Vector& operator = (const Vector&);
		inline Type& operator [] (int);
		//inline const Type& operator [] (int) const;

		friend std::ostream& operator<<(std::ostream& out, const Vector<Type>& V); //输出运算符重载
																				   //算术操作符重载
		Vector<Type> operator + (const Type&) const;
		Vector<Type> operator + (const Vector<Type>&) const;

		inline int get_size(void) const;
	private:

		int size; //向量大小
		bool display; //是否显示标志
					  /// 指向数据的指针
		Type *data;

	};

	//创建一个大小为0的向量
	template <class Type>
	Vector<Type>::Vector(void)
	{
		size = 0;
		display = true;
		data = NULL;
	}

	/// @param new_size 向量的大小
	template <class Type>
	Vector<Type>::Vector(int new_size)
	{
		// (if debug)

#ifdef _DEBUG

		if (new_size < 0)
		{
			std::cout << "Xiaoding Error: Vector Template." << std::endl
				<< "Vector(int) constructor." << std::endl
				<< "Size must be equal or greater than zero." << endl;

			exit(1);
		}

#endif

		size = new_size;
		display = true;
		data = new Type[new_size];
	}

	//创建一个大小为new_size的向量，并用类型为Type的值给向量赋初值
	template <class Type>
	Vector<Type> ::Vector(int new_size, const Type& value)
	{
		// Control sentence (if debug)

#ifdef _DEBUG

		if (new_size < 0)
		{
			std::cerr << "Xiaoding Error: Vector Template." << std::endl
				<< "Vector(int, const Type&) constructor." << std::endl
				<< "Size must be equal or greater than zero." << std::endl;

			exit(1);
		}

#endif

		size = new_size;
		display = true;
		data = new Type[new_size];

		for (int i = 0; i < size; i++)
		{
			data[i] = value;
		}
	}

	//复制构造函数，复制一个已经存在的向量，other_vector 为被赋值的向量
	template <class Type>
	Vector<Type>::Vector(const Vector<Type>& other_vector)
	{
		size = other_vector.size;
		display = true;
		data = new Type[size];

		// Control sentence (if debug)

		for (int i = 0; i < size; i++)
		{
			data[i] = other_vector[i];
		}
	}

	//析构函数
	template <class Type>
	Vector<Type>::~Vector(void)
	{
		if (data != NULL)
		{
			delete[](data);
		}
	}

	//赋值运算符重载，将一个向量赋给另一个向量
	template <class Type>
	Vector<Type>& Vector<Type>::operator = (const Vector<Type>& other_vector)
	{
		if (this != &other_vector) // other vector
		{
			if (size != other_vector.get_size()) // other size
			{
				if (data != NULL)
				{
					// Control sentence (if debug)

					//#ifdef _DEBUG
					//cout << "Xiaoding Warning: Vector Template." << endl
					//          << "Vector& operator = (const Vector<Type>&)." << endl
					//          << "Assignment operator to non-empty vector." << endl;
					//#endif

					delete[](data);
				}

				size = other_vector.size;

				data = new Type[size];
			}

			for (int i = 0; i < size; i++)
			{
				data[i] = other_vector[i];
			}

			display = true;//把other_vector的display的熟悉赋给它
		}

		return(*this);
	}

	//返回向量索引为i的值
	template <class Type>
	inline Type& Vector<Type>::operator [] (int i)
	{
		// Control sentence (if debug)

#ifdef _DEBUG

		if (size == 0)
		{
			std::cerr << " Xiaoding Error: Vector Template. " << std::endl
				<< "Reference operator []." << std::endl
				<< "Size of vector is zero." << std::endl;

			exit(1);
		}
		else if (i < 0)
		{
			std::cerr << "Xiaoding Error: Vector Template. " << std::endl
				<< "Reference operator []." << std::endl
				<< "Index must be equal or greater than zero." << std::endl;

			exit(1);
		}
		else if (i >= size)
		{
			std::cerr << "Xiaoding Error: Vector Template. " << std::endl
				<< "Reference operator []." << std::endl
				<< "Index is " << i << " and it must be less than " << size << "." << std::endl;

			exit(1);
		}

#endif

		// Return vector element

		return(data[i]);
	}

	template <class Type>
	std::ostream &operator<<(std::ostream &out, const Vector<Type>& V)
	{

		for (int i = 0; i<V.size; i++)
		{
			std::out << V.data[i] << " ";
			if ((i + 1) % 10 == 0)
				std::out << endl;
		}
		return std::out;
	}

	//给向量加上一个值 vector+scalar
	template <class Type>
	Vector<Type> Vector<Type>::operator + (const Type& scalar) const
	{
		Vector<Type> sum(size);

		for (int i = 0; i < size; i++)
		{
			sum[i] = data[i] + scalar;
		}

		return(sum);
	}

	//一个向量加上另一个向量
	template <class Type>
	Vector<Type> Vector<Type>::operator + (const Vector<Type>& other_vector) const
	{
		// Control sentence (if debug)

#ifdef _DEBUG

		int other_size = other_vector.get_size();

		if (other_size != size)
		{
			std::cerr << "Xiaoding Error: Vector Template. " << std::endl
				<< "Vector<Type> operator + (const Vector<Type>) const." << std::endl
				<< "Size of vectors is " << size << " and " << other_size << " and they must be the same."
				<< std::endl;

			exit(1);
		}

#endif

		Vector<Type> sum(size);

		for (int i = 0; i < size; i++)
		{
			sum[i] = data[i] + other_vector[i];
		}

		return(sum);
	}

	template <class Type>
	inline int Vector<Type>::get_size(void) const
	{
		return(size);
	}



#endif
*/

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

#include <stdlib.h>
template <class T>
class Vector {
private:
	T * data;
	int size;
	int max;
	void error(const char* s) { cout << s << endl;		exit(1); }
public:
	enum { SPARE_MAX = 16 };
	explicit Vector(int n = 0) : size(0), max(n + SPARE_MAX) { if (max >0) data = new T[max]; }
	Vector(const Vector<T>& v) : data(NULL), max(0) { operator=(v); }
	~Vector() { delete[] data; }
	T& operator[] (int id) { return data[id]; }
	bool empty() const { return size == 0; }
	int getSize() const { return size; }
	int getMax() const { return max; }
	void clear() { size = 0; }

	typedef T* Iterator;
	typedef const T* const_Iterator;
	Iterator begin() { return data; }
	const_Iterator begin() const { return data; }
	Iterator end() { return data + size; }
	const_Iterator end() const { return data + size; }

	const T& front() const { return data[0]; }
	T& front() { return data[0]; }
	const T& back() const { return data[size - 1]; }
	T& back() { return data[size - 1]; }
	void pushBack(const T& item) { data[size++] = item; }
	void popBack() { size--; }

	Vector& operator= (const Vector<T>& v);

	void reserve(int newmax);
	void resize(int newsize, const T& item = T());

	Iterator insert(Iterator itr, const T& item);
	Iterator erase(Iterator itr);
};
template<class T>
Vector<T>& Vector<T>::operator =(const Vector<T>& v)
{
	if (max != v.getMax())
	{
		delete[]data;
		max = v.max;
		data = new T[max];
	}
	size = v.getSize();
	for (int i = 0; i<size; ++i)
		data[i] = v.data[i];
	return *this;
}
template<class T>
void Vector<T>::reserve(int newmax)
{
	if (newmax<max)
		return;
	T* old = data;
	data = new T[newmax];
	for (int i = 0; i<size; ++i)
		data[i] = old[i];
	max = newmax;
	delete[]old;
}
template<class T>
void Vector<T>::resize(int newsize, const T& item)
{
	if (newsize>max)
		reserve(newsize * 2 + 1);
	for (int i = size; i<newsize; ++i)
		data[i] = item;
	size = newsize;
}
template<class T>
typename Vector<T>::Iterator
typename Vector<T>::erase(Iterator itr)
{
	for (Iterator p = itr, q = itr + 1; q != data + size; ++p, ++q)
		*p = *q;
	size--;
	return itr;
}
template<class T>
typename Vector<T>::Iterator
typename Vector<T>::insert(Iterator itr, const T& item)
{
	if (size == max)
		reserve(2 * max + 1);
	for (Iterator p = data + size, q = data + size - 1; p != itr; --p, --q)
		*p = *q;
	*itr = item;
	size++;
	return itr;
}
#endif

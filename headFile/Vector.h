#pragma once
#ifndef   _VECTOR_H  
#define   _VECTOR_H  //��ֹͷ�ļ��ظ�����  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstdlib>  
using namespace std;
	template <class Type>
	class Vector
	{
	public:
		explicit Vector(void); //Ĭ�Ϲ��캯��  
		explicit Vector(int);//������С���캯�� ��ֹͨ����ʽת��������������캯��  
		explicit Vector(int, const Type&);//��ʼ����С��������ֵ  
		Vector(const Vector&); //���ƹ��캯��  
		virtual ~Vector(void); //��������  
							   //���������غ���  
		Vector& operator = (const Vector&);
		inline Type& operator [] (int);
		//inline const Type& operator [] (int) const;  

		friend std::ostream& operator<<(std::ostream& out, const Vector<Type>& V); //������������  
																				   //��������������  
		Vector<Type> operator + (const Type&) const;
		Vector<Type> operator + (const Vector<Type>&) const;

		inline int get_size(void) const;
	private:

		int size; //������С  
		bool display; //�Ƿ���ʾ��־  
					  /// ָ�����ݵ�ָ��  
		Type *data;

	};

	//����һ����СΪ0������  
	template <class Type>
	Vector<Type>::Vector(void)
	{
		size = 0;
		display = true;
		data = NULL;
	}

	/// @param new_size �����Ĵ�С  
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

	//����һ����СΪnew_size����������������ΪType��ֵ����������ֵ  
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

	//���ƹ��캯��������һ���Ѿ����ڵ�������other_vector Ϊ����ֵ������  
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

	//��������  
	template <class Type>
	Vector<Type>::~Vector(void)
	{
		if (data != NULL)
		{
			delete[](data);
		}
	}

	//��ֵ��������أ���һ������������һ������  
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

			display = true;//��other_vector��display����Ϥ������  
		}

		return(*this);
	}

	//������������Ϊi��ֵ  
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

	//����������һ��ֵ vector+scalar  
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

	//һ������������һ������  
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
#ifndef MERGESORT
#define MERGESORT

#include <iostream>
#include "Ordenacion/ordenacion.h"

using namespace std;

template <class T>
class mergeSort
{
	private:
		int contador_;
	public:
		mergeSort();
		~mergeSort();

		int get_contador();
		void algoritmo(T* secuencia, int tam, int metodo);

		ostream& write(ostream& os, T* secuencia, int tam, int j, int k);
};

template <class T>
mergeSort<T>::mergeSort():
	contador_(0)
{}

template <class T>
mergeSort<T>::~mergeSort()
{
	contador_ = 0;
}

template <class T>
int mergeSort<T>::get_contador()
{
	return contador_;
}

template <class T>
void mergeSort<T>::algoritmo(T* secuencia, int tam, int metodo)
{
	//TODO
}

template <class T>
ostream& mergeSort<T>::write(ostream& os, T* secuencia, int tam, int j, int k)
{
	for (int i = 0; i < tam; i++)
	{
		if ((i != j) && (i != k))
			os << secuencia[i] << " ";
		else
			cout << "[" << secuencia[i] << "] ";
	}
	os << endl;
	return os;
}

#endif // MERGESORT


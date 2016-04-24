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
		int tam_;
	public:
		mergeSort();
		~mergeSort();

		int get_contador();
		void algoritmo(T* secuencia, int tam, int metodo);

		void do_mergeSort(T* secuencia, int ini, int fin);
		void mezcla(T* secuencia, int ini, int cen, int fin);

		ostream& write(ostream& os, T* secuencia, int tam, int j, int k);
};

template <class T>
mergeSort<T>::mergeSort():
	contador_(0),
	tam_(0)
{}

template <class T>
mergeSort<T>::~mergeSort()
{
	contador_ = 0;
	tam_ = 0;
}

template <class T>
int mergeSort<T>::get_contador()
{
	return contador_;
}

template <class T>
void mergeSort<T>::algoritmo(T* secuencia, int tam, int metodo)
{
	tam_ = tam;
	do_mergeSort(secuencia, 0, tam-1);
	if(metodo == 1)
		write(cout, secuencia, tam, -1, -1);
}

template <class T>
void mergeSort<T>::do_mergeSort(T* secuencia, int ini, int fin)
{
	if (ini < fin)
	{
		int cen = (ini+fin)/2;
		do_mergeSort (secuencia, ini, cen);
		do_mergeSort (secuencia, cen+1, fin);
		mezcla (secuencia, ini, cen, fin);
	}
}

template <class T>
void mergeSort<T>::mezcla(T* secuencia, int ini, int cen, int fin)
{
	int i = ini;
	int j = cen+1;
	int k = ini;

	T* aux = new T [tam_];
	for(int k = 0; k < tam_; k++)
		aux[k] = secuencia[k];

	while ((i <= cen) && (j <= fin))
	{
		write(cout, secuencia, tam_, i, j);
		cin.ignore();

		if (secuencia[i] < secuencia[j])
		{
			aux[k] = secuencia[i];
			i++;
		}
		else
		{
			aux[k] = secuencia[j];
			j++;
		}
		k++;
	}

	write(cout, secuencia, tam_, i, j);
	cin.ignore();

	if (i > cen){
		while (j <= fin)
		{
			aux[k] = secuencia[j];
			j++;
			k++;
		}
	}
	else{
		while (i <= cen){
			aux[k] = secuencia[i];
			i++;
			k++;
		}
	}

	for (int k = ini; k <= fin; k++)
		secuencia[k] = aux[k];
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


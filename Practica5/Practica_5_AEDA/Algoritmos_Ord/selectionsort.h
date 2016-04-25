#ifndef SELECTIONSORT
#define SELECTIONSORT

#include <iostream>
#include "Ordenacion/ordenacion.h"

using namespace std;

template <class T>
class selectionSort
{
	private:
		int contador_;
	public:
		selectionSort();
		~selectionSort();

		int get_contador();
		void algoritmo(T* secuencia, int tam, int metodo);

		ostream& write(ostream& os, T* secuencia, int tam, int j, int k);
};

template <class T>
selectionSort<T>::selectionSort():
	contador_(0)
{}

template <class T>
selectionSort<T>::~selectionSort()
{
	contador_ = 0;
}

template <class T>
int selectionSort<T>::get_contador()
{
	return contador_;
}

template <class T>
void selectionSort<T>::algoritmo(T* secuencia, int tam, int metodo)
{
	contador_ = 0;
	for (int i = 0; i < tam-1; i++)
	{
		for (int j = i+1; j < tam; j++)
		{
			if (metodo == 1){
				write(cout, secuencia, tam, i, j);
				cin.ignore();
			}
			else
				contador_++;

			if ((secuencia[i] > secuencia[j])){
				T aux(secuencia[i]);
				secuencia[i] = secuencia[j];
				secuencia[j] = aux;
			}
		}
	}

	if (metodo == 1)
		write(cout, secuencia, tam, -1, -1);
}

template <class T>
ostream& selectionSort<T>::write(ostream& os, T* secuencia, int tam, int j, int k)
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

#endif // SELECTIONSORT


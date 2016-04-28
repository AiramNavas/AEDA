#ifndef QUICKSORT
#define QUICKSORT

#include <iostream>
#include "Ordenacion/ordenacion.h"

using namespace std;

template <class T>
class quickSort
{
	private:
		int contador_;
		int tam_;
	public:
		quickSort();
		~quickSort();

		int get_contador();
		void algoritmo(T* secuencia, int tam, int metodo);
		void do_quickSort(T* secuencia, int ini, int fin, int metodo);

		ostream& write(ostream& os, T* secuencia, int ini, int fin, int j, int k, int p);
};

template <class T>
quickSort<T>::quickSort():
	contador_(0),
	tam_(0)
{}

template <class T>
quickSort<T>::~quickSort()
{
	contador_ = 0;
}

template <class T>
int quickSort<T>::get_contador()
{
	return contador_;
}

template <class T>
void quickSort<T>::algoritmo(T* secuencia, int tam, int metodo)
{
	contador_ = 0;
	tam_=tam;
	do_quickSort(secuencia, 0, tam-1, metodo);
}

template <class T>
void quickSort<T>::do_quickSort(T* secuencia, int ini, int fin, int metodo)
{

	int i = ini;
	int f = fin;
	int p = (i+f)/2;
	T pivot = secuencia[p];

	while(i < f)
	{
		while (secuencia[i] < pivot)
		{
			if (metodo == 1){
				write(cout, secuencia, ini, fin, i, p, p);
				cin.ignore();
			}
			else
				contador_++;
			i++;
		}
		if (metodo == 1){
			write(cout, secuencia, ini, fin, i, p, p);
			cin.ignore();
		}
		else
			contador_++;

		while (secuencia[f] > pivot)
		{
			if (metodo == 1){
				write(cout, secuencia, ini, fin, f, p, p);
				cin.ignore();
			}
			else
				contador_++;
			f--;
		}
		if (metodo == 1){
			write(cout, secuencia, ini, fin, f, p, p);
			cin.ignore();
		}
		else
			contador_++;

		if (i < f)
		{
			if (metodo == 1){
				write(cout, secuencia, ini, fin, i, f, p);
				cin.ignore();
			}

			T temp = secuencia[i];
			secuencia[i] = secuencia[f];
			secuencia[f] = temp;
			i++;
			f--;

			if (metodo == 1){
				write(cout, secuencia, 0, tam_-1, -1, -1, -1);
				cin.ignore();
			}
		}
		else if (i == f)
		{
			i++;
			f--;
			if (metodo == 1){
				write(cout, secuencia, 0, tam_-1, -1, -1, -1);
				cout << endl;
			}
		}
	}

	if (ini < i) do_quickSort(secuencia, ini, f, metodo);
	if (f < fin) do_quickSort(secuencia, i, fin, metodo);
}

template <class T>
ostream& quickSort<T>::write(ostream& os, T* secuencia, int ini, int fin, int j, int k, int p)
{
	for (int i = ini; i <= fin; i++)
	{
		if ((i != p) && (i != j) && (i != k))
			os << secuencia[i] << " ";
		else if((i == p) && ((j == p) || (k == p)))
			cout << "[|" << secuencia[i] << "|] ";
		else if ((i == p) && ((j != p) && (k != p)))
			cout << "|" << secuencia[i] << "| ";
		else
			cout << "[" << secuencia[i] << "] ";
	}
	os << endl;
	return os;
}

#endif // QUICKSORT


#ifndef BURBUJA
#define BURBUJA

#include <iostream>
#include "Ordenacion/ordenacion.h"

using namespace std;

template <class T>
class burbuja
{
	private:
		int contador_;
	public:
		burbuja();
		~burbuja();

		int get_contador();
		void algoritmo(T* secuencia, int tam, int metodo);

		ostream& write(ostream& os, T* secuencia, int tam, int j, int k);
};

template <class T>
burbuja<T>::burbuja():
	contador_(0)
{}

template <class T>
burbuja<T>::~burbuja()
{
	contador_ = 0;
}

template <class T>
int burbuja<T>::get_contador()
{
	return contador_;
}

template <class T>
void burbuja<T>::algoritmo(T* secuencia, int tam, int metodo)
{
	contador_ = 0;
	bool swapped = false;
	for (int i=0; i < tam; i++)
	{
		swapped = false;
		for (int j = tam-1; j > i; j--)
		{
			if (metodo == 1){
				write(cout, secuencia, tam, j, j-1);
				cout << endl;

			}
			else
				contador_++;

			if (secuencia[j] < secuencia[j-1]){
				T aux(secuencia[j]);
				secuencia[j] = secuencia[j-1];
				secuencia[j-1] = aux;
				swapped = true;
			}
			if (metodo == 1)
				cin.ignore();
		}
		if(!swapped)
			break;
	}
	if (metodo == 1)
		write(cout, secuencia, tam, -1, -1);
}

template <class T>
ostream& burbuja<T>::write(ostream& os, T* secuencia, int tam, int j, int k)
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


#endif // BURBUJA


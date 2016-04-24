#ifndef INSERCION
#define INSERCION

#include <iostream>
#include "Ordenacion/ordenacion.h"

using namespace std;

template <class T>
class insercion
{
	private:
		int contador_;
	public:
		insercion();
		~insercion();

		int get_contador();
		void algoritmo(T* secuencia, int tam, int metodo);

		ostream& write(ostream& os, T* secuencia, int tam, int j, int k);
};

template <class T>
insercion<T>::insercion():
	contador_(0)
{}

template <class T>
insercion<T>::~insercion()
{
	contador_ = 0;
}

template <class T>
int insercion<T>::get_contador()
{
	return contador_;
}

template <class T>
void insercion<T>::algoritmo(T* secuencia, int tam, int metodo)
{
	contador_ = 0;

	for (int i=1; i < tam; i++)
	{
		for (int k = i; k > 0; k--)
		{
			if (metodo == 1){
				write(cout, secuencia, tam, k, k-1);
				cout << endl;
			}
			else
				contador_++;

			if (secuencia[k] < secuencia[k-1]){
				T aux(secuencia[k]);
				secuencia[k] = secuencia[k-1];
				secuencia[k-1] = aux;
			}
			else{
				if (metodo == 1)
					cin.ignore();
				break;
			}
			if (metodo == 1)
				cin.ignore();
		}
	}
	if (metodo == 1)
		write(cout, secuencia, tam, -1, -1);
}

template <class T>
ostream& insercion<T>::write(ostream& os, T* secuencia, int tam, int j, int k)
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

#endif // INSERCION


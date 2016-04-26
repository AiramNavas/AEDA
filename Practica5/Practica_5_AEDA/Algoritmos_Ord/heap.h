#ifndef HEAP
#define HEAP


#include <iostream>
#include "Ordenacion/ordenacion.h"

using namespace std;

template <class T>
class heap
{
	private:
		int contador_;
		int tam_;
	public:
		heap();
		~heap();

		int get_contador();
		void algoritmo(T* secuencia, int tam, int metodo);

		void baja(int i, T* secuencia, int tam, int metodo);

		ostream& write(ostream& os, T* secuencia, int tam, int j, int k);
		ostream& write2(ostream& os, T* secuencia, int ini, int fin, int ins);
};

template <class T>
heap<T>::heap():
	contador_(0),
	tam_(0)
{}

template <class T>
heap<T>::~heap()
{
	contador_ = 0;
}

template <class T>
int heap<T>::get_contador()
{
	return contador_;
}

template <class T>
void heap<T>::algoritmo(T* secuencia, int tam, int metodo)
{
	tam_=tam;

	for (int i = tam/2; i > 0; i--)
	{
		if (metodo == 1)
			write2(cout, secuencia, i, tam-1, 1);

		baja(i, secuencia, tam, metodo);
	}

	for (int i = tam; i > 1; i--)
	{
		T x = secuencia[0];
		secuencia[0] = secuencia[i-1];
		secuencia[i-1] = x;

		if (metodo == 1)
			write2(cout, secuencia, 0, i-2, 0);

		baja(1,secuencia,i-1, metodo);
	}

	write(cout, secuencia, tam, -1, -1);

}

template <class T>
void heap<T>::baja(int i, T* secuencia, int tam, int metodo)
{
	T x = secuencia[i-1];

	int h, h1, h2;

	while (2*i <= tam)
	{
		h1 = 2*i;
		h2 = h1+1;

		if (metodo == 1 && h1 != tam)
		{
			write(cout, secuencia, tam, h1-1, h2-1);
			cin.ignore();
		}
		else
			contador_++;

		if (h1 == tam)
		{
			h = h1;
		}
		else if (secuencia[h1-1] > secuencia[h2-1])
		{
			h = h1;
		}
		else
		{
			h = h2;
		}

		if (metodo == 1)
		{
			write(cout, secuencia, tam, h-1, i-1);
			cin.ignore();
		}
		else
			contador_++;

		if (secuencia[h-1] <= x)
		{
			break;
		}
		else
		{
			secuencia[i-1] = secuencia[h-1];
			secuencia[h-1] = x;
			i = h;
		}
	}
}

template <class T>
ostream& heap<T>::write(ostream& os, T* secuencia, int tam, int j, int k)
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

template <class T>
ostream& heap<T>::write2(ostream& os, T* secuencia, int ini, int fin, int ins)
{
	if (ins == 1){
		for (int i = 0; i < ini; i++)
		{
			if (i != ini-1)
				cout << secuencia[i] << " ";
			else
				cout << secuencia[i];
		}
		cout << " ";
	}

	cout << "\33[4m";
	for (int i = ini; i <= fin; i++)
	{
		if (i != fin)
			cout << secuencia[i] << " ";
		else
			cout << secuencia[i];
	}
	cout << "\33[0m" << " ";

	for (int i = fin+1; i < tam_; i++)
	{
		if (i != tam_-1)
			cout << secuencia[i] << " ";
		else
			cout << secuencia[i];
	}

	os << endl;
	os << endl;
	return os;
}


#endif // HEAP


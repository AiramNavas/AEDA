#ifndef ABB

#include <iostream>
#include <vector>
#include "NodoBB/nodobb.h"

using namespace std;

template <class T>
class ArbolBB
{
	private:
		NodoBB<T> *raiz_;
		int* M_;
		float* ME_;

	public:
		ArbolBB();
		~ArbolBB();

		void Insertar(T clave);
		void Eliminar(T clave);
		void Buscar(T clave);

		void Estadistica(T* secuencia, int N, int P);

		ostream& write(ostream& os);
};

template <class T>
ArbolBB<T>::ArbolBB():
	raiz_(NULL)
{}

template <class T>
ArbolBB<T>::~ArbolBB()
{}

template <class T>
void ArbolBB<T>::Insertar(T clave)
{
	raiz_->Insertar(raiz_, clave);
}

template <class T>
void ArbolBB<T>::Eliminar(T clave)
{
	raiz_->Eliminar(raiz_, clave);
}

template <class T>
void ArbolBB<T>::Buscar(T clave)
{
	raiz_->Buscar(raiz_, clave);
}

//template <class T>
//NodoBB* ArbolBB<T>::Buscar(T clave )
//{
//	return BuscarRama(raiz, clave);
//}

//template <class T>
//NodoBB* ArbolBB<T>::BuscarRama(nodoBB* nodo, T clave)
//{
//	if (nodo == NULL)
//		return NULL;
//	if (clave == nodo->clave)
//		return nodo;
//	if (clave < nodo->clave)
//		return BuscarRama(nodo->izdo, clave);

//	return BuscarRama(nodo->dcho, clave);
//}

template <class T>
void ArbolBB<T>::Estadistica(T* secuencia, int N, int P)
{
	M_ = new int[P];

	for (int i = 0; i < N; i++)
		Insertar(secuencia[i]);
//	for (int i = 0; i < N; i++)
//		Buscar(secuencia[i]);

//	for (int i = N; i < N+P; i++)
//		Buscar(secuencia[i]);

	for (int i = 0; i < N; i++)
		Eliminar(secuencia[i]);
	cout << endl;
}

template <class T>
ostream& ArbolBB<T>::write(ostream& os)
{
	if (raiz_ != NULL){
		raiz_->write(os, raiz_);
	}
	else{
		os << "\33[1m" << "Árbol vacío" << "\33[0m" << endl;
		cout << "Nivel 0: [·]" << endl;
	}
	return os;
}

#endif // ABB


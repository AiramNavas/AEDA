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

	public:
		ArbolBB();
		~ArbolBB();

		void Insertar(T clave);
		void Eliminar(T clave);

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
void ArbolBB<T>::Eliminar(T clave)
{
	raiz_->Eliminar(raiz_, clave);
}

//template <class T>
//void ArbolBB<T>::EliminarRama(nodoBB* &nodo, T clave)
//{
//	if (nodo == NULL) return;

//	if (clave < nodo->clave)
//		EliminarRama(nodo->izdo, clave);
//	else{
//		if (clave > nodo->clave)
//			EliminarRama(nodo->dcho, clave);
//		else {
//			nodoBB* &Eliminado = nodo;

//			if (nodo->dcho == NULL) {
//				nodo = nodo->izdo;
//				delete (Eliminado);
//			}
//			else if (nodo->izdo == NULL) {
//				nodo = nodo->dcho;
//				delete (Eliminado);
//			}
//			else {
//				nodoBB* aux = nodo->izdo ;
//				while (aux->dcho != NULL)
//					aux = aux->dcho;
//				Eliminado->clave = aux->clave;
//				Eliminado->dato = aux->dato;
//				EliminarRama (aux, aux->clave);
//			}
//			delete(nodo);
//		}
//	}
//}

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


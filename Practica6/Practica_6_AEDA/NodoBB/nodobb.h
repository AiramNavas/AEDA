#ifndef NODOBB
#define NODOBB

#include <QList>
#include <QMap>

#include <iostream>
using namespace std;

template <class T>
struct L_type
{
		T clave;
		int null;
};

template <class T>
class NodoBB
{
	public:
		T dato_;
		NodoBB<T>* izq_;
		NodoBB<T>* dch_;
		int comparaciones_;
	public:
		NodoBB();
		NodoBB(T clave);
		~NodoBB();

		void Insertar(NodoBB<T>* &nodo, T clave);
		void Buscar(NodoBB<T>* &nodo, T clave);
		void BuscarRecursivo(NodoBB<T>* &nodo, T clave);
		void Eliminar(NodoBB<T>* &nodo, T clave);
		void sustituye(NodoBB<T>* &eliminado, NodoBB<T>* &sust);

		int get_comparaciones();

		void pre_write(NodoBB<T>* &nodo, int k, QMap<int, QList<L_type<T> > > &mapa);
		ostream& write_mapa(ostream& os, QMap<int, QList<L_type<T> > > &mapa);
		ostream& write(ostream& os, NodoBB<T>* &nodo);
};

template <class T>
NodoBB<T>::NodoBB():
	dato_(0),
	izq_(NULL),
	dch_(NULL),
	comparaciones_(0)
{}

template <class T>
NodoBB<T>::NodoBB(T clave):
	dato_(clave),
	izq_(NULL),
	dch_(NULL),
	comparaciones_(0)
{}

template <class T>
NodoBB<T>::~NodoBB()
{
	comparaciones_ = 0;
}

template <class T>
int NodoBB<T>::get_comparaciones()
{
	return comparaciones_;
}

template <class T>
void NodoBB<T>::Insertar(NodoBB<T>* &nodo, T clave)
{
	if (nodo == NULL)
		nodo = new NodoBB<T>(clave);
	else
	{
		if (clave < nodo->dato_)
		{
			Insertar(nodo->izq_, clave);
		}
		else
		{
			Insertar(nodo->dch_, clave);
		}
	}
}

template <class T>
void NodoBB<T>::Buscar(NodoBB<T>* &nodo, T clave)
{
	comparaciones_ = 0;
	BuscarRecursivo(nodo, clave);
}

template <class T>
void NodoBB<T>::BuscarRecursivo(NodoBB<T>* &nodo, T clave)
{
	if(nodo == NULL)
		return;

	comparaciones_++;

	if (clave == nodo->dato_)
	{
		return;
	}
	comparaciones_++;
	if (clave > nodo->dato_)
	{
		BuscarRecursivo(nodo->dch_, clave);
	}
	else
	{
		BuscarRecursivo(nodo->izq_, clave);
	}

}

template <class T>
void NodoBB<T>::Eliminar(NodoBB<T>* &nodo, T clave) {
	if (nodo == NULL)
	{
		cout << "No existe en el árbol." << endl;
		return;
	}

	if (clave < nodo->dato_)
		Eliminar(nodo->izq_, clave);
	else if (clave > nodo->dato_)
		Eliminar(nodo->dch_, clave);
	else {
		NodoBB<T>* Eliminado = nodo;
		if (nodo->dch_ == NULL)
			nodo = nodo->izq_;
		else if (nodo->izq_ == NULL)
			nodo = nodo->dch_;
		else
			sustituye(Eliminado, nodo->izq_);
		delete (Eliminado);
	}
}

template <class T>
void NodoBB<T>::sustituye(NodoBB<T>* &eliminado, NodoBB<T>* &sust) {
	if (sust->dch_ != NULL)
		sustituye(eliminado, sust->dch_);
	else {
		eliminado->dato_ = sust->dato_;
		eliminado = sust;
		sust = sust->izq_;
	}
}

template <class T>
void NodoBB<T>::pre_write(NodoBB<T>* &nodo, int k, QMap<int, QList<L_type<T> > > &mapa)
{
	L_type<T> nodoD;
	nodoD.clave = nodo->dato_;
	nodoD.null = 1;
	mapa[k].append(nodoD);

	k++;

	if(nodo->izq_ != NULL && nodo->dch_ != NULL){
		pre_write(nodo->izq_, k, mapa);
		pre_write(nodo->dch_, k, mapa);
	}
	else if (nodo->izq_ != NULL){
		pre_write(nodo->izq_, k, mapa);
		nodoD.null=0;
		mapa[k].append(nodoD);
	}
	else if (nodo->dch_ != NULL){
		nodoD.null=0;
		mapa[k].append(nodoD);
		pre_write(nodo->dch_, k, mapa);
	}
	else{
		nodoD.null=0;
		mapa[k].append(nodoD);
		mapa[k].append(nodoD);
	}
}

template <class T>
ostream& NodoBB<T>::write_mapa(ostream& os, QMap<int, QList<L_type<T> > > &mapa)
{
	for(int i = 0; i < mapa.size(); i++)
	{
		cout << "Nivel " << i << ": ";
		for(int j = 0; j < mapa[i].size(); j++)
		{
			if(mapa[i].at(j).null!=0)
				cout << "[" << mapa[i].at(j).clave << "] ";
			else
				cout << "[·] ";
		}
		cout << endl;
	}

	return os;
}

template <class T>
ostream& NodoBB<T>::write(ostream& os, NodoBB<T>* &nodo)
{
	QMap<int, QList<L_type<T> > > mapa;
	pre_write(nodo, 0, mapa);
	write_mapa(os, mapa);
	return os;
}

#endif // NODOBB


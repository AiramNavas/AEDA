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
		NodoBB<T>* padre_;
		NodoBB<T>* izq_;
		NodoBB<T>* dch_;
	public:
		NodoBB();
		NodoBB(T clave);
		~NodoBB();

		void Insertar(NodoBB<T>* &nodo, T clave);
		void Eliminar(NodoBB<T>* &nodo, T clave);
		void Buscar(NodoBB<T>* &nodo, T clave);

		void Estadistica(T* secuencia, int N, int P);

		void pre_write(NodoBB<T>* &nodo, int k, QMap<int, QList<L_type<T> > > &mapa);
		ostream& write_mapa(ostream& os, QMap<int, QList<L_type<T> > > &mapa);
		ostream& write(ostream& os, NodoBB<T>* &nodo);
};

template <class T>
NodoBB<T>::NodoBB():
	dato_(0),
	padre_(NULL),
	izq_(NULL),
	dch_(NULL)
{}

template <class T>
NodoBB<T>::NodoBB(T clave):
	dato_(clave),
	padre_(NULL),
	izq_(NULL),
	dch_(NULL)
{}

template <class T>
NodoBB<T>::~NodoBB()
{}

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
			nodo->izq_->padre_ = nodo;
		}
		else
		{
			Insertar(nodo->dch_, clave);
			nodo->dch_->padre_ = nodo;
		}
	}
}

template <class T>
void NodoBB<T>::Eliminar(NodoBB<T>* &nodo, T clave)
{
	if (nodo == NULL)
	{
		cout << "No existe en el árbol." << endl;
		return;
	}

	int twin = 0;
	if(nodo->dato_ < clave)
		Eliminar(nodo->dch_, clave);
	else if(nodo->dato_ > clave)
		Eliminar(nodo->izq_, clave);
	else
	{
		if(nodo->izq_ == NULL && nodo->dch_ != NULL)
		{
			// Si solo tiene el hijo DERECHO
			if (nodo->padre_ != NULL){
				if(nodo->padre_->dato_ < nodo->dato_)
					nodo->padre_->dch_ = nodo->dch_;
				else
					nodo->padre_->izq_ = nodo->dch_;
				nodo = NULL;
			}
			else
			{
				nodo = nodo->dch_;
				twin++;
			}
		}
		else if(nodo->izq_ != NULL && nodo->dch_ == NULL)
		{
			// Si solo tiene el hijo IZQUIERDO
			if (nodo->padre_ != NULL){
				if(nodo->padre_->dato_ > nodo->dato_)
					nodo->padre_->izq_ = nodo->izq_;
				else
					nodo->padre_->dch_ = nodo->izq_;
				nodo = NULL;
			}
			else
			{
				nodo = nodo->izq_;
				twin++;
			}
		}
		else if(nodo->izq_ != NULL && nodo->dch_ != NULL)
		{
			// Si tiene AMBOS hijos
			NodoBB<T>* aux = nodo->izq_;
			while (aux->dch_ != NULL)
				aux = aux->dch_;
			T Caux = aux->dato_;
			Eliminar(aux, aux->dato_);
			nodo->dato_ = Caux;
			twin++;
		}
		else
		{
			// Si es una HOJA
			if (nodo->padre_ != NULL){
				if (nodo->padre_->dato_ > nodo->dato_)
					nodo->padre_->izq_ = NULL;
				else
					nodo->padre_->dch_ = NULL;
			}
			else
				nodo = NULL;
		}
		if (twin == 0)
			delete (nodo);
	}
}

template <class T>
void NodoBB<T>::Buscar(NodoBB<T>* &nodo, T clave)
{

}

template <class T>
void NodoBB<T>::Estadistica(T* secuencia, int N, int P)
{
	cout << "AAAAAAA" << endl;
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


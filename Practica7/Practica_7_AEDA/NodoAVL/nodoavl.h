#ifndef NODOAVL
#define NODOAVL

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
class NodoAVL
{
	public:
		T dato_;
		int bal_;
		NodoAVL<T>* izq_;
		NodoAVL<T>* dch_;
		int comparaciones_;
	public:
		NodoAVL();
		NodoAVL(T clave);
		~NodoAVL();

		void Rotacion_II(NodoAVL* &nodo);
		void Rotacion_DD(NodoAVL* &nodo);
		void Rotacion_ID(NodoAVL* &nodo);
		void Rotacion_DI(NodoAVL* &nodo);

		void Insertar_bal(NodoAVL<T>* &nodo, NodoAVL<T>* nuevo, bool& crece);
		void Insertar_re_balancea_izq(NodoAVL<T>* &nodo, bool &crece);
		void Insertar_re_balancea_dch(NodoAVL<T>* &nodo, bool &crece);

		void Buscar(NodoAVL<T>* &nodo, T clave);
		void BuscarRecursivo(NodoAVL<T>* &nodo, T clave);

		void Eliminar_Rama(NodoAVL<T>* &nodo, T clave, bool decrece);
		void Eliminar_re_balancea_izq(NodoAVL<T>* &nodo, bool &decrece);
		void Eliminar_re_balancea_dch(NodoAVL<T>* &nodo, bool &decrece);
		void sustituye(NodoAVL<T>* &eliminado, NodoAVL<T>* &sust, bool &decrece);

		int get_comparaciones();

		void pre_write(NodoAVL<T>* &nodo, int k, QMap<int, QList<L_type<T> > > &mapa);
		ostream& write_mapa(ostream& os, QMap<int, QList<L_type<T> > > &mapa);
		ostream& write(ostream& os, NodoAVL<T>* &nodo);
};

template <class T>
NodoAVL<T>::NodoAVL():
	dato_(0),
	bal_(0),
	izq_(NULL),
	dch_(NULL),
	comparaciones_(0)
{}

template <class T>
NodoAVL<T>::NodoAVL(T clave):
	dato_(clave),
	bal_(0),
	izq_(NULL),
	dch_(NULL),
	comparaciones_(0)
{}

template <class T>
NodoAVL<T>::~NodoAVL()
{
	comparaciones_ = 0;
}

template <class T>
int NodoAVL<T>::get_comparaciones()
{
	return comparaciones_;
}

template <class T>
void NodoAVL<T>::Rotacion_II(NodoAVL* &nodo)
{
	NodoAVL<T>* nodo1 = nodo->izq_;
	nodo->izq_ = nodo1->dch_;
	nodo1->dch_ = nodo;
	if (nodo1->bal_ == 1) {
		nodo->bal_ = 0;
		nodo1->bal_ = 0;
	}
	else {
		nodo->bal_ = 1;
		nodo1->bal_ = -1;
	}
	nodo = nodo1;
}

template <class T>
void NodoAVL<T>::Rotacion_DD(NodoAVL* &nodo)
{
	NodoAVL<T>* nodo1 = nodo->dch_;
	nodo->dch_ = nodo1->izq_;
	nodo1->izq_ = nodo;
	if (nodo1->bal_ == -1) {
		nodo->bal_ = 0;
		nodo1->bal_ = 0;
	}
	else {
		nodo->bal_ = -1;
		nodo1->bal_ = 1;
	}
	nodo = nodo1;
}

template <class T>
void NodoAVL<T>::Rotacion_ID(NodoAVL* &nodo)
{
	NodoAVL<T>* nodo1 = nodo->izq_;
	NodoAVL<T>* nodo2 = nodo1->dch_;
	nodo->izq_ = nodo2->dch_;
	nodo2->dch_ = nodo;
	nodo1->dch_ = nodo2->izq_;
	nodo2->izq_ = nodo1;
	if (nodo2->bal_ == -1)
		nodo1->bal_ = 1;
	else nodo1->bal_ = 0;
	if (nodo2->bal_ == 1)
		nodo->bal_ = -1;
	else nodo->bal_ = 0;
	nodo2->bal_ = 0;
	nodo = nodo2;
}

template <class T>
void NodoAVL<T>::Rotacion_DI(NodoAVL* &nodo)
{
	NodoAVL<T>* nodo1 = nodo->dch_;
	NodoAVL<T>* nodo2 = nodo1->izq_;
	nodo->dch_ = nodo2->izq_;
	nodo2->izq_ = nodo;
	nodo1->izq_ = nodo2->dch_;
	nodo2->dch_ = nodo1;
	if (nodo2->bal_ == 1)
		nodo1->bal_ = -1;
	else nodo1->bal_ = 0;
	if (nodo2->bal_ == -1)
		nodo->bal_ = 1;
				else nodo->bal_ = 0;
	nodo2->bal_ = 0;
	nodo = nodo2;
}

template <class T>
void NodoAVL<T>::Insertar_bal(NodoAVL<T>* &nodo, NodoAVL<T>* nuevo, bool& crece)
{
	if (nodo == NULL) {
		nodo = nuevo;
		crece = true;
	}
	else if (nuevo->dato_ < nodo->dato_) {
		Insertar_bal(nodo->izq_, nuevo, crece);
		if (crece) Insertar_re_balancea_izq(nodo, crece);
	}
	else {
		Insertar_bal(nodo->dch_, nuevo, crece);
		if (crece) Insertar_re_balancea_dch(nodo, crece);
	}
}

template <class T>
void NodoAVL<T>::Insertar_re_balancea_izq(NodoAVL<T>* &nodo, bool &crece)
{
	switch (nodo->bal_)
	{
		case -1:	nodo->bal_ = 0;
					crece = false;
			break;

		case 0:		nodo->bal_ = 1;
			break;

		case 1:		NodoAVL<T>* nodo1 = nodo->izq_;
					if (nodo1->bal_ == 1)
						Rotacion_II(nodo);
					else Rotacion_ID(nodo);
					crece = false;
			break;
	}
}

template <class T>
void NodoAVL<T>::Insertar_re_balancea_dch(NodoAVL<T>* &nodo, bool &crece)
{
	switch (nodo->bal_)
	{
		case 1:		nodo->bal_ = 0;
					crece = false;
			break;

		case 0:		nodo->bal_ = 1;
			break;

		case -1:	NodoAVL<T>* nodo1 = nodo->dch_;
					if (nodo1->bal_ == 1)
						Rotacion_DD(nodo);
					else Rotacion_DI(nodo);
					crece = false;
			break;
	}
}

template <class T>
void NodoAVL<T>::Buscar(NodoAVL<T>* &nodo, T clave)
{
	comparaciones_ = 0;
	BuscarRecursivo(nodo, clave);
}

template <class T>
void NodoAVL<T>::BuscarRecursivo(NodoAVL<T>* &nodo, T clave)
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
void NodoAVL<T>::Eliminar_Rama(NodoAVL<T>* &nodo, T clave, bool decrece) {
	if (nodo == NULL) return;
	if (clave < nodo->dato_) {
		Eliminar_Rama(nodo->izq_, clave, decrece);
		if (decrece)
			Eliminar_re_balancea_izq(nodo, decrece);
	}
	else if (clave > nodo->dato_) {
		Eliminar_Rama(nodo->dch_, clave, decrece);
		if (decrece)
			Eliminar_re_balancea_dch(nodo, decrece);
	}
	else {
		NodoAVL* Eliminado = nodo;
		if (nodo->izq_ == NULL) {
			nodo = nodo->dch_;
			decrece = true;
		}
		else if (nodo->dch_ == NULL) {
			nodo = nodo->izq_;
			decrece = true;
		}
		else {
			sustituye(Eliminado, nodo->izq_, decrece);
			if (decrece)
				Eliminar_re_balancea_izq(nodo, decrece);
		}
		delete Eliminado;
	}
}

template <class T>
void NodoAVL<T>::Eliminar_re_balancea_izq(NodoAVL<T>* &nodo, bool &decrece)
{
	switch (nodo->bal_)
	{
		case -1:{	NodoAVL<T>* nodo1 = nodo->dch_;
					if (nodo1->bal_ > 0)
						Rotacion_DI(nodo);
					else {
						if (nodo1->bal_ == 0)
							decrece = false;
						Rotacion_DD(nodo);
					}
			break;
		}

		case 0:		nodo->bal_ = -1;
					decrece = false;
			break;

		case 1:		nodo->bal_ = 0;
			break;
	}
}

template <class T>
void NodoAVL<T>::Eliminar_re_balancea_dch(NodoAVL<T>* &nodo, bool &decrece)
{
	switch (nodo->bal_)
	{
		case 1:{	NodoAVL<T>* nodo1 = nodo->izq_;
					if (nodo1->bal_ < 0)
						Rotacion_ID(nodo);
					else {
						if (nodo1->bal_ == 0)
							decrece = false;
						Rotacion_II(nodo);
					}
			break;
		}

		case 0:		nodo->bal_ = 1;
					decrece = false;
			break;

		case -1:	nodo->bal_ = 0;
			break;
	}
}

template <class T>
void NodoAVL<T>::sustituye(NodoAVL<T>* &eliminado, NodoAVL<T>* &sust, bool &decrece)
{
	if (sust->dch_ != NULL) {
		sustituye(eliminado, sust->dch_, decrece);
		if (decrece)
			Eliminar_re_balancea_dch(sust, decrece);
	}
	else {
		eliminado->dato_ = sust->dato_;
		eliminado = sust;
		sust = sust->izq_;
		decrece = true;
	}
}

template <class T>
void NodoAVL<T>::pre_write(NodoAVL<T>* &nodo, int k, QMap<int, QList<L_type<T> > > &mapa)
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
ostream& NodoAVL<T>::write_mapa(ostream& os, QMap<int,QList<L_type<T> > > &mapa)
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
ostream& NodoAVL<T>::write(ostream& os, NodoAVL<T>* &nodo)
{
	QMap<int, QList<L_type<T> > > mapa;
	pre_write(nodo, 0, mapa);
	write_mapa(os, mapa);
	return os;
}

#endif // NODOAVL


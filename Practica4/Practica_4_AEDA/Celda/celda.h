#ifndef CELDA
#define CELDA

#include <iostream>
using namespace std;


template <class T>
class Celda
{
	private:
		T* bloque_;
		int counter_;
		int sz_;

	public:
		Celda();
		Celda(int sz);
		~Celda();

		void resize(int sz);

		ostream& write(ostream& os);

		bool buscar_clave(T clave);
		bool insertar_clave(T clave);
};


template <class T>
Celda<T>::Celda():
	bloque_(NULL),
	counter_(0),
	sz_(0)
{}


template <class T>
Celda<T>::Celda(int sz):
	bloque_(NULL),
	sz_(sz),
	counter_(0)
{
	bloque_ = new T [sz_];
}


template <class T>
Celda<T>::~Celda()
{
	delete [] bloque_;
	sz_=0;
	counter_=0;
}


template <class T>
void Celda<T>::resize(int sz)
{
	delete [] bloque_;
	sz_=sz;
	bloque_ = new T[sz_];
	counter_=0;
}


template <class T>
ostream& Celda<T>::write(ostream& os)
{
	for(int i=0; i<counter_;i++)
		os << bloque_[i] << endl;
	return os;
}


template <class T>
bool Celda<T>::insertar_clave(T clave)
{
	if (counter_ < sz_){
		bloque_[counter_]=(clave);
		counter_++;
		return true;
	}
	else
		return false;
}


template <class T>
bool Celda<T>::buscar_clave(T clave)
{
	for (int i=0; i < counter_; i++)
	{
		if(bloque_[i] == clave)
			return true;
	}
	return false;
}


#endif // CELDA

/*


*/

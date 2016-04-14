#ifndef TABLAHASH
#define TABLAHASH

#include "DNI/dni.h"
#include "Dispersion/dispersion.h"
#include "Dispersion/Modulo/modulo.h"
#include "Dispersion/Pseudo_Aleatoria/pseudo_aleatorio.h"
#include "Dispersion/Modificacion/modificacion_d.h"
#include "Exploracion/exploracion.h"
#include "Exploracion/Lineal/lineal.h"
#include "Exploracion/Doble/doble.h"
#include "Exploracion/Cuadratica/cuadratica.h"
#include "Exploracion/Redispersion/redispersion.h"
#include "Exploracion/Modificacion/modificacion_e.h"
#include "Celda/celda.h"

template <class T>
class TablaHash
{
	private:
		Celda<T>* tabla_;
		int nCeldas_;
		int nBloques_;
		Dispersion* dsp_;
		Exploracion* exp_;
		int full_;
		int minimo_Ins_;
		int maximo_Ins_;
		int minimo_Bus_;
		int maximo_Bus_;
	public:
		TablaHash();
		TablaHash(int nCeldas, int nBloques, int dsp, int exp);
		~TablaHash();

		bool insertar(T clave, int est);
		bool buscar(T clave, int est);

		ostream& write(ostream& os);
};

template <class T>
TablaHash<T>::TablaHash():
	tabla_(NULL),
	nCeldas_(0),
	nBloques_(0),
	dsp_(NULL),
	exp_(NULL),
	full_(0),
	minimo_Ins_(0),
	maximo_Ins_(0),
	minimo_Bus_(0),
	maximo_Bus_(0)
{}

template <class T>
TablaHash<T>::TablaHash(int nCeldas, int nBloques, int dsp, int exp):
	tabla_(NULL),
	nCeldas_(nCeldas),
	nBloques_(nBloques),
	dsp_(NULL),
	exp_(NULL),
	full_(0),
	minimo_Ins_(0),
	maximo_Ins_(0),
	minimo_Bus_(0),
	maximo_Bus_(0)
{
	tabla_ = new Celda<T> [nCeldas_];
	for (int i=0; i < nCeldas_; i++)
		tabla_[i].resize(nBloques_);

	if(dsp==1)
		dsp_ = new Modulo;
	else if(dsp==2)
		dsp_ = new Pseudo_Aleatorio;
	else if(dsp==3)
		dsp_ = new Modificacion_D;

	if(exp==1)
		exp_ = new Lineal;
	else if(exp==2)
		exp_ = new Cuadratica;
	else if(exp==3)
		exp_ = new Doble;
	else if(exp==4)
		exp_ = new Redispersion;
	else if(exp==5)
		exp_ = new Modificacion_E;
}

template <class T>
TablaHash<T>::~TablaHash(){}

template <class T>
bool TablaHash<T>::insertar(T clave, int est)
{
	int i=0;
	bool insertado = false;
	int intentos = 0;
	int j = 0;
	int estadistica = est;

	if(!tabla_[(dsp_->dispersion(clave, nCeldas_))].insertar_clave(clave)){
		if (estadistica == 1) intentos++;
		while ((insertado == false) && (full_ != nCeldas_*nBloques_) && (j != nCeldas_*nBloques_-1))
		{
			insertado = tabla_[(dsp_->dispersion(clave, nCeldas_)+exp_->exploracion(clave,nCeldas_,i))%nCeldas_].insertar_clave(clave);
			if (insertado){ full_++;}
			else if (estadistica == 1){ intentos++;}
			i++;
			j++;
		}
	}
	else
	{
		if (estadistica == 1) intentos++;
		insertado = true;
		full_++;
	}

	if (estadistica == 1){
		if (minimo_Ins_ == 0)
			minimo_Ins_ = intentos;

		if(intentos > maximo_Ins_)
			maximo_Ins_ = intentos;
		else if (intentos < minimo_Ins_)
			minimo_Ins_ = intentos;
	}
	return insertado;
}

template <class T>
bool TablaHash<T>::buscar(T clave, int est)
{
	int i=0;
	bool encontrado = false;
	int intentos = 0;
	int estadistica = est;
	bool noencontrado = false;
	if(!tabla_[(dsp_->dispersion(clave, nCeldas_))].buscar_clave(clave)){
		intentos++;
		intentos+=tabla_[(dsp_->dispersion(clave, nCeldas_))].get_repeticiones();
		while ((encontrado == false) && (i != nCeldas_-1) && (noencontrado == false))
		{
			encontrado = tabla_[(dsp_->dispersion(clave, nCeldas_)+exp_->exploracion(clave,nCeldas_,i))%nCeldas_].buscar_clave(clave);
			if((!encontrado)){
				intentos++;
				intentos+=tabla_[(dsp_->dispersion(clave, nCeldas_)+exp_->exploracion(clave,nCeldas_,i))%nCeldas_].get_repeticiones();
				if ((tabla_[(dsp_->dispersion(clave, nCeldas_)+exp_->exploracion(clave,nCeldas_,i))%nCeldas_].get_repeticiones()) < nBloques_)
					noencontrado = true;
			}
			i++;
		}
	}
	else
	{
		intentos++;
		intentos+=tabla_[(dsp_->dispersion(clave, nCeldas_))].get_repeticiones();
		encontrado = true;
	}

	if (estadistica == 1){
		if (minimo_Bus_ == 0)
			minimo_Bus_ = intentos;

		if(intentos > maximo_Bus_)
			maximo_Bus_ = intentos;
		else if (intentos < minimo_Bus_)
			minimo_Bus_ = intentos;
	}
	else{
		if (minimo_Ins_ == 0)
			minimo_Ins_ = intentos;

		if(intentos > maximo_Ins_)
			maximo_Ins_ = intentos;
		else if (intentos < minimo_Ins_)
			minimo_Ins_ = intentos;
	}

	return encontrado;
}

template <class T>
ostream& TablaHash<T>::write(ostream& os)
{

	for(int i=0; i < nCeldas_; i++)
	{
		os << "Celda " << i+1 << ": " << endl;
		tabla_[i].write(os);
		os << endl;
	}
	os << endl;
	os << endl;
	int media_Ins = (minimo_Ins_+maximo_Ins_)/2;
	int media_Bus = (minimo_Bus_+maximo_Bus_)/2;
	os << "\tNúmero de Comparaciones" << endl;
	os << endl;
	os << "\t\tMínimo\tMedia\tMáximo" << endl;
	os << "Búsqueda" << "\t" << minimo_Bus_ << "\t" << media_Bus << "\t" << maximo_Bus_ << endl;
	os << "Inserción" << "\t" << minimo_Ins_ << "\t" << media_Ins << "\t" << maximo_Ins_ << endl;
	os << endl;

	return os;
}

#endif // TABLAHASH


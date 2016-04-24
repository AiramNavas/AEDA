#ifndef ORDENACION
#define ORDENACION
#pragma once

#include <iostream>
#include <string>

#include "Algoritmos_Ord/insercion.h"
#include "Algoritmos_Ord/burbuja.h"
#include "Algoritmos_Ord/shellsort.h"
#include "Algoritmos_Ord/quicksort.h"
#include "Algoritmos_Ord/mergesort.h"

using namespace std;

template <class T>
class Ordenacion {
	private:
		int** M_;
		float** ME_;
		int nPruebas_;
	public:
		Ordenacion();
		Ordenacion(int nPruebas);
		~Ordenacion();

		int get_max(int j);
		int get_min(int j);
		float get_med(int j);
		void esta_comparaciones();

		void demostracion(T* sentencia, int tam, int algoritmo);
		void estadistica(T* sentencia, int tam, int i, int nPruebas);

		ostream& write(ostream& os);
};

template <class T>
Ordenacion<T>::Ordenacion():
	M_(NULL),
	ME_(NULL),
	nPruebas_(0)
{}

template <class T>
Ordenacion<T>::Ordenacion(int nPruebas):
	nPruebas_(nPruebas)
{
	M_ = new int* [nPruebas_];

	for (int i = 0; i < nPruebas_; i++)
		M_[i] = new int [5];
}

template <class T>
Ordenacion<T>::~Ordenacion()
{
	for (int i = 0; i < nPruebas_; i++)
		delete [] M_[i];
	delete [] M_;

	for (int i = 0; i < 5; i++)
		delete [] ME_[i];
	delete [] ME_;

	nPruebas_ = 0;
}

template <class T>
int Ordenacion<T>::get_max(int j)
{
	int max=0;
	for (int i = 0; i < nPruebas_; i++){
		if (max < M_[i][j])
			max = M_[i][j];
	}
	return max;
}

template <class T>
int Ordenacion<T>::get_min(int j)
{
	int min=M_[0][j];
	for (int i = 0; i < nPruebas_; i++){
		if (min > M_[i][j])
			min = M_[i][j];
	}
	return min;
}

template <class T>
float Ordenacion<T>::get_med(int j)
{
	float med=0.0;
	for (int i = 0; i < nPruebas_; i++){
		med += M_[i][j];
	}
	return med/nPruebas_;
}

template <class T>
void Ordenacion<T>::esta_comparaciones()
{
	ME_ = new float* [5];

	for (int i = 0; i < 5; i++)
		ME_[i] = new float [3];

	for (int i = 0; i < 5; i++)
		ME_[i][2] = get_max(i);

	for (int i = 0; i < 5; i++)
		ME_[i][0] = get_min(i);

	for (int i = 0; i < 5; i++)
		ME_[i][1] = get_med(i);
}

template <class T>
void Ordenacion<T>::demostracion(T* secuencia, int tam, int algoritmo)
{
	if (algoritmo == 1){
		insercion<T> v_insercion;
		v_insercion.algoritmo(secuencia, tam, 1);
	}
	else if (algoritmo == 2){
		burbuja<T> v_burbuja;
		v_burbuja.algoritmo(secuencia, tam, 1);
	}
	else if (algoritmo == 3){
		shellSort<T> v_shellSort;
		v_shellSort.algoritmo(secuencia, tam, 1);
	}
	else if (algoritmo == 4){
		quickSort<T> v_quickSort;
		v_quickSort.algoritmo(secuencia, tam, 1);
	}
	else if (algoritmo == 5){
		mergeSort<T> v_mergeSort;
		v_mergeSort.algoritmo(secuencia, tam, 1);
	}
}


template <class T>
void Ordenacion<T>::estadistica(T* secuencia, int tam, int i, int nPruebas)
{
	T* aux = new T [tam];
	for(int k = 0; k < tam; k++)
		aux[k] = secuencia[k];

	insercion<T> v_insercion;
	v_insercion.algoritmo(aux, tam, 0);
	M_[i][0] = v_insercion.get_contador();

	for(int k = 0; k < tam; k++)
		aux[k] = secuencia[k];

	burbuja<T> v_burbuja;
	v_burbuja.algoritmo(aux, tam, 0);
	M_[i][1] = v_burbuja.get_contador();

	for(int k = 0; k < tam; k++)
		aux[k] = secuencia[k];

	shellSort<T> v_shellSort;
	v_shellSort.algoritmo(aux, tam, 0);
	M_[i][2] = v_shellSort.get_contador();

	for(int k = 0; k < tam; k++)
		aux[k] = secuencia[k];

	quickSort<T> v_quickSort;
	v_quickSort.algoritmo(aux, tam, 0);
	M_[i][3] = v_quickSort.get_contador();

	for(int k = 0; k < tam; k++)
		aux[k] = secuencia[k];

	mergeSort<T> v_mergeSort;
	v_mergeSort.algoritmo(aux, tam, 0);
	M_[i][4] = v_mergeSort.get_contador();

	if (i == nPruebas-1)
		esta_comparaciones();
}

template <class T>
ostream& Ordenacion<T>::write(ostream &os)
{
	os << endl;
	for (int i = 0; i < nPruebas_; i++){
		for (int j = 0; j < 5; j++){
			os << M_[i][j] << "\t";
			if (j == 4)
				os << endl;
		}
	}

	os << endl;
	os << "\033[4m" << "\t\tNúmero de comparaciones" << "\033[0m" << endl;
	os << "\033[4m" << "\t\tMínimo\tMedio\tMáximo" << "\033[0m" << endl;
	os << endl;

	for (int i = 0; i < 5; i++){
		os << "Método " << i+1 << "\t";
		for (int j = 0; j < 3; j++)
			os << ME_[i][j] << "\t";
		os << endl;
	}
//	for(int i = 0; i < nPruebas_; i++)
//	{
//		os << "Método " << i+1 << "\t";
//		os << M_[i][0] << endl;
//	}

	return os;
}
#endif // ORDENACION

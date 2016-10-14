#include <iostream>
#include <unistd.h>
#include "DNI/dni.h"
#include "Ordenacion/ordenacion.h"
#include "Algoritmos_Ord/insercion.h"

#define VALOR_MIN 30000000
#define VALOR_MAX 80000000

using namespace std;

template <class T>
void generar_s_aleatorio(T* secuencia, int tam, int inicio, int final)
{
	static int seed = time(0);

	srand(seed++);
	// Formula a + rand() % (b-a+1)
	for(int i=0; i < tam; i++){
		T num = (inicio+rand()%(final-inicio+1));
		if(i>0){
			for(int j=0; j < i; j++)
				if(num==secuencia[j]){
					num = inicio + rand()%(final-inicio+1);
					j=-1;
				}
		}
		secuencia[i] = num;
	}
}

int main()
{

//////////////////////////////////////////////////////////		PEDIR POR PANTALLA


/*
 * Insercion.....= 1
 * Burbuja.......= 2
 * ShellSort.....= 3
 * QuickSort.....= 4
 * MergeSort.....= 5
 * SelectionSort..=6
 * Heap...........=7
*/

	int nPruebas = 5;
	int tam = 8;
	int metodo = 1;
	int algoritmo = 5;


//////////////////////////////////////////////////////////		PRACTICA 5

	Ordenacion<DNI> ordena(nPruebas);
	DNI secuencia[tam];

	cout << "Presione ENTER para comenzar." << endl;
	cin.ignore();

	if (metodo == 1)
	{
		generar_s_aleatorio(secuencia, tam, VALOR_MIN, VALOR_MAX);
		ordena.demostracion(secuencia, tam, algoritmo);
		int x;
		cin >> x;
	}

	if (metodo == 2){
		for (int i = 0; i < nPruebas; i++)
		{
			generar_s_aleatorio(secuencia, tam, VALOR_MIN, VALOR_MAX);
			ordena.estadistica(secuencia, tam, i, nPruebas);
			for(int k = 0; k < tam; k++)
				cout << secuencia[k] << "  ";
			cout << "Prueba" << i+1 << endl;
		}
		ordena.write(cout);
	}		

	return 0;
}


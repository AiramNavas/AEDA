#include <iostream>
#include <unistd.h>
#include "DNI/dni.h"
#include "Ordenacion/ordenacion.h"
#include "Algoritmos_Ord/insercion.h"

using namespace std;

template <class T>
void generar_s_aleatorio(T* secuencia, int tam, int inicio, int final)
{
	srand(time(0));
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
 * Insercion..= 1
 * Burbuja....= 2
 * ShellSort..= 3
 * QuickSort..= 4
 * MergeSort..= 5
*/

	int nPruebas = 10;
	int tam = 15;
	int metodo = 2;
	int algoritmo = 5;


//////////////////////////////////////////////////////////		PRACTICA 5

	Ordenacion<DNI> ordena(nPruebas);
	DNI secuencia[tam];

	if (metodo == 2) cin.ignore();


	if (metodo == 1)
	{
		generar_s_aleatorio(secuencia, tam, 30000000, 80000000);
		ordena.demostracion(secuencia, tam, algoritmo);
	}

	if (metodo == 2){
		for (int i = 0; i < nPruebas; i++)
		{
			generar_s_aleatorio(secuencia, tam, 30000000, 80000000);
			ordena.estadistica(secuencia, tam, i, nPruebas);
			for(int k = 0; k < tam; k++)
				cout << secuencia[k] << "  ";
			cout << "Prueba" << i+1 << endl;
			usleep(1000000);
		}
	}


	if (metodo == 2)
		ordena.write(cout);

	return 0;
}


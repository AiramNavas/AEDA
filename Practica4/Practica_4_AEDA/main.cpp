#include <iostream>
//#include <fstream>
#include "DNI/dni.h"
#include "TablaHash/tablahash.h"

using namespace std;

int main()
{
/*
* Dispersion:
*	1 = Modulo
*	2 = Pseudo-Aleatoria
*	3 = Modificacion
*
* Exploracion:
*	1 = Lineal
*	2 = Cuadratica
*	3 = Doble
*	4 = Redispersion
*	5 = Modificacion
*
*
* F_D: = 0;
* F_E: = Lineal, pero hacia atrás.
*
*
*/


	int nCeldas = 100;
	int nBloques = 2;
	int nPruebas = 20;
	int dsp = 1;
	int exp = 1;
	double factor = 0.5;

	string string_exp;

	if(exp==1)
		string_exp = "Lineal";
	else if(exp==2)
		string_exp = "Cuadrat";
	else if(exp==3)
		string_exp = "Doble";
	else if(exp==4)
		string_exp = "Redisp";
	else if(exp==5)
		string_exp = "Modifi";

///////////////////////////////////////////////////////////////	BANCO DE PRUEBSA

	TablaHash<DNI> TH(nCeldas,nBloques,dsp,exp);
	int N = factor*nCeldas*nBloques;
	int banco[2*N];
	srand(time(0));
	// Formula a + rand() % (b-a+1)
	for(int i=0; i < 2*N; i++)
	{
		int num = 30000000 + rand()%(80000000-30000000+1);
		if(i>0)
		{
			for(int j=0; j < i; j++)
				if(num==banco[j])
				{
					num = 30000000 + rand()%(80000000-30000000+1);
					j=-1;
				}
		}
		banco[i]=num;
	}

///////////////////////////////////////////////////////////////	INSERTAR

	for(int i=0; i < N; i++)
		TH.insertar(banco[i],0);

///////////////////////////////////////////////////////////////	ESTADÍSTICA INSERTAR

	for (int i=0; i < N; i++)
		TH.buscar(banco[i],0);

///////////////////////////////////////////////////////////////	ESTADÍSTICA BUSCAR

	for (int i=N; i < N+nPruebas; i++)
		TH.buscar(banco[i],1);

///////////////////////////////////////////////////////////////	IMPRIMIR

	cout << "Celdas\t\tBloques\t\tExploración\tCarga\t\tPruebas" << endl;
	cout << " " << nCeldas << "\t\t" << nBloques << "\t\t" << string_exp << "\t\t";
	cout << factor << "\t\t" << nPruebas << endl;
	cout << endl;
	cout << endl;

	TH.write(cout);

	return 0;
}

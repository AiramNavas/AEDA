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
	*
	* Exploracion:
	*	1 = Lineal
	*	2 = Cuadratica
	*	3 = Doble
	*	4 = Redispersion
	*/

	int nCeldas = 17;
	int nBloques = 4;
	int dsp = 1;
	int exp = 3;
	double factor = 1.0;

	string string_exp;

	if(exp==1)
		string_exp = "Lineal";
	else if(exp==2)
		string_exp = "Cuadrat";
	else if(exp==3)
		string_exp = "Doble";
	else if(exp==4)
		string_exp = "Redisp";

///////////////////////////////////////////////////////////////	INSERTAR

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

	for(int i=0; i < N; i++)
	{
		TH.insertar(banco[i]);
	}

///////////////////////////////////////////////////////////////	BUSCAR

	for (int i=0; i < N; i++)
	{
		TH.buscar(banco[i]);
	}

///////////////////////////////////////////////////////////////	IMPRIMIR

	cout << "Celdas\t\tBloques\t\tExploración\tCarga\t\tPruebas" << endl;
	cout << " " << nCeldas << "\t\t" << nBloques << "\t\t" << string_exp << "\t\t";
	cout << factor << "\t\t" << N << endl;
	cout << endl;
	cout << endl;

	TH.write(cout);


	return 0;
}

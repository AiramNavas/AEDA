#include <QCoreApplication>

#include <iostream>
#include "ArbolAVL/arbolavl.h"
#include "DNI/dni.h"

#include <vector>

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

void menu_demostracion()
{
	ArbolAVL<int> arbol;

	int num;

	int i = 1;
	while(i != 0)
	{
		cout << "\33[4m" << "\33[1m" << "Modo Demostración" << "\33[0m" << endl;
		cout << "[0] Salir." << endl;
		cout << "[1] Insertar." << endl;
		cout << "[2] Eliminar." << endl;
		cin >> i;
		system("clear");
		if (i > 2 || i < 0)
			cout << "Opción incorrecta." << endl;
		else
			switch (i)
			{
				case 1:		cout << "Insertar: ";
							cin >> num;
							arbol.Insertar(num);
							arbol.write(cout);
					break;
				case 2:		cout << "Elimina: " << endl;
							cin >> num;
							arbol.Eliminar(num);
							arbol.write(cout);
					break;
			}
		cout << endl;
	}
}

void menu_estadistica()
{
	ArbolAVL<DNI> arbol;

	int i = 1;
	while(i != 0)
	{
		cout << "\33[4m" << "\33[1m" << "Modo Estadística" << "\33[0m" << endl;
		cout << "[0] Salir." << endl;
		cout << "[1] Sacar estadística." << endl;
		cin >> i;
		system("clear");
		if (i > 1 || i < 0)
			cout << "Opción incorrecta." << endl;
		else
			switch (i)
			{
				case 1:		int N, P;
							cout << "Introduzca el tamaño: " << endl;
							cin >> N;
							cout << "Introduzca el número de pruebas: " << endl;
							cin >> P;
							DNI secuencia[N*2];
							generar_s_aleatorio(secuencia, N*2, VALOR_MIN, VALOR_MAX);
							arbol.Estadistica(secuencia, N, P);
							system("clear");
							arbol.write_estadistica(cout,N,P);
							cout << endl;
					break;
			}
	}
	cout << endl;
}

int main()
{
	int i=1;
	while(i != 0)
	{
		cout << "\33[4m" << "\33[1m" << "Seleccione un modo:" << "\33[0m" << endl;
		cout << "[0] Salir." << endl;
		cout << "[1] Demostración." << endl;
		cout << "[2] Estadística." << endl;
		cin >> i;
		system("clear");
		if (i > 2 || i < 0)
			cout << "Opción incorrecta." << endl;
		else
			switch (i)
			{
				case 1:		system("clear");
							menu_demostracion();
					break;
				case 2:		system("clear");
							menu_estadistica();
					break;
			}
	}
	cout << endl;

	return 0;
}


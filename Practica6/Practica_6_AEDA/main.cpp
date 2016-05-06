#include <QCoreApplication>

#include <iostream>
#include "ABB/abb.h"

#include <vector>

using namespace std;

void menu_demostracion()
{
	ArbolBB<int> arbol;

	int num;

	int i = 1;
	while(i != 0)
	{
		cout << "\33[4m" << "\33[1m" << "Modo Demostración" << "\33[0m" << endl;
		cout << "[0] Salir." << endl;
		cout << "[1] Insertar." << endl;
		cout << "[2] Eliminar." << endl;
		cout << "[3] Mostrar." << endl;
		cin >> i;
		system("clear");
		if (i > 3 || i < 0)
			cout << "Opción incorrecta." << endl;
		else
			switch (i)
			{
				case 1:		cout << "Instertar: ";
							cin >> num;
							arbol.Insertar(num);
					break;
				case 2:		cout << "Elimina: " << endl;
							cin >> num;
							arbol.Eliminar(num);
					break;
				case 3:		system("clear");
							arbol.write(cout);
					break;
			}
		cout << endl;
	}
}

void menu_estadistica()
{
	int i = 1;
	while(i != 0)
	{
		cout << "\33[4m" << "\33[1m" << "Modo Estadística" << "\33[0m" << endl;
		cout << "[0] Salir." << endl;
		cout << "[1] Modificar." << endl;
		cin >> i;
		system("clear");
		if (i > 1 || i < 0)
			cout << "Opción incorrecta." << endl;
		else
			switch (i)
			{
				case 1:		cout << "Modificar case." << endl;
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


#ifndef CALCULADORA_NUMEROS_H
#define CALCULADORA_NUMEROS_H
#pragma once

#include "common.h"
#include "P3/number_list/number_list.h"
#include "P3/numbers/number_t.h"

class calculadora_numeros
{
	private:
		number_list list_;
	public:
		calculadora_numeros();
		calculadora_numeros(char* expresion);
		~calculadora_numeros();

		number_t* calcular_expresion();

};

#endif // CALCULADORA_NUMEROS_H

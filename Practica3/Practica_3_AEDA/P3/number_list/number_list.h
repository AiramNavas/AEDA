#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H
#pragma once

#include "common.h"
#include "VO/stack/stack.h"
#include "P3/numbers/number_t.h"
#include "P3/numbers/entero_t.h"
#include "P3/numbers/real_t.h"
#include "P3/numbers/rational_t.h"
#include "P3/numbers/complex_t.h"
#include "string.h"

class number_list
{
	private:
		AEDA::stack<number_t*> stack_;
	public:
		number_list();
		number_list(char* expresion);
		~number_list();

		bool is_number(char *pch);
		bool is_entero(const string& s);
		bool is_real(const string& s);
		bool is_rational(const string& s);
		bool is_complex(char *pch);


		ostream& write(ostream& os);
};

#endif // NUMBER_LIST_H

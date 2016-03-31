#include <iostream>
#include "VO/queue/queue.h"
#include "VO/vector/vector.h"
#include "P3/numbers/entero_t.h"
#include "P3/numbers/real_t.h"
#include "P3/numbers/rational_t.h"
#include "P3/numbers/complex_t.h"
#include "P3/numbers/number_t.h"
#include "VO/stack/stack.h"
#include "P3/number_list/number_list.h"

using namespace std;

// Modificacion: e la / 0 quiere que dividir por 1 o no y se devuelve el error.

int main()
{

//	char expresion[]="(3,9) (9,8) + 5 * 2.3 /";


//	number_list lista(expresion);
//	lista.write(cout);

//	number_t* a = new complex_t(6,6);
//	number_t* b = new entero_t(2);
//	cout << (*a)+b << endl;

//	number_t* x = new real_t (8.4);
//	number_t* y = new entero_t(3);
//	cout << y->toReal()+x << endl;


//	number_t* a = new real_t(5.4);
//	number_t* b = new entero_t(0);
//	try{
//		cout << (*a)/b << endl;
//	}
//	catch(division_zero_exception_t& e){
//		cout << e.what() << endl;
//	}

//	real_t a(3);
//	entero_t b(1);
//	try{
//		cout << a.toEntero()+b << endl;
//	}
//	catch (invalid_convertion_of_type& e){
//		cout << e.what() << endl;
//	}


//	try{
//		AEDA::stack<int> A(5);
//		A.pop();
//	}
//	catch (out_of_mem_exception_t& e){
//		cout << e.what() << endl;
//	}
//	catch (overflow_stack_exception_t& e){
//		cout << e.what() << endl;
//	}
//	catch (empty_stack_exception_t& e){
//		cout << e.what() << endl;
//	}


//	try{
//		AEDA::vector<int> A(5);
//		A[0]=1;
//		A[1]=2;
//		A[2]=3;
//		A[3]=4;
//		A[4]=5;
//		A[5]=6;

//		A.write(cout);
//	}
//	catch (high_index_exception_t& e){
//		cout << e.what() << endl;
//	}
//	catch (low_index_exception_t& e){
//		cout << e.what() << endl;
//	}
//	catch (bad_size_exception_t& e){
//		cout << e.what() << endl;
//	}


	return 0;
}


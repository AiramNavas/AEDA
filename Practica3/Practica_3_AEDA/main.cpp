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


int main()
{

	char expresion[]="3 4i + 1 1i + *";

	number_list lista(expresion);
	lista.write(cout);

	real_t a(3);
	entero_t b(1);
	try{
		cout << a.toEntero()+b << endl;
	}
	catch (invalid_convertion_of_type& e){
		cout << e.what() << endl;
	}

//	try{
//		AEDA::queue<int> A(5);
//		A.put(1);
//		A.put(1);
//		A.put(1);
//		A.put(1);
//		A.put(1);
//		A.put(1);
//	}
//	catch (out_of_mem_exception_t& e){
//		cout << e.what() << endl;
//	}
//	catch (overflow_queue_exception_t& e){
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


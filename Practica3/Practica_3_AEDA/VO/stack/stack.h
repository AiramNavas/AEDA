#pragma once
#include "common.h"
#include "Entities/list/dll.h"
#include "Entities/node/dll_int_node.h"
#include "Exceptions/exceptions.h"

#define MAX_STACK_SIZE 100

namespace AEDA {

	template <class TDATO>
	class stack {

		private:
			dll list_;
			int max_sz_;

		public:
			stack(void);
			stack(int size);
			virtual ~stack(void);

			void push(TDATO i);
			TDATO pop(void);

			int get_size(void);

			bool empty(void);

			ostream& write(ostream& os);
	};

	template <class TDATO>
	stack<TDATO>::stack(void):
		list_(),
		max_sz_(MAX_STACK_SIZE)
	{}

	template <class TDATO>
	stack<TDATO>::stack(int size):
		list_()
	{
		if (size >= MAX_STACK_SIZE || size <= 0)
			throw out_of_mem_exception_t();

		max_sz_ = size;
	}

	template <class TDATO>
	stack<TDATO>::~stack(void)
	{}

	template <class TDATO>
	void stack<TDATO>::push(TDATO i)
	{
		if (get_size() >= max_sz_)
			throw overflow_stack_exception_t();

		list_.insert_beginning(new dll_int_node<TDATO>(i));
	}

	template <class TDATO>
	TDATO stack<TDATO>::pop(void)
	{
		if (empty())
			throw empty_stack_exception_t();

		dll_int_node<TDATO>* n_aux = (dll_int_node<TDATO>*)(list_.extract_beginning());

		TDATO aux = n_aux->get_data();

		delete n_aux;

		return aux;
	}

	template <class TDATO>
	int stack<TDATO>::get_size(void)
	{
		return list_.get_size();
	}

	template <class TDATO>
	bool stack<TDATO>::empty(void)
	{
		return list_.empty();
	}

	template <class TDATO>
	ostream& stack<TDATO>::write(ostream& os)
	{
		if (empty())
			throw empty_stack_exception_t();

		list_.write(os);
		return os;
	}

}

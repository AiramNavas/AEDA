#pragma once
#include "../../Entities/list/dll.h"
#include "common.h"
#include "../../Entities/node/dll_int_node.h"
#include "Exceptions/exceptions.h"

#define MAX_QUEUE_SIZE 100

namespace AEDA {

	template <class TDATO>
	class queue {
		private:
			dll list_;
			int max_sz_;

		public:
			queue(void);
			queue(int size);
			~queue(void);

			void put(TDATO i);
			TDATO get(void);

			int get_size(void);

			bool empty(void);

			void insert_middle(TDATO c);

			ostream& write(ostream& os);
	};



	template <class TDATO>
	queue<TDATO>::queue(void):
		list_(),
		max_sz_(MAX_QUEUE_SIZE)
	{}

	template <class TDATO>
	queue<TDATO>::queue(int size):
		list_()
	{
		if (size >= MAX_QUEUE_SIZE || size <= 0)
			throw out_of_mem_exception_t();

		max_sz_ = size;
	}

	template <class TDATO>
	queue<TDATO>::~queue(void)
	{}

	template <class TDATO>
	void queue<TDATO>::put(TDATO i)
	{
		if (get_size() >= max_sz_)
			throw overflow_queue_exception_t();

		list_.insert_beginning(new dll_int_node<TDATO>(i));
	}

	template <class TDATO>
	TDATO queue<TDATO>::get(void)
	{
		if (empty())
			throw empty_queue_exception_t();

		dll_int_node<TDATO>* n_aux = (dll_int_node<TDATO>*)(list_.extract_end());

		TDATO aux = n_aux->get_data();

		delete n_aux;

		return aux;
	}

	template <class TDATO>
	int queue<TDATO>::get_size(void)
	{
		return list_.get_size();
	}

	template <class TDATO>
	bool queue<TDATO>::empty(void)
	{
		return list_.empty();
	}

	template <class TDATO>
	ostream& queue<TDATO>::write(ostream& os)
	{
		list_.write(os);
		cout << endl;
		return os;
	}

	template <class TDATO>
	void queue<TDATO>::insert_middle(TDATO c)
	{
		list_.insert_middle(new dll_int_node<TDATO>(c));
	}

}

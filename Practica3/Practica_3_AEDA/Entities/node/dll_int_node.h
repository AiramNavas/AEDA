#pragma once
#include "common.h"
#include "dll_node.h"

namespace AEDA {

	template <class TDATO>
	class dll_int_node: public dll_node {
		private:
			TDATO c_;
		public:
			dll_int_node(TDATO c);
			virtual ~dll_int_node(void);

			virtual ostream& write(ostream& os) const;

			TDATO get_data(void);
			void set_data(TDATO c);
	};


	template <class TDATO>
	dll_int_node<TDATO>::dll_int_node(TDATO c):
		dll_node(),
		c_(c)
	{}

	template <class TDATO>
	dll_int_node<TDATO>::~dll_int_node(void)
	{}

	template <class TDATO>
	ostream& dll_int_node<TDATO>::write(ostream& os) const
	{
		os << c_;
		return os;
	}

	template <class TDATO>
	TDATO dll_int_node<TDATO>::get_data(void)
	{
		return c_;
	}

	template <class TDATO>
	void dll_int_node<TDATO>::set_data(TDATO c)
	{
		c_ = c;
	}

}

#include "dll_int_node.h"

namespace AEDA {

    dll_int_node::dll_int_node(TDATO c):
    dll_node(),
    c_(c)
    {}

    dll_int_node::~dll_int_node(void)
    {}


    ostream& dll_int_node::write(ostream& os) const
    {
        os << c_;
        return os;
    }

    TDATO dll_int_node::get_data(void)
    {
        return c_;
    }

    void dll_int_node::set_data(TDATO c)
    {
        c_ = c;
    }
}
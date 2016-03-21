#include "dll_node.h"

namespace AEDA {

    dll_node::dll_node(void):
    next_(NULL),
    prev_(NULL)
    {}

    dll_node::~dll_node(void)
    {}


    void dll_node::set_next(dll_node* next)
    {
        next_ = next;
    }

    dll_node* dll_node::get_next(void) const
    {
        return next_;
    }


    void dll_node::set_prev(dll_node* prev)
    {
        prev_ = prev;
    }

    dll_node* dll_node::get_prev(void) const
    {
        return prev_;
    }
}

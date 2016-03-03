#include "stack.h"
#include "../../Entities/node/dll_int_node.h"

namespace AEDA {
    
    stack_TDATO::stack_TDATO(void):
    list_()
    {}

    stack_TDATO::~stack_TDATO(void)
    {}


    void stack_TDATO::push(TDATO i)
    {
        list_.insert_beginning(new dll_int_node(i));
    }

    TDATO stack_TDATO::pop(void)
    {
        dll_int_node* n_aux = (dll_int_node*)(list_.extract_beginning());
        
        TDATO aux = n_aux->get_data();
        
        delete n_aux;
        
        return aux;
    }


    bool stack_TDATO::empty(void)
    {
        return list_.empty();
    }


    ostream& stack_TDATO::write(ostream& os)
    {
        list_.write(os);
        return os;
    }
}

#pragma once
#include "common.h"
#include "../../Entities/list/dll.h"
#include "../../Entities/node/dll_int_node.h"


namespace AEDA {

template <class TDATO>

    class stack_TDATO {
    
        private:
            dll list_;
            
        public:
            stack_TDATO(void);
            virtual ~stack_TDATO(void);
            
            void push(TDATO i);
            TDATO pop(void);
            
            bool empty(void);
            
            ostream& write(ostream& os);
    };




template <class TDATO>
    stack_TDATO<TDATO>::stack_TDATO(void):
    list_()
    {}

template <class TDATO>
    stack_TDATO<TDATO>::~stack_TDATO(void)
    {}

template <class TDATO>
    void stack_TDATO<TDATO>::push(TDATO i)
    {
        list_.insert_beginning(new dll_int_node(i));
    }
template <class TDATO>
    TDATO stack_TDATO<TDATO>::pop(void)
    {
        dll_int_node* n_aux = (dll_int_node*)(list_.extract_beginning());

        TDATO aux = n_aux->get_data();

        delete n_aux;

        return aux;
    }

template <class TDATO>
    bool stack_TDATO<TDATO>::empty(void)
    {
        return list_.empty();
    }

template <class TDATO>
    ostream& stack_TDATO<TDATO>::write(ostream& os)
    {
        list_.write(os);
        return os;
    }




}

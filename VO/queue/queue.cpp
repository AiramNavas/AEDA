#include "queue.h"
#include "../../Entities/node/dll_int_node.h"

namespace AEDA {
    
    queue::queue(void):
    list_()
    {}

    queue::~queue(void)
    {}


    void queue::put(TDATO i)
    {
        list_.insert_beginning(new dll_int_node(i));
    }

    TDATO queue::get(void)
    {
        dll_int_node* n_aux = (dll_int_node*)(list_.extract_end());
        
        TDATO aux = n_aux->get_data();
        
        delete n_aux;
        
        return aux;
    }


    bool queue::empty(void)
    {
        return list_.empty();
    }


    ostream& queue::write(ostream& os)
    {
        list_.write(os);
        cout << endl;
        return os;
    }
    
    int queue::get_size(void)
    {
        return list_.get_size();
    }
    
    void queue::insert_middle(TDATO c)
    {
        list_.insert_middle(new dll_int_node(c));
    }
}

#pragma once
#include "../../Entities/list/dll.h"
#include "common.h"

namespace AEDA {
    class queue {
        private:
            dll list_;
            
        public:
            queue(void);
            ~queue(void);
            
            void put(TDATO i);
            TDATO get(void);
            
            bool empty(void);
            
            int get_size(void);
            void insert_middle(TDATO c);
            
            ostream& write(ostream& os);
    };
}

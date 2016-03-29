#pragma once
#include "common.h"
#include "dll.h"

namespace AEDA {
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
}

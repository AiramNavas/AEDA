#include <iostream>
#include "VO/queue/queue.h"
#include "VO/stack/stack.h"
#include "VO/vector/vector.h"

using namespace std;

int main()
{
    AEDA::queue A;

    for (int i=0; i < 4; i++)
    {
        A.put(2+i);
    }

    A.write(cout);

    cout << A.get_size() << endl;

    TDATO B = 9;

    A.insert_middle(B);

    A.write(cout);

    return 0;
}


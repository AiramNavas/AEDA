#ifndef DNI_H
#define DNI_H

#include <iostream>
using namespace std;

typedef unsigned int DNI_type;

class DNI
{
	private:
		DNI_type DNI_;
	public:
		DNI();
		DNI(DNI_type DNI_number);
		DNI(const DNI& DNI_number);
		~DNI();

		DNI_type get_DNI() const;

		ostream& write(ostream& os) const;

		bool operator ==(const DNI& DNI_number) const;
		bool operator <(const DNI& DNI_number) const;
};

inline ostream& operator <<(ostream& os, const DNI& DNI_number)
{
	DNI_number.write(os);
	return os;
}

#endif // DNI_H

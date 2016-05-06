#include "dni.h"
#include "Exceptions/exceptions.h"

DNI::DNI(){}

DNI::DNI(DNI_type DNI_number)
{
	if (DNI_number >= 30000000 && DNI_number <= 80000000)
		DNI_ = DNI_number;
	else
		throw invalid_dni_t();
}

DNI::DNI(const DNI& DNI_number)
{
	DNI_ = DNI_number.DNI_;
}

DNI::~DNI(){}

DNI_type DNI::get_DNI() const
{
	return DNI_;
}

ostream& DNI::write(ostream& os) const
{
	os << DNI_;
	return os;
}

bool DNI::operator ==(const DNI& DNI_number) const
{
	return (DNI_ == DNI_number.DNI_);
}

bool DNI::operator <(const DNI& DNI_number) const
{
	return (DNI_ < DNI_number.DNI_);
}

bool DNI::operator !=(const DNI& DNI_number) const
{
	return (DNI_ != DNI_number.DNI_);
}

bool DNI::operator >(const DNI& DNI_number) const
{
	return (DNI_ > DNI_number.DNI_);
}

bool DNI::operator <=(const DNI& DNI_number) const
{
	return (DNI_ <= DNI_number.DNI_);
}

bool DNI::operator >=(const DNI& DNI_number) const
{
	return (DNI_ >= DNI_number.DNI_);
}

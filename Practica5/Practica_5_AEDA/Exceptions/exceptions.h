#ifndef EXCEPTIONS
#define EXCEPTIONS

#pragma once
#include <exception>


class exception_t{
	public:
		virtual const char* what() const throw()=0;
};


class invalid_dni_t : public exception_t{
	public:
		virtual const char* what() const throw(){
			return "Invalid DNI.";
		}
};

#endif // EXCEPTIONS


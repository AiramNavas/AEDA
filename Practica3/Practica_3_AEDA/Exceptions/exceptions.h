#ifndef EXCEPTIONS
#define EXCEPTIONS

#pragma once
#include <exception>


class exception_t{
	public:
		virtual const char* what() const throw()=0;
};


class low_index_exception_t : public exception_t{
	public:
		virtual const char* what() const throw(){
			return "Low index.";
		}
};


class high_index_exception_t : public exception_t{
	public:
		virtual const char* what() const throw(){
			return "High index.";
		}
};


class bad_size_exception_t : public exception_t{
	public:
		virtual const char* what() const throw(){
			return "Error size.";
		}
};


class out_of_mem_exception_t : public exception_t{
	public:
		virtual const char* what() const throw(){
			return "Out of memory.";
		}
};


class writing_empty_exception_t : public exception_t{
	public:
		virtual const char* what() const throw(){
			return "Traying to wrinte in white.";
		}
};


class empty_stack_exception_t : public exception_t{
	public:
		virtual const char* what() const throw(){
			return "ERROR: The stack is empty.";
		}
};


class overflow_stack_exception_t : public exception_t{
	public:
		virtual const char* what() const throw(){
			return "ERROR: The stack is full.";
		}
};

class empty_queue_exception_t : public exception_t{
	public:
		virtual const char* what() const throw(){
			return "ERROR: The queue is empty.";
		}
};


class overflow_queue_exception_t : public exception_t{
	public:
		virtual const char* what() const throw(){
			return "ERROR: The queue is full.";
		}
};


class division_zero_exception_t: public exception_t{
	public:
		virtual const char* what() const throw(){
			return "ERROR: Cant divide by 0.";
		}
};

class negative_square_root_exception_t: public exception_t{
	public:
		virtual const char* what() const throw(){
			return "ERROR: Cant do the square root of a negative number.";
		}
};

class invalid_convertion_of_type: public exception_t{
	public:
		virtual const char* what() const throw(){
			return "ERROR: Invalid convertion of type.";
		}
};


#endif // EXCEPTIONS


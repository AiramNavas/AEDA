#include "number_list.h"

number_list::number_list():
stack_()
{}

number_list::number_list(char* expresion)
{
	char *pch = NULL;
	pch = strtok (expresion, " ");

	while (pch != NULL){

		if (is_number(pch) && is_entero(pch)){
			int aux = atoi(pch);
			number_t* n_aux = new entero_t (aux);
			stack_.push(n_aux);
		}
		else if (is_number(pch) && is_real(pch)){
			double aux = atof(pch);
			number_t* n_aux = new real_t (aux);
			stack_.push(n_aux);
		}
		else if (is_number(pch) && is_rational(pch)){
			float aux = atof(pch);
			number_t* n_aux = new rational_t (aux);
			stack_.push(n_aux);
		}
		else if (is_number(pch) && is_complex(pch)){
			double p_real, p_img;
			sscanf(pch,"(%lf,%lf)",&p_real,&p_img);
			number_t* n_aux = new complex_t (p_real,p_img);
			stack_.push(n_aux);
		}

		pch = strtok (NULL, " ");
	}
}

number_list::~number_list()
{}

bool number_list::is_number(char *pch){
	if (( ((*pch)>='0') && ((*pch)<='9') ) || ( ( (pch[1])>='0') && ((pch[1])<='9') ) )
		return true;
	else
		return false;
}

bool number_list::is_entero(const string& s){
		size_t found = s.find(".");
		if (found != string::npos)
			return false;
		else if (s[0] != '(')
			return true;
		else
			return false;
}

bool number_list::is_real(const string& s){
		size_t found = s.find(".");
		return (found != string::npos);
}

bool number_list::is_rational(const string& s){
		size_t found = s.find(".");
		return (found != string::npos);
}

bool number_list::is_complex(char *pch){
		if((pch[0])=='(')
			return true;
		else
			return false;
}

ostream& number_list::write(ostream& os)
{
	stack_.write(os);
	return os;
}

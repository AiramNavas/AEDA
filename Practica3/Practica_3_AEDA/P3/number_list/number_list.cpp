#include "number_list.h"

number_list::number_list():
stack_()
{}

number_list::number_list(char* expresion)
{
	char *pch = NULL;
	pch = strtok (expresion, " ");

	while (pch != NULL){

		if (is_number(pch) && !is_complex(pch)){
			float aux = atof(pch);
			number_t* n_aux = new rational_t (aux);
			stack_.push(n_aux);
		}
		else if (is_number(pch) && is_complex(pch)){
			float aux = atof(pch);
			number_t* n_aux = new complex_t (0,aux);
			stack_.push(n_aux);
		}

//		if (!is_complex(pch) && es_numero(pch)){
//			float p_real = atof (pch);
//			number_t* aux2(p_real);
//			stack_.push(aux2);
//		}
//		else if(is_complex(pch) && es_numero(pch)){
//			float p_imag = atof (pch);
//			number_t* aux3(0,p_imag);
//			stack_.push(aux3);
//		}

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

bool number_list::is_complex(const string& s){
		size_t found = s.find("i");
		return (found != string::npos);
}

ostream& number_list::write(ostream& os)
{
	stack_.write(os);
	return os;
}

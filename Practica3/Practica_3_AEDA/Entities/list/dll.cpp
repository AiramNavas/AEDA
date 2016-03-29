#include "dll.h"

namespace AEDA {

	dll::dll(void):
		beginning_(NULL),
		end_(NULL)
	{}

	dll::~dll(void)
	{
		while (beginning_ != NULL){
			dll_node* aux = beginning_;
			beginning_ = beginning_->get_next();
			delete aux;
		}
	}



	void dll::insert_beginning(dll_node* n)
	{
		n->set_next(beginning_);
		n->set_prev(NULL);

		if(end_ == NULL)
			end_ = n;
		else
			beginning_->set_prev(n);

		beginning_ = n;
	}

	dll_node* dll::extract_beginning(void)
	{
		dll_node* aux = beginning_;
		beginning_ = beginning_->get_next();

		aux->set_next(NULL);
		aux->set_prev(NULL);

		if (beginning_ == NULL)
			end_ = NULL;

		return aux;
	}


	void dll::insert_end(dll_node* n)
	{
		n->set_next(NULL);
		n->set_prev(end_);

		if (end_ != NULL)
			end_->set_next(n);
		else
			beginning_ = n;

		end_ = n;
	}

	dll_node* dll::extract_end(void)
	{
		dll_node* aux = end_;

		end_ = end_->get_prev();

		aux->set_next(NULL);
		aux->set_prev(NULL);

		if (end_ == NULL)
			beginning_ = NULL;
		else
			end_->set_next(NULL);

		return aux;
	}


	bool dll::empty(void) const
	{
		return (beginning_ == NULL);
	}

	ostream& dll::write(ostream& os) const
	{
		dll_node* aux = beginning_;

		while (aux != NULL){
			aux->write(os);
			aux = aux->get_next();
		}os << endl;
	}

	int dll::get_size()
	{
		int sz=0;
		dll_node* move;
		move = beginning_;

		if (beginning_ != NULL)
		{
			while (move != NULL)
			{
				sz++;
				move = move->get_next();
			}
		}
		delete move;
		return sz;
	}

	void dll::insert_middle(dll_node* n)
	{
		int sz = get_size()/2;

		if (beginning_ != NULL){

			dll_node* aux1 = beginning_;

			for (int i=1; i < sz; i++)
			{
				aux1 = aux1->get_next();
			}

			dll_node* aux2 = aux1;
			aux2 = aux2->get_next();

			n->set_prev(aux1);
			n->set_next(aux2);

			aux1->set_next(n);
			aux2->set_prev(n);
		}
	}
}




















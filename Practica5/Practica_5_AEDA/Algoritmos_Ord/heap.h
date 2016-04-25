#ifndef HEAP
#define HEAP


#include <iostream>
#include "Ordenacion/ordenacion.h"

using namespace std;

template <class T>
class heap
{
	private:
		int contador_;
	public:
		heap();
		~heap();

		int get_contador();
		void algoritmo(T* secuencia, int tam, int metodo);

		ostream& write(ostream& os, T* secuencia, int tam, int j, int k);
};

template <class T>
heap<T>::heap():
	contador_(0)
{}

template <class T>
heap<T>::~heap()
{
	contador_ = 0;
}

template <class T>
int heap<T>::get_contador()
{
	return contador_;
}

template <class T>
void heap<T>::algoritmo(T* secuencia, int tam, int metodo)
{
	contador_ = 0;
	for(int k = tam; k > 0; k--)
	{
		for(int i = 1; i <= k; i++)
		{
			T aux = secuencia[i-1];
			int j=i/2;
			while(j > 0)
			{
				if (metodo == 1){
					write(cout, secuencia, tam, j-1, i-1);
					cin.ignore();
				}
				else
					contador_++;

				if (secuencia[j-1] < aux){
					secuencia[i-1] = secuencia[j-1];
					i=j;
					j=j/2;
				}
				else
					break;
			}
			secuencia[i-1] = aux;
		}
		T temp = secuencia[0];
		secuencia[0] = secuencia[k-1];
		secuencia[k-1] = temp;
	}
	write(cout, secuencia, tam, -1, -1);
	/*
 *
 *  int A[max],j,item,temp,i,k,n;
	cout<<"Ingresa la cantidad de elementos del arreglo: ";
	cin>>n;
	for(i=1;i<=n;i++)
	cin >> A[i];

	for(k=n;k>0;k--)
	{
		for(i=1;i<=k;i++)
		{
			item=A[i];
			j=i/2;
			while(j>0 && A[j]<item)
			{
				A[i]=A[j];
				i=j;
				j=j/2;
			}
			A[i]=item;
		}
		temp=A[1];
		A[1]=A[k];
		A[k]=temp;
	}
	cout<<"El orden es:"<<endl;
	for(i=1;i<=n;i++)
	cout<<A[i] << endl;
	return 0;
 *
 *
 *
# heapify
for i = n/2:1, sink(a,i,n)
→ invariant: a[1,n] in heap order

# sortdown
for i = 1:n,
	swap a[1,n-i+1]
	sink(a,1,n-i)
	→ invariant: a[n-i+1,n] in final position
end

# sink from i in a[1..n]
function sink(a,i,n):
	# {lc,rc,mc} = {left,right,max} child index
	lc = 2*i
	if lc > n, return # no children
	rc = lc + 1
	mc = (rc > n) ? lc : (a[lc] > a[rc]) ? lc : rc
	if a[i] >= a[mc], return # heap ordered
	swap a[i,mc]
	sink(a,mc,n)
*/
}

template <class T>
ostream& heap<T>::write(ostream& os, T* secuencia, int tam, int j, int k)
{
	for (int i = 0; i < tam; i++)
	{
		if ((i != j) && (i != k))
			os << secuencia[i] << " ";
		else
			cout << "[" << secuencia[i] << "] ";
	}
	os << endl;
	return os;
}


#endif // HEAP


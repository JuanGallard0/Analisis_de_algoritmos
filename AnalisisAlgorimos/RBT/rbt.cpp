#include<iostream>

using namespace std;

enum color{BLACK, RED};
enum side{LEFT, RIGHT};

typedef struct nodo
{
	int dato;
	color col;
	nodo* parent;
	nodo* izq;
	nodo* der;
}nodo;

nodo* crear()
{
	return nullptr;
}

bool esta_vacio(nodo* T)
{
	return (!T)? true:false;
}

nodo* crear_nodo(nodo* T, int n)
{
	nodo* nuevo = new nodo;
	nuevo->dato = n;
	nuevo->parent = nullptr;
	nuevo->izq = nullptr;
	nuevo->der = nullptr;
	return nuevo;
}

void mostrar_in_order(nodo* T)
{
	if (esta_vacio(T))
	{
		cout<<"nil"<<"-"<<BLACK<<endl;
		return;
	}
	mostrar_in_order(T->izq);
	cout<<T->dato<<"-"<<T->col<<endl;
	mostrar_in_order(T->der);
}

void mostrar_pre_order(nodo* T)
{
	if (esta_vacio(T))
	{
		cout<<"nil"<<"-"<<BLACK<<endl;
		return;
	}
	cout<<T->dato<<"-"<<T->col<<endl;
	mostrar_in_order(T->izq);
	mostrar_in_order(T->der);
}

void mostrar_post_order(nodo* T)
{
	if (esta_vacio(T))
	{
		cout<<"nil"<<"-"<<BLACK<<endl;
		return;
	}
	mostrar_in_order(T->izq);
	mostrar_in_order(T->der);
	cout<<T->dato<<"-"<<T->col<<endl;
}

bool esta(nodo* T, int n)
{
	if (!T)
		return false;
	if (T->dato == n)
		return true;
	if (n < T->dato)
		return esta(T->izq, n);
	else 
		return esta(T->der, n);
}

int in_order_successor(nodo * T)
{
	if (!T->izq)
		return T->dato;
	else 
		return in_order_successor(T->izq);
}

void destruir_arbol(nodo* T)
{
	if (!T)
		return;
	destruir_arbol(T->izq);
	destruir_arbol(T->der);
	delete T;
}

void rotar_izq(nodo*& A, nodo*& B)
{
	nodo* Adad = A->parent;
	nodo* Bizq = B->izq;
	if (B->izq)
		Bizq->parent = A;
	B->izq = A;
	A->der = Bizq;
	A->parent = B;
	B->parent = Adad;
	if (Adad)
	{
		if (Adad->izq == A)
			Adad->izq = B;
		else
			Adad->der = B;
	}
}

void rotar_der(nodo*& A, nodo*& B)
{
	nodo* Adad = A->parent;
	nodo* Bder = B->der;
	if (Bder)
		Bder->parent = A;
	B->der = A;
	A->izq = Bder;
	A->parent = B;
	B->parent = Adad;
	if (Adad)
	{
		if (Adad->izq == A)
			Adad->izq = B;
		else 
			Adad->der = B;
	}
}

nodo* get_root(nodo* n)
{
	if (!n->parent)
		return n;
	else 
		return get_root(n->parent);
}

void fix_root(nodo*& T, nodo*& recent)
{
	nodo* root_actual = get_root(recent);
	if (T != root_actual)
		T = root_actual;
}

void fix_double_red(nodo*& T, nodo*& recent)
{
	side s1, s2;
	nodo* daddy;
	nodo* grandpa;
	nodo* uncle;
	
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
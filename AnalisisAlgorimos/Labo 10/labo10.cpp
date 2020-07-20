#include<iostream>

using namespace std;

typedef struct nodo
{
	int dato;
	nodo* izq;
	nodo* der;
}nodo;

nodo* crearNodo(nodo* T, int n)
{
	nodo* temp = new nodo;
	temp->dato = n;
	temp->izq = nullptr;
	temp->der = nullptr;
	return temp;
}

nodo* insertar(nodo* T, int n)
{
	if (!T)
		return crearNodo(T, n);
	if (n < T->dato)
		T->izq = insertar(T->izq, n);
	else 
		T->der = insertar(T->der, n);
	return T;
}

void in_order(nodo* T)
{
	if (!T)
		return;
	in_order(T->izq);
	cout<<T->dato<<endl;
	in_order(T->der);
}

nodo* valorMinimo(nodo* T) 
{ 
    nodo* temp = T; 
    while (temp and temp->izq) 
        temp = temp->izq; 
    return temp; 
} 

nodo* borrarNodo(nodo* T, int n) 
{ 
    if (!T) return T; 

    if (n < T->dato) 
        T->izq = borrarNodo(T->izq, n); 
    else if (n > T->dato) 
        T->der = borrarNodo(T->der, n); 

    else
    { 
        if (!T->izq) 
        { 
            nodo* temp = T->der; 
            delete(T); 
            return temp; 
        } 
        else if (!T->der) 
        { 
            nodo* temp = T->izq;
            delete(T); 
            return temp; 
        }  
        nodo* temp = valorMinimo(T->der); 
        T->dato = temp->dato; 
        T->der = borrarNodo(T->der, temp->dato); 
    } 
    return T; 
} 

int main(void)
{
	nodo* T = nullptr;
	T = insertar(T, 8);
	T = insertar(T, 10);
	T = insertar(T, 13);
	T = insertar(T, 3);
	T = insertar(T, 4);
	T = insertar(T, 6);
	T = insertar(T, 7);
	T = insertar(T, 14);
	T = insertar(T, 1);
	in_order(T);
	borrarNodo(T, 4);
	borrarNodo(T, 8);
	borrarNodo(T, 13);
	cout<<endl;
	in_order(T);
	return 0;
}
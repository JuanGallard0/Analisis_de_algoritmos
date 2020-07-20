#include<iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo * sig;
}*inicio;

class Pila
{
public:

	Nodo* crearNodo(int valor)
	{
		Nodo *n = new Nodo;
		n -> dato = valor;
		n -> sig = nullptr;
		return n;
	}

	void push(int valor)
	{
		Nodo *n = crearNodo(valor);
		n -> sig = inicio;
		inicio = n;
	}

	void pop()
	{
		Nodo *temp = inicio;
		inicio = inicio -> sig;
		free(temp);
	}

	void mostrarPila()
	{
		Nodo *temp = inicio;
		if (!inicio)
		{
			cout<<"Pila vacia"<<endl;
		}
		else
		{
			while(temp)
			{
				cout<<temp -> dato<<endl;
				temp = temp -> sig;
			}
		}
	}

	void guardarEntero(int x)
	{
		while (x > 0)
		{
			push(x % 10);
			x /= 10;
		}
	}
};

int main(void)
{
	Pila stack;
	int entero;
	cout<<"Introduzca numero entero: ";
	cin>>entero;
	stack.guardarEntero(entero);
	cout<<endl<<"PILA:"<<endl;
	stack.mostrarPila();
	return 0;
}
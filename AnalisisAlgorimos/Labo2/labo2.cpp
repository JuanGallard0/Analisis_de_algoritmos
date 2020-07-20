#include<iostream>
#include<string>

using namespace std;

struct alumno
{
	string nombre;
	int edad;
	char sexo;

	alumno(){}
	alumno(string N, int E, char S)
	{
		nombre = N;
		edad = E;
		sexo = S;
	}
};

struct Nodo
{
	alumno dato;
	Nodo *sig;
}*inicio;

class ListaEnlazada
{
public:

	ListaEnlazada()
	{
		inicio = nullptr;
	}

	Nodo* crearNodo(alumno valor)
	{
		Nodo *n = new Nodo;
		n -> dato = valor;
		n -> sig = nullptr;
		return n;
	}

	void agregarElemento(alumno valor)
	{
		Nodo *n = crearNodo(valor), *temp;
		if (!inicio)
		{
			inicio = n;
		}
		else
		{
			for (temp = inicio; temp -> sig; temp = temp -> sig);
			temp -> sig = n;
		}
	}

	void mostrarLista()
	{
		Nodo *temp = inicio;
		if (!inicio)
		{
			cout<<"La lista no posee elementos"<<endl;
		}
		else
		{
			while (temp)
				{
					cout<<temp -> dato.nombre<<", "<<temp -> dato.edad<<", "<<temp -> dato.sexo<<", "<<endl;
					temp = temp -> sig;
				}
		}
	}
	void ordenarGenero()
	{
		Nodo *temp = inicio, aux;
		while (temp)
		{
			
		}
	}
};

int main(void)
{
	alumno A("Cecil", 17, 'M');
	alumno B("Edgar", 16, 'M');
	alumno C("Lia", 19, 'F');
	alumno D("Cami", 18, 'F');

	ListaEnlazada alumnos;
	alumnos.agregarElemento(A);
	alumnos.agregarElemento(B);
	alumnos.agregarElemento(C);
	alumnos.agregarElemento(D);

	alumnos.mostrarLista();
	alumnos.ordenarGenero();
	alumnos.mostrarLista();

	cout<<endl<<"Transformacion de lista."<<endl<<endl;
	return 0;
}
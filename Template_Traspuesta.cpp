#include <iostream>
using namespace std;

template<class T>
class Matriz{
	private:
		T dato; //tipo de elemento genérico T
		T **ptrMatriz; //matriz de punteros de tipo T
		int fila, columna; //filas y columnas
	public:
		Matriz(int, int); //constructor con inicializacion
		void llenarMatriz(string); //para leer una matriz genércia de tipo T
		void imprimeMatriz(string); //para imprimir una matriz genérica de tipo T
		Matriz<T> operator^(Matriz &matriz); //sobrecarga del operador ^
		int getFila();//getters necesarios
		int getColumna();//getters necesarios
};

template<typename T>//metodo gettter
int Matriz<T>::getFila(){
	return fila;
}

template<typename T>//metodo gettter
int Matriz<T>::getColumna(){
	return columna;
}

template<typename T>//constructor de la clase Matriz
Matriz<T>::Matriz(int filas, int columnas){
	fila = filas;
	columna = columnas;
	ptrMatriz = new T*[fila]; //creamos un puntero T a filas;
	for (int i=0; i<fila; i++) {
		ptrMatriz[i] = new T[columna]; //creamos un puntero T a columnas;
	}
}

template<typename T>//Llenar una matriz genérica desde el teclado
void Matriz<T>::llenarMatriz(string nombreMatriz){
	cout<<endl<<">> Asignando datos "<<nombreMatriz<<endl;
	for (int i=0; i<getFila(); i++){
		for (int j=0; j<getColumna(); j++){
			cout<<"Ingresa un elemento en la posicion["<<i+1<<"]["<<j+1<<"]: ";
			cin>>dato;
			ptrMatriz[i][j] = dato;
		}
	}
}

template<typename T>//imprimir la Matriz
void Matriz<T>::imprimeMatriz(string nombreMatriz){
	cout<<endl<<">> Matriz "<<nombreMatriz<<endl;
	for(int i=0; i<getFila(); i++){
		for(int j=0; j<getColumna(); j++){
			cout << ptrMatriz[i][j] << " ";
		}
		cout<<endl;
	}
	cout<<endl;
}

template<typename T>//matriz sobreoperada 
Matriz<T> Matriz<T>::operator^(Matriz &matriz){
	Matriz res(columna, fila);
	for(int i=0; i<getFila(); i++){
		for(int j=0; j<getColumna(); j++){
			res.ptrMatriz[j][i] = ptrMatriz[i][j];
		}
	}	
	return res;
}

int main(){
	int filas,columnas;
	cout<<"Ingrese las filas: ";
	cin>>filas;
	cout<<"Ingrese las columnas: ";
	cin>>columnas;	
	//asigna la matriz de tipo entero	
	Matriz<int> mA(filas, columnas);
	Matriz<int> mB(columnas, filas);
	Matriz<int> mC(columnas, filas);
	//llena y muestra la matriz
	mA.llenarMatriz("mA");
	mA.imprimeMatriz("mA");
	//hace la operacion sobrecargada
	mC=mA^mB;
	mC.imprimeMatriz("SOBREOPERADA mA^mB");
	return 0;
}
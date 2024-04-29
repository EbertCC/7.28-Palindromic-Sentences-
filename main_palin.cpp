#include <iostream>
#include <string>

using namespace std;

// funcion que indique di es letra
bool es_letra(char letra){
	
	char letras[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for(int i = 0 ; i < 52 ; i ++){
		if(letra == letras[i] ){
			return true;
		}
	}
	return false;
}

// creo una funcion recursiva bool
	
bool Es_palin(const string& cadena, int inicio, int fin) {
	// caso base es cuando la posicion 0 de mi oracion y size.otracion - 1 se comparan  
	if (inicio >= fin) {
		return true;
	}
	// verifico si es un letra inicio de mi oracion, si no salta al siguiente 
	if (es_letra(cadena[inicio]) == false ) {
		return Es_palin(cadena, inicio + 1, fin);
	}
	// verifico si es un letra final de mi oracion , si no salta al siguiente 
	if (es_letra(cadena[fin])== false) {
		return Es_palin(cadena, inicio, fin - 1);
	}
	
	// veririco si las letras son diferentes no importa si son mayusculas o minisculas
	//tolower convierte a minuscula
	if (tolower(cadena[inicio]) != tolower(cadena[fin])) {
		return false;
	}
	
	// si cumple paso a las siguientes posiciones 
	return Es_palin(cadena, inicio + 1, fin - 1);
}

int main() {
	string oracion = "red roses run no risk, sir, on nurses order.";
	
	cout<<oracion<<endl;

	// uso funcon string <length> idica tamaño, -1
	if (Es_palin(oracion,0, oracion.length() - 1) == true ) {
		cout << "la oracion es palindromo " << endl;
	} else {
		cout << "la oracion no es palindromo " << endl;
	}
	
	return 0;
}

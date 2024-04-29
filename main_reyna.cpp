#include <iostream>
using namespace std;


//lleno de 0 mi matriz 8*8
void LLenar_ceros_matriz(int Matriz[][8],int filas,int columnas){
	
    int val = 0;
	for( int i = 0; i<filas ; i++){
		for( int j = 0; j<columnas; j++){
			Matriz[i][j] = val;
            //val++;
		}
	}
	
}

//verifico si la posicion del tablero ingresado [pos_fil][pos_col]
// no colisione con otra reyna(1)
bool verificar(int Matriz[][8],int pos_fil , int pos_col){
    const int Tamanio_matriz = 8;
    
    int cont_filas = 0 ; 
    int cont_columnas = 0;

    // suma fila y columna de la pos [pos_fil][pos_col]
    for(int i = 0 ; i < Tamanio_matriz ; i++){
        for(int j = 0 ; j < Tamanio_matriz ; j++){
            if( i == pos_fil){
                cont_filas = cont_filas + Matriz[pos_fil][j];
            }
            if( j == pos_col){
                cont_columnas = cont_columnas + Matriz[i][pos_col];
            }
        }
    }
    //cout<<"suma de la fila "<< pos_fil <<" es : "<<cont_filas <<endl;
    //cout<<"suma de la columna "<< pos_col <<" es : "<<cont_columnas <<endl;

    //suma de su diagonal -> secundaria

    int cont_incio_2 = 0;
    while( (pos_fil-cont_incio_2 != 0  ) && (pos_col+cont_incio_2 !=7 ) ){

        cont_incio_2 = cont_incio_2 + 1 ;
    }
    //cout<<"caso base de pos "<<pos_fil<<" - "<<pos_col<<" : "<<pos_fil - cont_incio_2 << pos_col + cont_incio_2 <<endl;
   
    int cont_temp_2 = 0 ; 
    int suma_diagonal_secundaria = 0 ;

    for(int i = 0 ; i < Tamanio_matriz ; i++){
        for(int j = 0 ; j < Tamanio_matriz ; j++){

            if( (i == pos_fil - cont_incio_2 + cont_temp_2 ) && (j == pos_col + cont_incio_2 - cont_temp_2) ){

                suma_diagonal_secundaria = suma_diagonal_secundaria + Matriz[i][j];
                cont_temp_2 = cont_temp_2 + 1 ;
            }
        }
        //cont_temp_2 = cont_temp_2 + 1 ;
    }  
   

    //cout<<"Suma diagonal secundatia es "<<pos_fil<<" y "<<pos_col<<" : "<<suma_diagonal_secundaria<<endl;


                                                                                                        

    //suma de su diagonal <- principal 

    int cont_incio = 0;
    while( (pos_fil-cont_incio != 0  ) && (pos_col-cont_incio !=0 ) ){

        cont_incio = cont_incio + 1 ;
    }

    //cout<<"caso base de pos "<<pos_fil<<" - "<<pos_col<<" : "<<pos_fil-cont_incio << pos_col - cont_incio <<endl;
    
    int cont_temp = 0 ;
    int suma_diagonal_princial = 0;
    for( int i = 0 ; i < Tamanio_matriz ; i++){
        for( int j = 0 ; j < Tamanio_matriz ; j++){

            if((i == pos_fil-cont_incio+cont_temp) && (j == pos_col - cont_incio+cont_temp) ){
                suma_diagonal_princial = suma_diagonal_princial + Matriz[i][j];
                cont_temp = cont_temp + 1 ;
            }
        }
        //cont_temp = cont_temp + 1 ;
    }

    //cout<<"Suma diagonal principal de "<<pos_fil<<" y "<<pos_col<<" : "<<suma_diagonal_princial;
    if((cont_filas == 0 ) && (cont_columnas == 0 ) && (suma_diagonal_secundaria == 0) && (suma_diagonal_princial == 0) ){
        return true;
    } else {
        return false;
    }

}

//funcion imprimir matriz
void Imprimir_Matriz(int Matriz [][8],int filas,int columnas){
	
	for(int i = 0; i<filas;i++){
		for(int j = 0; j<columnas;j++){
			cout<<Matriz[i][j]<<"      ";
		}
		cout<<endl;
        cout<<endl;
	}
}

// verifica si as ingreasdo 8 reynas 
bool Verificar_8_reynas_completar(int matriz[][8] , int filas , int columnas){
    int cont = 0 ; 
    for(int i = 0 ; i < filas ; i ++){
        for(int j = 0 ; j <columnas ; j++){
            cont = cont + matriz[i][j]; 
        }
    }

    if(cont == 8){
        return true;
    } else {
        return false;
    }
}


int main() {
	
	const int Filas = 8;
	const int Columnas = 8;
	int MATRIZ_PRINCIPAL[Filas][Columnas];
	LLenar_ceros_matriz(MATRIZ_PRINCIPAL,Filas,Columnas);
	Imprimir_Matriz(MATRIZ_PRINCIPAL,Filas,Columnas);
    verificar(MATRIZ_PRINCIPAL,3,5);

    int opc ;
    cout<<" --- Eliga una opcion ---" <<endl;
    cout<<" 1) ingresar manualmente "<<endl;
    //cout<<" 2) imprimir caso aleaorio"<<endl;
    cin>>opc;


    if(opc == 1 ){
        
        int num;
        cout<<" Ingrese ficha 1(reyna) y 0 (vacio) "<<endl;
        for(int i = 0 ; i < Filas ; i++){
            for( int j = 0 ; j < Columnas ; j++){
                
                do{
                    cout << "Ingrese elemento [" << i << "][" << j << "] : ";
                    cin>> num;

                    if(num == 0){
                        MATRIZ_PRINCIPAL[i][j] = 0 ;
                        //continue;
                    }

                    if(num == 1){
                        if(verificar(MATRIZ_PRINCIPAL,i,j) == true){
                            MATRIZ_PRINCIPAL[i][j] = 1 ;
                        } else {
                            cout<<"Ese espacio no puede ir una reyna se relleno con 0"<<endl;
                            MATRIZ_PRINCIPAL[i][j] = 0 ;
                        }
                    }

                    Imprimir_Matriz(MATRIZ_PRINCIPAL,Filas,Columnas);

                    
            

                }while (num != 1 && num != 0 );
                
                

            }
        }
        if(Verificar_8_reynas_completar(MATRIZ_PRINCIPAL,Filas,Columnas) == true){
            cout<<"Resolvio un caso del acertijo"<<endl;
        } else{
            cout<<"No pudo resolver el acerijo"<<endl;
        }
    }
  
	
	return 0;
}


/*

0  0  0  1  0  0  0  0
0  0  0  0  0  0  1  0
0  0  1  0  0  0  0  0
0  0  0  0  0  0  0  1
0  1  0  0  0  0  0  0
0  0  0  0  1  0  0  0
1  0  0  0  0  0  0  0
0  0  0  0  0  1  0  0


*/
#include<iostream>
using namespace std;
int const filas=4;
int const columnas=5;
void limpiarMatrices(bool disponibilidad[filas][columnas],int pesos[filas][columnas]);
void imprimirMatrizBooleana(bool matriz[filas][columnas]);
void imprimirMatrizTexto(string matriz[filas][columnas]);
void imprimirMatrizEnteros(int matriz[filas][columnas]);
string marcaMasPesada(int pesos[filas][columnas],string marcas[filas][columnas]);

int main(){
	string marcaPesada="";
	bool disponibilidad[filas][columnas];
	string marcas[filas][columnas], nomPuertos, nomMayorPeso, marca, tipo, nomMenorPeso;
	int pesos[filas][columnas], puertos, cantContenedor, p,q, fila, columna, peso, sumatory = 0, sumatoryArticulo = 0, acumPeso = 0, sumatoryPuer = 0, acumPuer = 0, mayorPeso = 0, menorPeso = 25000;
	int mayorCarga = 0, auxMayorCarga = 25000, filaCarga;
	float promPeso, promPuer;
	string puertoCarga[filas][columnas], buscArticulo, buscPuerto;
	string tipoArticulo[filas][columnas];
	limpiarMatrices(disponibilidad,pesos);
	
	//Solicitud de información
	cout << "Por favor ingrese el numero de puertos con los que desea trabajar: "; cin >> puertos;
	
	for (int i = 0; i < puertos; i++){				//Recorre los puertos
		cout<<"\nMatriz disponibilidad"<<endl;
		imprimirMatrizBooleana(disponibilidad);
		p= i+1;
	
		
		for (int k = 0; k < filas; k++){
			for (int l = 0; l < columnas; l++){			//Ciclo para listar los espacios libres para contenedores
				if (disponibilidad[k][l] == 0){
					cout << "\nLa posicion [" << k <<"] [" << l << "] esta disponible.";
				}
				
			}
		}
		cout << "\nPor favor ingresar la cantidad de contenedores cargados en el puerto " << p <<": "; cin >> cantContenedor;
		cout << "Por favor ingresar el nombre del puerto " << p <<": "; cin >> nomPuertos;
		for (int j=0; j<cantContenedor; j++){			//Ingreso de cada contenedor.
		 q=j+1;
		 	do {
				cout << "\nPor favor ingresar la fila en la que desea ubicar el contenedor " << q <<": "; cin >> fila;
		 		cout << "\nPor favor ingresar la columna en la que desea ubicar el contenedor " << q <<": "; cin >> columna;
	
		
		 	}while ((((fila<0 )||(fila>3))||((columna<0)||(columna>4)))||(disponibilidad[fila][columna]==1));
		 	disponibilidad[fila][columna] = 1; //Asigné el contenedor a una posición
		 	
			 if (disponibilidad[fila][columna] == 1){
		 		cout << "Por favor ingrese la marca del contenedor: "; cin >> marca; //Ingreso marca  Fila y columna
		 		marcas [fila][columna] = marca;										 //Asigno marca a la matriz marca Fila y columna
		 		cout << "Por favor ingrese el peso del contenedor: "; cin >> peso;  
		 		pesos [fila][columna] = peso;
		 		cout << "Por favor ingrese el nombre del puerto origen: "; cout << nomPuertos;
		 		puertoCarga [fila][columna] = nomPuertos;
		 		cout << "\nPor favor ingrese el tipo de articulo que contiene: "; cin >> tipo;	 		
		 		tipoArticulo [fila][columna] = tipo;
				 }
		 }
	}
	
	//Lista de información
	for (int k = 0; k < filas; k++){
			for (int l = 0; l < columnas; l++){
				if (disponibilidad[k][l] == 1){
					sumatory+=1;				//Variables para sacar promedio del peso de los contenedores en el barco (sumatory = sumatory + 1)
					acumPeso+= pesos[k][l];
				}
			}
		}
	
	promPeso = acumPeso / sumatory; //calculo promerdio de peso basado en pesototal sobre lugares ocupados
	
	cout<<"\nMatriz disponibilidad"<<endl;
	imprimirMatrizBooleana(disponibilidad);
	cout<<"\nMatriz marcas "<<endl;
	imprimirMatrizTexto(marcas);
	cout<<"Matriz puertos "<<endl;
	imprimirMatrizTexto(puertoCarga);
	cout<<"Matriz Tipo Articulo "<<endl;
	imprimirMatrizTexto(tipoArticulo);
	cout<<"Matriz Pesos "<<endl;
	imprimirMatrizEnteros(pesos);
	
	cout << "\n1.La cantidad de contenedores ingresados en los " << puertos << " puertos es de: " << sumatory << endl;
	
	cout << "\n6. El promedio del peso de los contenedores en cubierta es: " << promPeso << endl;
	
	cout << "9.Ingrese tipo de articulo que desea buscar en bodega: "; cin >> buscArticulo; // Ingreso articulo a buscar en la matriz de articulos
	
	for (int k = 0; k < filas; k++){
			for (int l = 0; l < columnas; l++){
				
				if (tipoArticulo[k][l] == buscArticulo){		//Ciclo Buscador de un tipo de artículo definido por el usuario.
					sumatoryArticulo+=1;
				}
				
			}
		}
	
	cout << "\nEn las bodegas se encuentran " << sumatoryArticulo <<  " contenedores con articulo tipo " << buscArticulo;
	
	cout << "\n10.Ingrese el nombre del puerto del que quiere conocer el promedio de peso de sus contenedores "; cin >> buscPuerto;
		
	for (int k = 0; k < filas; k++){
			for (int l = 0; l < columnas; l++){
				if (puertoCarga[k][l] == buscPuerto){
					sumatoryPuer+=1;				//Variables para sacar promedio de peso deacuerdo al puerto de carga
					acumPuer+= pesos[k][l];
				}
				
			}
		}	
	
	promPuer = acumPuer / sumatoryPuer;
	
	cout << "En las bodegas se encuentran un peso promedio de  " << promPuer <<  " kilos, provenientes del puerto " << buscPuerto;	
	
	for (int k = 0; k < filas; k++){
			for (int l = 0; l < columnas; l++){
				if (pesos[k][l] > mayorPeso){
					mayorPeso = pesos [k][l];				//Variables para sacar el contenedor más pesado de la empresa respectiva
					nomMayorPeso= marcas[k][l];
				}
				
			}
		}
	
	cout << "\n11.El contenedor de la empresa " << nomMayorPeso <<" con un peso de " << mayorPeso <<" Kilos, es el mas pesado de la carga actual.";
	
	for (int k = 0; k < filas; k++){
			
			for (int l = 0; l < columnas; l++){
				
				if (disponibilidad [k][l] == 1){
					auxMayorCarga += pesos [k][l];				//Determinar la fila con más carga.
				}
				
			}
			if (auxMayorCarga > mayorCarga){
					mayorCarga = auxMayorCarga;
					filaCarga = k;				
				}
				auxMayorCarga = 0;
		}
	cout << "\n7.Sumando todos los valores por fila se determino que la que posee mayor carga es:  " << filaCarga;
	
	for (int k = 0; k < filas; k++){
			for (int l = 0; l < columnas; l++){
				if ((pesos[k][l] < menorPeso)&&(disponibilidad[k][l]==1)){
					menorPeso = pesos [k][l];				//Variables para sacar el contenedor más liviano de la empresa respectiva
					nomMenorPeso= marcas[k][l];
				}
				
			}
		}
	
	cout << "\n12.El contenedor de la empresa " << nomMenorPeso <<" con un peso de " << menorPeso <<" Kilos, es el mas liviano de la carga actual.";
	return 0;
}
void limpiarMatrices(bool disponibilidad[filas][columnas],int pesos[filas][columnas]){	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			disponibilidad[i][j]=0;
			pesos[i][j]=0;
		}
	}
}
void imprimirMatrizBooleana(bool matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void imprimirMatrizTexto(string matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<", \t";
		}
		cout<<endl;
	}
}
void imprimirMatrizEnteros(int matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
string marcaMasPesada(int pesos[filas][columnas],string marcas[filas][columnas]){
	int mayor=INT_MIN;
	string respuesta="";
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(pesos[i][j]>mayor){
				mayor=pesos[i][j];
				respuesta=marcas[i][j];
			}
		}
	}
	return respuesta;
}
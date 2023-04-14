#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int CargarMatriz(int m[5][12]);
void ImprimirMatriz(int m[5][12]);

int main (){

    int columna, anio;
    int m[5][12];

    CargarMatriz(m);
    printf("Valores cargados:\n");
    ImprimirMatriz(m);
    printf("Promedio de ganancia por anio:\n");

 return 0;

}

int CargarMatriz(int m[5][12]){
    int mes, anio; //fila=anio columna=mes
    int aux;
    int maximo=50000;
    int minimo=10000;
    srand(time(NULL)); //semilla
    for(anio=0;anio<5;anio++){
        for(mes=0;mes<12;mes++){
                m[anio][mes]= rand() % (maximo - minimo +1) + minimo;

            
        }
    }

    return 0;

}

void ImprimirMatriz(int m[5][12]){
	int mes, anio;
    for(anio=0;anio<5;anio++){
        for(mes=0;mes<12;mes++){
            printf("%5d  ", m[anio][mes]);

        }

        printf("\n");

    }

}


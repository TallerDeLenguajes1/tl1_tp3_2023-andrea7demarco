#include<stdio.h>
#include<time.h>
#include<stdlib.h>

float CargarMatriz(float m[5][12]);
void ImprimirMatriz(float m[5][12]);
void calcularPromedio(float m[5][12]);
void maxymin(float m[5][12]);


int main (){

    int columna, anio;
    int m[5][12];
    float anio1;

    CargarMatriz(m);
    printf("Valores cargados:\n");
    ImprimirMatriz(m);
    printf("Promedio de ganancia por anio:\n");
    calcularPromedio(m);
    maxymin(m);

    

 return 0;

}

float CargarMatriz(float m[5][12]){
    int mes, anio; //fila=anio columna=mes
    float aux;
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

void ImprimirMatriz(float m[5][12]){
	int mes, anio;
    for(anio=0;anio<5;anio++){
        for(mes=0;mes<12;mes++){
            printf("%5.0f  ", m[anio][mes]);

        }

        printf("\n");

    }

}

void calcularPromedio(float m[5][12]){
	int mes, anio;
	float acumulador=0,calculo;
	float anio1,anio2,anio3,anio4,anio5;
	for(anio=0;anio<5;anio++){
		acumulador=0;
		for(mes=0;mes<12;mes++){
			acumulador=m[anio][mes] + acumulador;
		}
		
		calculo=acumulador/12;
		
		printf(" Anio[%d] , promedio:%.2f\n",anio+1,calculo);

	}
	
}

void maxymin(float m[5][12]){
	int mes,anio;
	float max=0, min, aux,aux2=0;

	    for(anio=0;anio<5;anio++){
          for(mes=0;mes<12;mes++){
           min=m[anio][mes];
           aux2=m[anio][mes];

           if(min>max){
           	  max=min;
		   }
		   if(aux2<aux){
		    	aux=aux2;
		   	
		   }
		   
        }
    }
    
    printf("max %0.f ",max);
    printf("min %0.f ",aux);
}


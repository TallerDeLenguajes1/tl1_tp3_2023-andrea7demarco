#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i;
    //reserva dinámica de memoria
    char** nombres=(char**)malloc(5*sizeof(char*));
    char buff[50];
    printf("Ingresar 5 nombres:\n");
    for(i=0;i<5;i++){
        printf("%d:",i+1);
        gets(buff);
        nombres[i]=(char*) malloc((strlen(buff)+1) * sizeof(char));
        strcpy(nombres[i],buff);
    
    }

    printf("NOMBRES INGRESADOS:\n");
    for(i=0;i<5;i++){

        printf("%s\n",nombres[i]);


    }


    for(i=0;i<5;i++){
        free(nombres[i]);

    }


    free(nombres);
    return 0;
}
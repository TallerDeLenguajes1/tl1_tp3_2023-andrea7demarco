#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char* TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
typedef struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}Cliente;

Cliente CargarCliente();
Producto CargarProducto();
Cliente* CargarClientes(int cantClientes);
void MostrarCliente(Cliente cli);
void MostrarUnProducto(Producto pro);
void MostrarClientes(Cliente* clientes, int cant);
void MOstrarProductos(Producto* productos);
void Calculos(Cliente* clientes, int cant);

int main(){
    
    int i,j, cantClientes;
    Cliente* punt_cliente;
    printf("Ingrese la cantidad de clientes:\n");
    scanf("%d",&cantClientes);
    punt_cliente=CargarClientes(cantClientes);
    MostrarClientes(punt_cliente,cantClientes);
    Calculos(punt_cliente,cantClientes);
    for(i=0;i<cantClientes;i++){
        for(j=0;j<cantClientes;j++){
            free(punt_cliente[i].Productos[j].TipoProducto);

        }
        free(punt_cliente[i].NombreCliente);
    }
    free(punt_cliente);

   return 0;
}


Cliente CargarCliente(){
    int i;
    Cliente ingreso;
    ingreso.NombreCliente=(char*)malloc(sizeof(char)*30);
    printf("Ingrese el nombre del cliente:");
    fflush(stdin);
    gets(ingreso.NombreCliente);
    ingreso.CantidadProductosAPedir=rand()%5+1;
    ingreso.Productos=(Producto*)malloc(ingreso.CantidadProductosAPedir*sizeof(Producto));
    for(i=0;i<ingreso.CantidadProductosAPedir;i++){
        ingreso.Productos[i]=CargarProducto();
        ingreso.Productos[i].ProductoID=i;
   }
   return ingreso;
}

Cliente* CargarClientes(int cant){
    int i;
    Cliente* ingreso;
    ingreso=(Cliente*)malloc(sizeof(Cliente)*cant);
    for(i=0;i<cant;i++){
        ingreso[i]=CargarCliente();
        ingreso[i].ClienteID=i;
    }

    return ingreso;
}

Producto CargarProducto(){
    Producto ingreso;
    ingreso.Cantidad=rand()%9+1;
    ingreso.TipoProducto=(char*)malloc(12*sizeof(char));
    ingreso.TipoProducto=TiposProductos[rand()%5];
    ingreso.PrecioUnitario=rand()%91*10;

    return ingreso;
}

void MostrarUnProducto(Producto pro){
    printf("ID del producto %d:\n",pro.ProductoID);
    printf("Tipo:%d\n",pro.TipoProducto);
    printf("Cantidad:%d\n",pro.Cantidad);
    printf("Precio unitario:%d\n",pro.PrecioUnitario);


}

void MostrarProductos(Producto* productos, int cant){
    int i;
    for(i=0;i<cant;i++){
        printf("PRODUCTO %d:\n",i+1);
        MostrarUnProducto(productos[i]);

    }
}

void MostrarUnCliente(Cliente cli){
    printf("ID cliente: %d\n",cli.ClienteID);
    printf("Nombre: %s\n",cli.NombreCliente);
    printf("Productos a pedir:%d\n",cli.CantidadProductosAPedir);
    MostrarProductos(cli.Productos,cli.CantidadProductosAPedir);
}

void MostrarClientes(Cliente* clientes, int cant){
    int i;
    for(i=0;i<cant;i++){
        printf("Cliente :%d\n",i+1);
        MostrarUnCliente(clientes[i]);
    }
}

void Calculos(Cliente* clientes, int cant){
    char* dato;
    int total, id, i,j;
    printf("Ingrese el nombre del cliente A BUSCAR:");
    dato=(char*)malloc(30*sizeof(int));
    gets(dato);
    for(i=0;i<cant;i++){
        if(strcmp(dato,clientes[i].NombreCliente)==0){
            printf("Ingrese el id del producto\n");
            scanf("%d",&id);
            for(j=0;j<clientes[i].CantidadProductosAPedir;j++){
                if(id==clientes[i].Productos[j].ProductoID){
                    total=clientes[i].Productos[j].Cantidad*clientes[i].Productos[j].PrecioUnitario;
                    printf("El total de %s es %d\n",clientes[i].Productos[j].TipoProducto,total);
                }
            }
        }
    }
    

}


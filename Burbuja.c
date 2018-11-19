#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
	int dato;
	struct nodo *siguiente;
	struct nodo *anterior;
};

nodo *inicio=NULL;
nodo *ultimo=NULL;
nodo *inicio2=NULL;
nodo *ultimo2=NULL;

nodo *crearnodo(int dato){
	nodo *nuevo=NULL;
	nuevo=(nodo *)malloc(sizeof(nodo));
	if(nuevo!=NULL){
		nuevo->dato=dato;
		nuevo->siguiente=NULL;
		nuevo->anterior=NULL;
	}
	return nuevo;
}

void insertar(int dato){
	nodo *nuevo=NULL;
	nuevo= crearnodo(dato);
	if(inicio == NULL){
		inicio=nuevo;
		ultimo=nuevo;
	}
	else{
		ultimo->siguiente=nuevo;
		nuevo->anterior=ultimo;
		ultimo=nuevo;
	}
}

void imprimirFI(){
	nodo *aux=inicio;
	while(aux!=NULL){
		printf("%d \n",aux->dato);
		aux=aux->siguiente;
	}
}

void burbuja(int a){
	int temp;
	nodo *aux=inicio;
	for(int i=0; i<a; i++){
		nodo *aux2=inicio;
		for(int j=0; j<i; j++){
			if((i!=j)&&(aux->dato<aux2->dato)){
				temp=aux2->dato;
				aux2->dato=aux->dato;
				aux->dato=temp;
			}
			aux2=aux2->siguiente;
		}	
		aux=aux->siguiente;
	}
}

int main(int argc, char *argv[]) {
	int a,b;
	printf("Ingrese la cantidad de numero que desea ordenar por el metodo de ordenamiento de burbuja :");
	scanf("%d",&a);
	for(int i=0; i<a; i++){
		printf("Ingrese el numero numero %d de %d :",i+1,a);
		scanf("%d",&b);
		insertar(b);
	}
	printf("\nLista original\n");
	imprimirFI();
	burbuja(a);
	printf("\nLista ordenada por burbuja\n");
	imprimirFI();
	return 0;
}

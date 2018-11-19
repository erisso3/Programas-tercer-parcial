#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
	int dato;
	int ordenado;
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
		nuevo->ordenado=0;
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
void QuickSort(nodo* aux,nodo* aux2){
	int temp,x=0;
	while(aux!=aux2){
		while(x==0){
			if(aux!=aux2){
				if(aux->dato>=aux2->dato){
					temp=aux->dato;
					aux->dato=aux2->dato;
					aux2->dato=temp;
					nodo* piv=aux;
					aux=aux2;
					aux2=piv;
					x=1;
				}
				else{
					aux2=aux2->anterior;
				}
			}
			else{
				x=1;
			}
		}
		x=0;
		while(x==0){
			if(aux!=aux2){
				if(aux->dato<aux2->dato){
					temp=aux->dato;
					aux->dato=aux2->dato;
					aux2->dato=temp;
					nodo* piv=aux;
					aux=aux2;
					aux2=piv;
					x=1;
				}
				else{
					aux2=aux2->siguiente;
				}
			}
			else{
				x=1;
			}
		}
		x=0;
	}
	aux->ordenado=1;
	nodo* ant=aux->anterior;
	nodo* ini2=aux;
	nodo* pos=aux->siguiente;
	nodo* ult2=aux;
	while((ini2->anterior!=NULL)&&(ini2->anterior->ordenado!=1)){
		ini2=ini2->anterior;
	}
	while((ult2->siguiente!=NULL)&&(ult2->siguiente->ordenado!=1)){
		ult2=ult2->siguiente;
	}
	if((ini2!=ant)&&(ant!=NULL)&&(ant->ordenado==0)){
		QuickSort(ini2,ant);
	}
	if((ult2!=aux->siguiente)&&(aux->siguiente!=NULL)&&(pos->ordenado==0)){
		QuickSort(aux->siguiente,ult2);
	}
}

void visualizar(){
	nodo *aux=inicio;
	while(aux!=NULL){
		printf("%d \n",aux->dato);
		aux=aux->siguiente;
	}
}

int main(int argc, char *argv[]) {
	int a,b;
	printf("Ingrese la cantidad de numero que desea ordenar por el metodo de ordenamiento de QuickSort :");
	scanf("%d",&a);
	for(int i=0; i<a; i++){
		printf("Ingrese el numero numero %d de %d :",i+1,a);
		scanf("%d",&b);
		insertar(b);	
	}
	printf("\nLista original\n");
	visualizar();
	QuickSort(inicio,ultimo);
	printf("\nLista ordenada por QuickSort\n");
	visualizar();
	return 0;
}

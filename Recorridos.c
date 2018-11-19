#include <stdio.h>
#include <stdlib.h>
#define nodo struct nodo
#define nodocola struct nodocola

nodo{
	int datito;
	nodo*izquierda;
	nodo*derecha;
};
nodocola{
	nodo*datito;
	nodocola*siguiente;
	nodocola*anterior;
};

nodocola*inicio=NULL;
nodocola*fin=NULL;
nodocola*nodonuevo(nodo*);

void encolar(nodo*);
nodo*desencolar();


nodo*raiz=NULL;
nodo*nuevonodo(int);
void insertar(int);
void recorrerniveles();
int colavacia();
void inorden(nodo*);
void postOrden( nodo*);
void preOrden( nodo* r);





nodocola*nuevonodocola(nodo*datito){
	nodocola*nuevo=(nodocola*)malloc(sizeof(nodocola));
	nuevo->datito=datito;
	nuevo->siguiente=NULL;
	nuevo->anterior=NULL;
	return nuevo;
}


void encolar(nodo*datito){
	nodocola*nuevo=nuevonodocola(datito);
	if(colavacia()){
		inicio=nuevo;
		fin=nuevo;
	}else{
		fin->siguiente=nuevo;
		nuevo->anterior=fin;
		fin=nuevo;
	}
}

int colavacia(){
	if((inicio==NULL)&&(fin==NULL)){
		return 1;
	}else{
		return 0;
	}
}

nodo*desencolar(){
	nodocola*aux;
	if(colavacia()){
		return NULL;
	}else{
		aux=inicio;
		inicio=inicio->siguiente;
		aux->siguiente=NULL;
		if(inicio!=NULL){
			inicio->anterior=NULL;
		}else{
			fin=NULL;
		}
	}
	nodo*resultado=aux->datito;
	free(aux);
	return resultado;
}


nodo*nuevonodo(int datito){
	nodo*nuevo=(nodo*)malloc(sizeof(nodo));
	nuevo->datito=datito;
	nuevo->izquierda=NULL;
	nuevo->derecha=NULL;
	return nuevo;
}

void insertar(int datito){
	nodo*nuevo=nuevonodo(datito);
	nodo*aux=raiz;
	nodo*anterior=NULL;
	while(aux!=NULL){
		anterior=aux;
		if(nuevo->datito>aux->datito){
			aux=aux->derecha;
		}else{
			aux=aux->izquierda;
		}
	}
	if(anterior==NULL){
		raiz=nuevo;
	}else{
		if(nuevo->datito>anterior->datito){
			anterior->derecha=nuevo;
		}else{
			anterior->izquierda=nuevo;
		}
	}
}


void recorrerniveles(){
	if(raiz!=NULL){
		nodo*aux=raiz;
		encolar(aux);
		while(!colavacia()){
			nodo*tmp=desencolar();
			printf("%d ",tmp->datito);
			if(tmp->izquierda!=NULL){
				encolar(tmp->izquierda);
			}
			if(tmp->derecha!=NULL){
				encolar(tmp->derecha);
			}
		}
	}
}

void inorden(nodo*raiz){
	if(raiz!=NULL){
		inorden(raiz->izquierda);
		printf("%d ",raiz->datito);
		inorden(raiz->derecha);
	}
}

void postOrden( nodo*raiz )
{ 
	
	if ( raiz!= NULL ) { 
		postOrden( raiz->izquierda );
		postOrden( raiz->derecha);
		printf( "%d ", raiz->datito );
	} 
	
}

void preOrden( nodo*r )
{ 
	if ( r != NULL ) { 
		printf( "%d ", r->datito );
		preOrden( r->izquierda );
		preOrden( r->derecha );
	} 
} 

int main(int argc, char *argv[]) {
	int n,n1;
	printf("Ingrese la cantidad de numero que desea recorrer por anchura :");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Ingrese el numero numero %d de %d :",i+1,n);
		scanf("%d",&n1);
		insertar(n1);
	}
	printf("\nLista recorrida por anchura\n");
	recorrerniveles();
	printf("\n-------------------------------------\n");
	printf("\nLista recorrida en inorden\n");
	inorden(raiz);
	printf("\n-------------------------------------\n");
	printf("\nLista recorrida en postOrden\n");
	postOrden(raiz);
	printf("\n-------------------------------------\n");
	printf("\nLista recorrida por preOrden\n");
	preOrden(raiz);
	return 0;
}


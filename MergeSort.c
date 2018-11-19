#include <stdio.h>
#include <stdlib.h>
void mergeSort(int a[],int izq, int der, int n);
int main(int argc, char *argv[]) {
	int n,i,izq,der,b;
	printf("Ingrese la cantidad de numero que desea ordenar por el metodo de ordenamiento de MergeSort:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("Ingrese el numero numero %d de %d :",i+1,n);
		scanf("%d",&b);
		a[i]=b;
	}
	printf("\nLista original\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		printf("\n");
	}
	izq = 0;
	der = n-1;
	mergeSort(a,izq,der,n);
	printf("\nLista ordenada por MergeSort\n");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
void mergeSort(int a[],int izq, int der,int n){
	int i,j,k,l;
	int array[n];
	if(der>izq){
		l = (der + izq)/2;
		mergeSort(a,izq,l,n);
		mergeSort(a,l+1,der,n);
		for(i=l+1;i>izq;i--){
			array[i-1]= a[i-1];
		}
		for(j=l;j<der;j++){
			array[der+l-j]= a[j+1];
		}
		for(k=izq;k<=der;k++){
			if(array[i]<array[j]){
				a[k]=array[i++];
			}else{
				a[k]= array[j--];
			}
		}
	}
}

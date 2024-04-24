#include <stdio.h>
#include <stdlib.h>
int C=0; // var glob pr compter le nb detapes necessaires pour atteindre 1.

void Hailstone_Number(int n){
	int HN = n;
	int * T;
	T=(int *)malloc(n*sizeof(int));
	int i=0;
	// si HN est pair
	if (HN % 2==0){
		HN= HN/2;
		C++;
		*(T+i)=HN;
		n++;
		T=(int *)realloc(T, n * sizeof(int));
		printf(" %d \t", *(T+i));	
	}
	else{
		HN = HN*3+1;
		C++;
		*(T+i)=HN;
		n++;
		T=(int *)realloc(T,n*sizeof(int));
		printf("%d \t", *(T+i));
	}
	if(HN>1) {
		Hailstone_Number(HN); 
	}
	else {
		printf ("\nle nombre des etapes est : %d", C) ; }
	}
///////////////////////////////////////////////
int main( ){
	int n;
	printf(" saisir un entier positif ");
	scanf("%i", &n);
	printf("la sequence des Nombres Hailstone de %d est : \n",n);
	Hailstone_Number(n);
	return 0;
}

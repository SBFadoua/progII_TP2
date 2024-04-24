#include <stdio.h>
#include <stdlib.h>

// fonction d'allocation 
int ** alloue_matrice_pascal(int **Tab,int n){
	int i;
	Tab=(int**)malloc(n*sizeof(int *));
	for(i=0;i<n;i++){
		*(Tab+i)=(int *)malloc((i+1)*sizeof(int)); 
	}
	return Tab; 
}
// fonction récursive
int Triangle_pascal (int ** T, int p, int q){
	if(p==q||q==0){
		return 1; 
	}
	else {
		return Triangle_pascal(T,p-1,q) + Triangle_pascal(T,p-1,q-1);}
	}

int main(){
	int i,j, espace,n;
	int **Tab;
	printf("entrer une valeur ");
	scanf("%d",&n);
	Tab=alloue_matrice_pascal (Tab,n);
	for(i = 0; n >= i; i++) {
		for(espace = 0; espace < n-i; espace++)
			printf(" ");
		for(j = 0; i >= j; j++) {
			int res = Triangle_pascal(Tab,i, j);
			printf("%ld ", res);
		}
	printf("\n"); 
	}
	return 0;
}

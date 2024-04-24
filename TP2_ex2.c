#include <stdio.h>
#include <stdlib.h>

void convertir(int n,int b){
	int *tab;
	int taille=1;
	int r,q,i=0;
	tab=(int *)malloc(taille*sizeof(int));
	if(n!=0){
		r=n%b;
		q=n/b;
		convertir(q,b);
		taille++;
		tab=(int *)realloc(tab,taille*sizeof(int));
		*(tab+i)=r;
		printf("%d",*(tab+i));
		i++;
		
	}
}


int main(){
	int n,b;
	printf("\n saisir un nombre decimal: ");
	scanf("%d",&n);
	printf("\n saisir une base: ");
	scanf("%d",&b);
	printf("\n %d en base %d = ",n,b );
	convertir(n,b);
	return 0;
}

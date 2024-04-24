#include <stdio.h>
#include <stdlib.h>

/*1). Ecrire une fonction r�cursive Parfait permettant d�afficher tous les nombres parfait qui sont
inf�rieur au nombre entier pass� en param�tre.*/

int parfait(int n, int div){
	
	if(div==1){ 
		return 1;
	}
	else if(n%div==0){ // Si div est un diviseur de n
		return (div+parfait(n,div-1));		
	}
	else{
		return parfait(n,div-1);
	}
		
}
//2). Allouer dynamiquement la m�moire pour le tableau renvoyant le r�sultat.
void allouer(int n){
	int *tab;
	int taille=1;
	int i,j=0;
	tab = (int*)malloc(taille*sizeof(int));
	for(i=2;i<=n;i++){ // 1 n'est g�n�ralement pas parfait
		if(parfait(i,i/2)==i){//Nous n'avons pas besoin de v�rifier les diviseurs potentiels au-del� de i/2
			taille++;
			tab=(int*)realloc(tab,taille*sizeof(int));
			*(tab+j)=i;
			printf("%d\t",*(tab+j));
			j++; // Incr�mentation de l'indice d'insertion dans le tableau
		}
		else {
			*(tab+j)=-1;
		}
	}
}
/*
void afficheParfait(int *tab,int taille){
	printf("les nombres parfaits : ");
	for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}*/

int main(){
	int n;
	printf("saisir n ");
	scanf("%d",&n);	
	printf("les nombres parfaits < %d sont : \n",n);
	allouer(n);	
	return 0;
}

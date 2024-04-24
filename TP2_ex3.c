#include <stdio.h>
#include <stdlib.h>

void Facteurs_Premiers(int num, int count){ 
	int N=1; int *tab;
	int j=0;
	tab=(int*)malloc(N* sizeof(int));
	if(num < 1)
		return;
	else if(num % count == 0){
		N++;
		tab=(int*)realloc(tab,N * sizeof(int));
		*(tab+j)=count;
		printf("%d\n", *(tab+j));
		j++;
		Facteurs_Premiers(num / count, count);
	}
	else{
			Facteurs_Premiers(num, count+1);
	}
}

int main(){
	int num;
	printf("saisir un entier positif\n");
	scanf("%d", &num);
	printf("\n La decomposition de % d en facteurs premiers est :\n", num);
	Facteurs_Premiers(num, 2);
	return 0;
}

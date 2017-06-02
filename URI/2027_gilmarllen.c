#include <stdio.h>

int maxComum(int x ,int y) {
	int aux;
	if(x<y){
		aux = x;
		x = y;
		y = aux;
	}
	for(aux = y; aux>0; aux--){
		if((x%aux == 0)&&(y%aux == 0))
			return aux;
	}
}

int main() {
	int x, y, apostas[100], cont = 0, i;
	while (scanf("%d %d",&x,&y)!=EOF) {
		 apostas[cont] = maxComum(x,y);
		 if  (apostas[cont++]>5)
			printf("Noel\n");
		 else
			printf("Gnomos\n");;
	}
	for(i=cont-1; i>=0; i--) {
		printf("%d ",apostas[i]);
	}
	printf("\n");

	return 0;
}

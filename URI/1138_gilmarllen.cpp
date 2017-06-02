#include <cstdio>
#include <cstring>
using namespace std;

int qtdA[15];
int qtdB[15];

void calc(int* vet, int num)
{
    int aux = num, qD=0;
    while(aux)
    {
        vet[aux%10]++;
        aux/=10;
		qD++;
    }

    vet[0]--;
    for(int i=0; i<10; i++)
        vet[i]+=(num/10);

    for(int i=0; i<(num%10); i++)
        vet[i]++;

	if(qD==1)
		return;

	int l=10;
	aux=num;

	int ant = num%l;

	aux /=10;

	
    while(aux/10)
    {
		vet[0]-=l;
        for(int i=0; i<10; i++)
        	vet[i]+=(aux/10)*l;

		for(int i=0; i<(aux%10); i++)
        	vet[i]+=l;

		vet[(aux%10)]+=ant;

		l*=10;
		aux /=10;
		ant = num%l;
    }

	vet[0]-=l;
	for(int i=0; i<aux; i++)
    	vet[i]+=l;

	vet[aux]+=ant;
    
}

int main()
{
    while(true)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if((a==0) && (b==0))
            break;

        memset(qtdA, 0, sizeof(qtdA));
        memset(qtdB, 0, sizeof(qtdB));

        calc(qtdA, a);
		int aux = a;
		while(aux)
		{
		    qtdA[aux%10]--;
		    aux/=10;
		}

        calc(qtdB, b);

        for(int i=0; i<9; i++)
            printf("%d ", qtdB[i] - qtdA[i]);

        printf("%d\n", qtdB[9] - qtdA[9]);
    }

	return 0;
}

#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

typedef struct Jogador jogador;

struct Jogador{
	char nome[101];
	int skill;
	jogador* prox;
};

int compara(const void* a, const void* b)
{
	jogador* x = (jogador*)a;
	jogador* y = (jogador*)b;
	
	if(x->skill > y->skill)
		return -1;
		
	if(x->skill < y->skill)
		return 1;
}

int nTimes, nJogadores;
jogador vet[10010];
//jogador* times[1010];

int main() {
	scanf("%d %d", &nJogadores, &nTimes);

	for(int i=0; i<nJogadores; i++)
	{
		scanf("\n%s %d", vet[i].nome, &vet[i].skill);
		vet[i].prox = NULL;
	}

	qsort(vet, nJogadores, sizeof(jogador), compara);

    vector<string> times[nTimes];
    for(int i=0; i<nJogadores; i++)
        times[i%nTimes].push_back(vet[i].nome);

    for(int i=0; i<nTimes; i++)
    {
        printf("Time %d\n", i+1);

        sort(times[i].begin(), times[i].end());
        
        for(int j=0; j < times[i].size(); j++)
            cout << times[i][j] << endl;

        printf("\n");
    }

	//printf("\naa\n");
	/*for(int i=0; i<nJogadores; i++)
	{
		jogador* it = times[i%nTimes];
		jogador* ant = it;
		while(it!=NULL)
		{
			ant = it;
			it = it->prox;
		}
		ant->prox = &(vet[nJogadores]);
	}*/
	
	/*for(int i=0; i<nTimes; i++)
	{
		printf("Time %d\n", i+1);
		jogador* it = times[i];
		while(it)
		{
			printf("%s\n", it->nome);
			it = it->prox;
		}
		printf("\n");
	}*/
	
	return 0;
}

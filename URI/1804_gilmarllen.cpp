#include <cstdio>

#define MAXS 100010

int BIT[MAXS], val[MAXS];
int n;

// Adiciona o valor v à posição idx do vetor
void update(int idx, int v){
    while(idx<=n){
        BIT[idx]+=v;
        idx+=(idx&-idx);
    }
}
// Calcula a soma do vetor no intervalo [1,idx]
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=(idx&-idx);
    }
    return sum;
}

int main()
{
	scanf("%d", &n);

	for(int i=1; i<=n; i++)
	{
		scanf("%d", &val[i]);
		update(i, val[i]);
	}
	scanf("\n");

	int bg;
	char op;
	while(scanf("%c %d\n", &op, &bg)!=EOF)
	{
		//printf("\t%c %d\n", op, bg);
		if(op=='a')
			update(bg, -val[bg]);

		if(op=='?')
			printf("%d\n", query(bg-1));		
	}

	return 0;
}

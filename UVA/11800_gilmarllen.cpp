#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

int n, teste=1;

typedef struct{
	int x;
	int y;
} Ponto;

Ponto pts[4];
int dist[4];

/*Calculo distancia^2(nao precisa do valor exato) entre dois pontos*/
int distancia(Ponto p1, Ponto p2)
{
	return (pow(p2.x-p1.x, 2)+pow(p2.y-p1.y, 2));
}

int ordXY(const void* a, const void* b)
{
	Ponto* p1 = (Ponto*)a;
	Ponto* p2 = (Ponto*)b;

	if(p1->x == p2->x)
	{
		if(p1->y < p2->y)
			return -1;

		if(p1->y > p2->y)
			return 1;
	}

	if(p1->x > p2->x)
		return 1;

	if(p1->x < p2->x)
		return -1;	
}

/*atan2l funcao arctang*/
int CmpAng(const void* a, const void* b)
{
	Ponto* p1 = (Ponto*)a;
	Ponto* p2 = (Ponto*)b;

	if(atan2l((p1->y - pts[0].y),(p1->x - pts[0].x)) > atan2l((p2->y - pts[0].y),(p2->x - pts[0].x)))
		return 1;

	return -1;
}

int ProdInterno(Ponto p1, Ponto p2, Ponto r1, Ponto r2)
{
	return ((p2.x-p1.x)*(r2.x-r1.x))+((p2.y-p1.y)*(r2.y-r1.y));
}

int ProdVetorial(Ponto p1, Ponto p2, Ponto r1, Ponto r2)
{
	return ((p2.x-p1.x)*(r2.y-r1.y))-((p2.y-p1.y)*(r2.x-r1.x));
}

int main()
{
	scanf("%d", &n);

	while(n--)
	{
		printf("Case %d: ", teste);

		for(int i=0; i<4; i++)
			scanf("%d %d", &pts[i].x, &pts[i].y);

		qsort(pts, 4, sizeof(Ponto), ordXY); /*Deixa o ponto com menor x e menor y na primeira posicao*/
		qsort(&pts[1], 3, sizeof(Ponto), CmpAng);/*Ordena os 3 outros pontos de acordo com o angulo formado em relacao ao ponto da primeira posicao do vetor*/

		/*for(int i=0; i<4; i++)
			printf("%d %d\n", pts[i].x, pts[i].y);*/

		/*Calcula distancias das retas que formam a figura*/
		for(int i=0; i<4; i++)
			dist[i] = distancia(pts[i], pts[(i+1)%4]);

		/*for(int i=0; i<4; i++)
			printf("d%d\n", dist[i]);*/

		if(dist[0] == dist[1] && dist[1]==dist[2] && dist[2]==dist[3])
		{
			/*Se o Produto interno entre dois vetores==0, eles sao orgonais*/
			if(ProdInterno(pts[0], pts[3],pts[0],pts[1])==0)
			{
				printf("Square\n");
				teste++;
				continue;
			}else{
				printf("Rhombus\n");
				teste++;
				continue;
			}
		}

		if(dist[0] == dist[2] && dist[1]==dist[3])
		{
			if(ProdInterno(pts[0], pts[3],pts[0],pts[1])==0)
			{
				printf("Rectangle\n");
				teste++;
				continue;
			}else{
				printf("Parallelogram\n");
				teste++;
				continue;
			}
		}

		/*Se o Produto vetorial entre dois vetores==0, eles sao paralelos*/
		if(ProdVetorial(pts[0], pts[1],pts[2],pts[3])==0 || ProdVetorial(pts[0], pts[3],pts[1],pts[2])==0)
		{
			printf("Trapezium\n");
			teste++;
			continue;
		}

		printf("Ordinary Quadrilateral\n");
		teste++;
	}

	return 0;
}

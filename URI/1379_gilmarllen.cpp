 #include <cstdio>

long long b, c;

int main()
{
	while(true)
	{
		scanf("%lld %lld", &b, &c);
		if(b==0 && c==0) break;

		printf("%lld\n", (2*b) - c);
	}
    
	return 0;
}

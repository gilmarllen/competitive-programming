#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

#define MAXN 100010

int n_casos;
char entrada[MAXN];

/*bool ehComplementar(char topo, char ent)
{
	if(ent == ')')
	{
		if(topo == '(')
		{
			return true;
		}else{
			return false;
		}
	}

	if(ent == ']')
	{
		if(topo == '[')
		{
			return true;
		}else{
			return false;
		}
	}

	if(ent == '}')
	{
		if(topo == '{')
		{
			return true;
		}else{
			return false;
		}
	}
}*/

char fechando (char c)
{
  switch (c)
    {
      case '(':
        return ')';
      case '[':
        return ']';
      case '{':
        return '}';
    }
  return '\0';
}

int main()
{
	scanf("%d\n", &n_casos);
	
	while(n_casos)
	{
		scanf("%s",entrada);
 		int i=0;
		int ans=0;
		stack <char> sEnt;
		int tam = strlen(entrada);
		while(i < tam)
		{
			if(entrada[i]=='(' || entrada[i]=='[' || entrada[i]=='{')
			{
				sEnt.push(entrada[i]);
			}else{
				if(!sEnt.empty() && (fechando(sEnt.top()) == entrada[i]))
				{
					sEnt.pop();
				}else{
					ans=1;
					break;
				}
			}

			i++;
		}

		if(ans)
		{
			printf("N\n");
		}else{
			if(sEnt.empty())
			{
				printf("S\n");
			}else{
				printf("N\n");
			}			
		}

		n_casos--;
	}

	return 0;
}

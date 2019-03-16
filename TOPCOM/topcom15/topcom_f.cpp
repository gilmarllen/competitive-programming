// reset
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>

using namespace std;

int n;
char line[9999];

bool isNum(char c)
{
    return (c>='0') && (c<='9');
}

int main()
{
    cin >> n;
    while(n--)
    {
        bool div0 = false;
        stack<int> pilha;
        scanf(" %[^\n]\n", line);
        // printf("%s\n", line);
        int tamLine = strlen(line);
        for(int idx=0; idx<tamLine;idx++)
        {
            char str_num[100];
            int idx_num = 0;
            if( isNum(line[idx]) ) // num
            {
                // printf("AAAAA\n");
                while( isNum(line[idx]) ){
                    str_num[idx_num] = line[idx];
                    idx_num++;
                    idx++;
                }
                idx_num--;
                // printf("BBBB\n");
                // cout << "idx_num: " << str_num[idx_num] << endl;
                int num = 0;
                int exp = 0;
                while(idx_num>=0){
                    num += (str_num[idx_num]-'0')*pow(10,exp);
                    exp++;
                    idx_num--;
                }

                // cout << num << endl;
                pilha.push(num);
            }

            // ops
            if( line[idx]=='+' )
            {
                int a = pilha.top();
                pilha.pop();
                int b = pilha.top();
                pilha.pop();
                // cout << a << "+" << b << endl;
                pilha.push(a+b);
                idx++;
            }

            if( line[idx]=='-' )
            {
                int a = pilha.top();
                pilha.pop();
                int b = pilha.top();
                pilha.pop();
                // cout << b << "-" << a << endl;
                pilha.push(b-a);
                idx++;
            }

            if( line[idx]=='*' )
            {
                int a = pilha.top();
                pilha.pop();
                int b = pilha.top();
                pilha.pop();
                // cout << a << "*" << b << endl;
                pilha.push(a*b);
                idx++;
            }

            if( line[idx]=='/' )
            {
                int a = pilha.top();
                pilha.pop();
                int b = pilha.top();
                pilha.pop();
                // cout << b << "/" << a << endl;
                if(a==0){
                    div0 = true;
                    break;
                }
                pilha.push(b/a);
                idx++;
            }
        }

        if(div0)
            cout << "DIV0" << endl;
        else
            cout << pilha.top() << endl;
    }

    return 0;
}
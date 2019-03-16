#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <string>

using namespace std;

char str[100];

bool isPalindrome(int left, int right)
{
    int check = true;
    while(check && (left<right))
    {
        check = str[left] == str[right];
        left++;
        right--;
    }
    return check;
}

int main()
{
    while( scanf("%s\n", str)!=EOF )
    {
        set<string> conj;
        int resp = 0;
        int strTam = strlen(str);
        for(int wordTam=1; wordTam<=strTam; wordTam++)
        {
            for(int idx=0; idx<=(strTam-wordTam); idx++)
            {
                // for(int i=idx; i<=(idx+wordTam-1);i++)
                //     printf("%c", str[i]);
                if(isPalindrome(idx, idx+wordTam-1)){
                    // Skip duplicates
                    string cpp_str(&str[idx],wordTam);
                    if(conj.find(cpp_str)==conj.end())
                    {
                        // cout << cpp_str << endl;
                        resp++;
                        conj.insert(cpp_str);
                    }
                }
                // printf("\n");
            }
        }

        printf("The string '%s' contains %d palindromes.\n", str, resp);
    }

    return 0;
}

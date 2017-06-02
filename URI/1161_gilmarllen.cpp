#include <stdio.h>
 
int main(){
    long long int m , n, fatm=1, fatn=1, i, soma;
 
    while(scanf("%lli %lli",&m ,&n)!=EOF){        
         
        fatn = 1;
        fatm = 1;
 
        for(i=m; i!=0; i--){
            fatm = fatm*i;
        }
 
        for(i=n; i!=0; i--){
            fatn = fatn*i;
        }
 
        soma = fatm + fatn;
        printf("%lli\n", soma);
    }
 
    return 0;
}

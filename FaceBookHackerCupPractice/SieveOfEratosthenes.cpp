#include <bits/stdc++.h>

using namespace std;

//efficient when n is smaller than 10 million
void SieveOfEratosthenes(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int p=2;p<=n;p++){
        if(prime[p]==true){
            for(int i=p*p;i<=n;i+=p){
                prime[i] = false;
            }
        }
    }
    for(int p=2;p<=n;p++)
        if(prime[p])
            printf("%d ",p);
}

int main(){
    int n = 30;
    scanf("%d",&n);
    freopen("output.txt","w",stdout);
    printf("Following are the prime numbers smaller than or equal to %d \n",n);
    SieveOfEratosthenes(n);
    printf("\n");
    return 0;
}
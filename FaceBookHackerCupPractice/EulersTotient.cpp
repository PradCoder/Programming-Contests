#include <bits/stdc++.h>

using namespace std;

//unreliable since floating point errors
int phi1(int n){
    float result = n;

    for(int p=2;p*p<=n;++p){
        if(n%p==0){
            while(n%p==0){
                n /= p;
            }
            result *= (1.0-(1.0/(float)p));
        }
    }

    if(n>1)
        result *= (1.0-(1.0/(float)n));
    return (int)result;
}

//reliable totient function
/*
This method is calculates the totient of n
by subtracting the prime factors and multiples of them from n
since gcd>1 for those numbers
*/
int phi2(int n){
    int result = n;
    for(int p=2;p*p<=n;++p){
        if(n%p==0){
            while(n%p==0){
                n/=p;
            }
            result-=result/p;
        }
    }

    if(n>1)
        result -= result/n;
    return result;
}

int main(){
    FILE *fp= freopen("output.txt","w",stdout);

    for(int i=1;i<=1000000;++i){
        printf("phi1(%d) = %d phi2(%d) = %d\n",i,phi1(i),i,phi2(i));
    }
    fclose(fp);
    return 0;
}
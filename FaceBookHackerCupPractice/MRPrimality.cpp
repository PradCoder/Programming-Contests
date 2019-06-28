#include <bits/stdc++.h>

using namespace std;

int power(int x,int n,int m){
    int res = 1;
    x = x%m;
    while(n>0){
        if(n&1)
            res = (res*x)%m;
        n=n>>1;
        x=(x*x)%m;
    }
    return res;
}

//given a number n check if it prime or not
bool millerTest(int n, int d){
    int a = rand()%(n-3)+2;
    int x = power(a,d,n);
    if(x==1||x==n-1) return true;
    while(d!=n-1){//runs r-1 time if it is prime
        x=(x*x)%n;
        d*=2;
        if(x==1) return false;
        if(x==n-1) return true;
    }
    return false;
}

bool isPrime(int n,int k){
    if(n<=1||n==4) return false;
    if(n<=3) return true;
    int d = n-1;
    while(d%2==0)
        d/=2;
    for(int i=0;i<k;i++){
        if(!millerTest(n,d))
            return false;
    }
    return true;
}

int main(){
    FILE *fp = freopen("output.txt","w",stdout);

    int k=4;
    for(int i=1;i<=100;i++){
        if(isPrime(i,k)) printf("%d\n",i);
    }

    fclose(fp);
    return 0;
}
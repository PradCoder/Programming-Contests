/*Number Theory*/
#include <bits/stdc++.h>

using namespace std;

bool prime(int n){
    if(n<2) return false;
    for(int x=2;x*x<=n;x++){
        if(n%x==0) return false;
    }
    return true;
}

vector<int> factors(int n){
    vector<int> f;
    for(int x=2;x*x<=n;x++){
        while(n%x==0){
            f.push_back(x);
            n/=x;
        }
    }
    if(n>1) f.push_back(n);
    return f;
}

/*Sieve of Eratosthenes*/
vector<int> factor(int n){
    vector<int> sieve(n,0);
    for(int x=2;x<=n;x++){
        if(sieve[x]) continue;
        for(int u=2*x;u<=n;u++){
            sieve[u] = x;
        }
    }
    return sieve;
}

/*Euclid's algorithm*/
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

/*Modular exponentiation*/
int modpow(int x,int n,int m){
    if(n==0) return 1%m;
    long long u = modpow(x,n/2,m);
    u=(u*u)%m;
    if(n%2==1) u = (u*x)%m;
    return u;
}

int main(){
    /*Computer arithmetic*/
    unsigned int x = 123456789;
    cout<<x*x<<"\n";//2537071545 = 123456789^2 mod 2^32 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//modular power function
int power(int x, unsigned int y, unsigned int m){
    if(y==0)
        return 1;
    int p = power(x,y/2,m)%m;
    p = (p*p)%m;
    return (y%2==0)? p:(x*p)%m;
}

int gcd(int a, int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

//Naive 
int modInverse1(int a,int m){
    int mod(0);
    for(int i=1;i<m;i++){
        if((i*a)%m==1){
            mod = i;
            break;
        }
    }
    return mod;
}

int gcdExtended(int a, int b, int *x,int *y){
    if(a==0){
        *x=0;
        *y=1;
        return b;
    }
    int x1,y1;
    int gcd = gcdExtended(b%a,a,&x1,&y1);
    *x = y1-(b/a)*x1; 
    *y = x1;
    return gcd;
}

//Works when m and a are coprime because otherwise there is no
//modular inverse
void modInverse2(int a,int m){
    int x,y;
    int g = gcdExtended(a,m,&x,&y);
    if(g!=1){
        printf("Inverse doesn't exist\n");
    }else{
        int res = (x%m+m)%m;
        printf("Modular multiplicative inverse is %d\n",res);
    } 
}

//Iterative approach of modInverse2
int modInverse3(int a,int m){
    int m0 = m;
    int y = 0,x = 1;

    if(m==1)
        return 0;
    
    while(a > 1){
        int q = a/m;
        int t = m;

        m = a%m, a = t;
        t = y;
        y = x-q*y;
        x = t;
    }

    if(x<0)
        x+=m0;
    
    return x;
}

//Works when m is prime
void modInverse4(int a,int m){
    int g = gcd(a,m);
    if(g!=1){
        printf("Inverse doesn't exist\n");
    }else{
        printf("Modular multiplicative inverse is %d\n",power(a,m-2,m));
    } 
}

int main(){
    int a = 3, m = 11;
    printf("%d\n",modInverse1(a,m));
    modInverse2(a,m);
    printf("%d\n",modInverse3(a,m));
    modInverse4(a,m);
    return 0;
}
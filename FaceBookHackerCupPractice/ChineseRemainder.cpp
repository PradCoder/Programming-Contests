#include <bits/stdc++.h>

using namespace std;

int inv(int a,int m){
    int m0=m;
    int x=1,y=0;
    while(a>1){
        int q = a/m;
        int t = m;
        m=a%m; a=t;
        t=y;
        y = x-q*y;
        x = t;
        if(a<1) break;
    }

    if(x<0)
        x+=m0;
    return x;
}

int findMinX(int num[],int rem[],int k){
    int prod=1;
    for(int i=0;i<k;i++){
        prod*=num[i];
    }
    int result(0);
    for(int i=0;i<k;i++){
        int pp = prod/num[i];
        result+=rem[i]*pp*inv(pp,num[i]);
    }
    return result%prod;
}

int main(){
    FILE *fp = freopen("output.txt","w",stdout);
    int num[] = {4,7,9,11};
    int rem[] = {3,4,1,0};
    int k = sizeof(num)/sizeof(num[0]);
    printf("x is %d\n",findMinX(num,rem,k));
    fclose(fp);
    return 0;
}
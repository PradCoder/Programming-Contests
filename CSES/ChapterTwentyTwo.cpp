#include <bits/stdc++.h>

using namespace std;

vector<unsigned int> memo(1,1);

void per(unsigned int n){
    unsigned int su=0;
    for(unsigned int i=1;i<=n;i++){
        su += memo[n-i];
    }
    memo.push_back(su);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int n= 10;
    unsigned int ans = 0;

    if(n>(memo.size()-1)){
        per(n);
    }
    ans = memo[n];
    printf("%u\n",ans);
    for(unsigned int i: memo){
        printf("%u ",i);
    }
    printf("\n");
    return 0;
}
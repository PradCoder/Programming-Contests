#include "bits/stdc++.h"
#include <cstdint>
#include <cstdio>
#include <iterator>

using namespace std;

void solve(vector<int> &v, int n){
    int count;
    count = 0;
    sort(v.begin(),v.end());
    vector<int> m = vector<int>(n,0);
    m[0] = 1;
    for(int i = 0; i < n; i++){
        if(v[i] >= i+1 && i>0){
            m[i] = m[i-1] + 1;
        }else if (v[i] <= i+1 && i>0){
            m[i] = m[i-1];
        }
    }
    printf("%d",m[n-1]);
}

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);

    int t;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
        int n;
        scanf("%d",&n);
        vector<int> v = vector<int>(n,0);
        for(int j = 0; j < n; j++){
            cin >> v[j];
        }
        printf("Case #%d: ",i);
        solve(v,n);
        printf("\n");
    }
    return 0;
}



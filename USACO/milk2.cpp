/*
ID: 2010pes1
TASK: milk2
LANG: C++
*/

#include "bits/stdc++.h"

using namespace std;

int solve1(int n, vector<pair<int,int>> v){
    int s,mx;
    s = v[0].first;
    mx = v[0].second-s;
    int cal = 0;
    for(int i = 0; i<n-1;i++){
        if(v[i].second >= v[i+1].first){
            cal = v[i+1].second - s;
        }else{
            s = v[i+1].first;
            cal = v[i+1].second-s;

        }
        mx = max(cal,mx);
    }
    return mx;
}

int solve2(int n, vector<pair<int,int>> v){
    int s, mx;
    s = v[0].second;
    mx = 0;
    int cal = 0;
    for(int i = 0; i<n-1;i++){
        if(v[i+1].first-s > 0){
            cal = v[i+1].first - s;
        }
        s = v[i+1].second; 
        mx = max(cal,mx);
    }
    return mx;
}

int main(){
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> v = vector<pair<int,int>>(n,{0,0});
    for(int i = 0; i < n; i++){
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(),v.end());
    printf("%d %d\n", solve1(n, v), solve2(n, v));
    return 0;
}

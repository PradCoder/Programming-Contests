/*
ID: 2010pes1
TASK: milk2
LANG: C++
*/

#include "bits/stdc++.h"

using namespace std;

/* So solving for longest interval works 
 * solve1: by scanning for the intersects of schedules 
 * solve2: by scanning for ranges 
 *         sort for start and end time (of first task)
 *         check if following ending time is below after first task end time
 *         take difference between current task being scanned and next task
 * 
*/

int solve1(int n, vector<pair<int,int>> v){
    int s,mx;
    s = v[0].first;
    mx = v[0].second-s;
    int cal = 0;
    for(int i = 0; i<n-1;i++){
        if(v[i+1].first <= v[i].second){
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

    for(int i = 1; i<n; i++){
        if(v[i].second < s){
            s = s;
        }else{
            s = v[i].second;
        }
        cal = v[i+1].first - s;
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

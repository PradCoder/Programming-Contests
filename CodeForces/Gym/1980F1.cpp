#include "bits/stdc++.h"
#include <cstdint>

#define x                   first
#define y                   second
#define PG                  push_back
#define PPB                 pop_back
#define PF                  push_front
#define MP                  make_pair
#define REP0(i,a,b)         for (int i = a; i < b; i++)
#define REP1(i,a,b)         for (int i = a; i <= b; i++)

#define PPC                 __builtin_popcount
#define PPCLL               __builtin_popcountll

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.x != b.x) {
        return a.x > b.x;
    }
    return a.y < b.y;
}

int solveSize(int n,int m,int k,vpi& fountains,vector<ll>& solution){
    map<pair<int,int>,int> idx;
    for(int i = 0; i < k; i++){
        idx[fountains[i]] = i;
    }
    sort(fountains.begin(),fountains.end(),cmp);
    unsigned total = 0;
    int cur = m+1;
    int last = n;
    for (auto e: fountains){
        if(cur > e.y){
            solution[idx[e]] = 1;
            total += (cur - 1) * (last - e.x);
            cur = e.y;
            last = e.x;
        }
    }
    total += (cur - 1) * last;
    return total;
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n, m, k;
        vpi fountains;
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++){
            int x,y;
            cin >> x >> y;
            fountains.push_back({x,y});
        }
        vector<ll> solution = vector<ll>(k,0);
        cout << solveSize(n,m,k,fountains,solution) << '\n';
        for (int i = 0; i < k; i++){
            cout << solution[i] << ((i==k-1) ? "\n" : " ");
        }
    }
    return 0;
}


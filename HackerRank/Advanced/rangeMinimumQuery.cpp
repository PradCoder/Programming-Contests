/*
 * Implement The range minimum query
 * sparse_table
 * segment_tree
 * */
#include "bits/stdc++.h"
#include <cstdint>
#include <utility>

#define F                   first
#define S                   second
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

const ll INF = 1e18;
const int32_t M = 1e9+7;
const int32_t MM=998244353;
#define MAXN  (int)1e5

int solve(int st[MAXN][MAXN], int l, int r){
    int j = (int) log2(r - l +1);
    int minimum = min(st[l][j], st[r - (1 << j) + 1][j]);
    return minimum;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
// Range sum query
    int st[MAXN][MAXN];
    vector<pi> v = vector<pi>();
    int n,q;
    cin >> n >> q;
     
    for (int i = 0; i < n; i++){
        cin >> st[i][0];
    }
    for (int i = 0; i< q;i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }

    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 0; i + (1 << j) < n; i++){
            st[i][j] = min(st[i][j-1], st[i + (1 << (j -1))][j - 1]);
        }
    }
    
    for(int j = 0;j<q;j++){
        cout << solve(st,v[j].first,v[j].second) << "\n";
    }
}

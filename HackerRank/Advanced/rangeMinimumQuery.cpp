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
//#define MAXN  (int)1e5
const int MAX_N = 100005;
const int LOG = 17;
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i ... i+2^j-1]
int bin_log[MAX_N];

int solve(int L , int R){
    int length = R - L + 1;
    int k = bin_log[length];
    int minimum = min(m[L][k], m[R - (1 << k) + 1][k]);
    return minimum;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n,q;
    cin >> n;
    for(int i = 2; i <= n; i++){
        bin_log[i] = bin_log[i/2]+1;
    }

    for (int i = 0; i < n; i++){
        cin >> m[i][0];
    }
    
    // 2) preprocessing, O(N*log(N))
    for(int k = 1; k < LOG; k++){
        for(int j = 0; j + (1 << k) - 1 < n; j++){
            m[j][k] = min(m[j][k-1], m[j+(1<<(k-1))][k-1]);
        }
    }

    // 3) answer queries
    cin >> q;
    for(int i = 0; i< q; i++){
        int L,R;
        cin >> L >> R;
        cout << solve(L,R) << "\n";
    }
    return 0;
}

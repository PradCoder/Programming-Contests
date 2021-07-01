/*
 * Implement The range minimum query
 * sparse_table
 * segment_tree
 * */
#include "bits/stdc++.h"
#include <cstdint>

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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
/** Range sum query
    int st[MAXN][K + 1];
    for (int i = 0; i < N; i++){
        st[i][0] = f(array[i]);
    }

    for(int j = 1; j <= K; j++){
        for(int i = 0; i + (1 << j) <= N; i++){
            st[i][j] = f(st[i][j-1], st [i + (1 << (j -1))][j - 1]);
        }
    }
    **/
    int log[M];
    log[1] = 0;
    for (int i = 2; i <= M; i++){
        log[i] = log[i/2] + 1;
    }
    K = math.log(K);
    int st[M][K + 1]
	cin >> a >> b >> x;
	cout << a << " " << b << " " << x << "\n";
}


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
const int IINF = 1e9;

int solve(vi v, int a){
    vi m = vi(a,0);
    REP0(i,0,a){
        v[i] = IINF;
    }
    m[0] = 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a;
    vi v = vi(a,0);
    REP0(i,0,a){
        cin >> v[i];
    }
    printf("%d",solve(v,a));

    return 0;
}

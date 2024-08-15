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
typedef vector<string> vs;
typedef unsigned int ui;

int solve(int n, int m){
    ll ans = 0;
    for (int i = 0; i <= 30; i++){
        ll x = n & ((1LL << (i+1)) - 1);
        ll t = (1LL << i) - x;
        if (n >= (1LL << i)){
            t = min(t, x+1);
        }
        if (x >= (1LL << i) || t <= m){
            ans |= (1LL << i);
        }
    }
    return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        cout << solve(n,m) << '\n';
    }
    return 0;
}

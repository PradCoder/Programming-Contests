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
typedef unsigned int ui;

/*@power: (x^y)%p
 */
int power(ll  x, unsigned int y,int p){
    int res = 1;
    x = x%p;
    if (x == 0){
        return 0;
    }
    while (y>0){
        if(y & 1){
            res = (res*x)%p;
        }
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
} 

unsigned int solve(ui l, ui r,ui k){
    int mod = 1e9+7;
    return ((power(9/k+1,(ui) r,mod) - power(9/k+1,(ui)l,mod)+mod)%mod);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        ll l, r, k;
        cin >> l >> r >> k;
        cout << solve(l,r,k) << '\n';
    }
    return 0;
}

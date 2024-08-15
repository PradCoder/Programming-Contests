#include "bits/stdc++.h"
#include <iostream>

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

ll solve(ll x,ll y,ll z,ll k){
    ll ans = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if(k%(i*j)) continue;
            ll l = k/(i*j);
            if(l>z) continue;
            ll combos = (ll) (x-i+1)*(y-j+1)*(z-l+1);
            ans = max(ans,combos);
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
        ll x,y,z,k;
        cin >> x >> y >> z >> k;
        cout << solve(x,y,z,k) << endl;
    }
    
    return 0;
}

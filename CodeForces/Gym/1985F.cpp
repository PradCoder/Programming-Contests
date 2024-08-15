#include "bits/stdc++.h"

/**
 * Problem C. Sofia and the Lost Operations
*****
All operations must be applied to the array in the given order. 
More than one operation can be applied to a single position.
*/

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

ll solve(int h,int n, vi& a, vi& c){
    set<pair<ll,int>> S;
    for (int i = 0; i < n; i++){
        S.insert({1,i});
    }
    ll ans = 0;
    while(h>0){
        auto [turn, idx] = *S.begin();
        //Sets are ordered like min heap based on first element
        h -= a[idx];
        ans = turn;
        S.erase(S.begin());
        S.insert({turn+c[idx],idx});
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
        int h,n;
        cin >> h >> n;
        vi a = vi(n,0);
        vi c = vi(n,0);
        for(int& i : a){
            cin >> i;
        }
        for(int& i : c){
            cin >> i;
        }
        
        cout << solve(h,n,a,c) << endl;
    }
    
    return 0;
}

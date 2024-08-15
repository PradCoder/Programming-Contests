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

ll solve(int n, vi h){
    ll ans = 0;
    int m = h[0];
    int sm = h[0];
    while(h[n-1] > 0){
        m = h[0];
        sm = h[0];
        int mi = 0;
        for (int i = 0; i < n-1;i++){
            if(h[i]>h[i+1]){
                h[i] = max(0,h[i]-1);
                if(h[i]>m and i != mi){
                    sm = m;
                }
                m = max(m,h[i]);
                if(m == h[i]){
                    mi = i;
                }
            }
        }
        h[n-1]--;
        ans++;
    }
    ans += m+(m-sm);
    return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vi h(n,0);
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
        cout << solve(n,h) << "\n";
    }
    
    return 0;
}

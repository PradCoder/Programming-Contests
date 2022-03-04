/*
P. AMARASEKERA
2021-05-28

Codeforces Round 773

The trick here is realizing that the averages can be the same for
each pair or it can be bigger than or less than a certain amount
so pair the numbers at the opposite ends of the sorted order to
change up the averages
*/
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

int main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--){
       int n;
       int64_t x;
       cin >> n >> x;
       vector<int64_t> ar(n);
       for (auto& it : ar){
           cin >> it;
       }
       sort(ar.begin(), ar.end());
       vector<bool> vis(n);
       int j = 0, q = 0;
       int ans = 0;
       for (int i = 0; i < n; ++i){
            if (vis[i])
                continue;
            if (ar[i] * x > ar[j]){
                while (ar[i] * x >= ar[j] && j < n){
                    q = ++j;
                }
                q = --j;
            }
            if (i < q && ar[i] * x == ar[q]){
                vis[q--] = 1;
            }else{
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

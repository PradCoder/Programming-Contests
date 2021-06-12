/*
P. Amarasekera
YYYY/MM/DD
2021/03/30 - 2021/04/01


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

const ll INF = 1e18;
const int32_t M = 1e9+7;
const int32_t MM = 998244353;

ll solve(vi coins, int n){
    vector<ll> dp = vector<ll> (n+1,0);
    dp[0] = 1;    
        /*
        target: 4
        coins: [1,2,3]
                0   1   2   3   4
            1   1   1   1   1   1      
            2   1   1   2   2   3        
            3   1   1   2   3   4        
        */
        for (auto c : coins){
            REP1(i,1,n){
                if(i - c < 0){
                    dp[i] += 0;
                }else{
                    dp[i] += dp[i-c];
                }
                }
        }
        ll ans = dp[n];
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    string x;
    cin >> n >> m ;
    vi c = vi(m,0);
    REP0(i,0,m){
        cin >> c[i];
    }

    printf("%lld\n",solve(c,n));
}


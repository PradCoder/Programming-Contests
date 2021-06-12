/*
P. Amarasekera
YYYY/MM/DD
2021/01/30 - 2021/03/30



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
const int32_t MM=998244353;
const int IINF = 1e9;


/*
*/
int solve(vi v, int a, int k){
    vector<int> dp = vi(a,0);
    //sort(v.begin(), v.end());
    dp[0] = 0;
    for (int i = 1; i<k && i<a;i++){
        dp[i] = abs(v[i]-v[0]);
    }
    for(int i = k; i< a;i++){

        vi calc = vi(k,0);
        for(int j = 0; j< k; j++){
            calc[j] = dp[i-(j+1)]+abs(v[i]-v[i-(j+1)]);
        }

        auto ans = min_element(calc.begin(),calc.end());
        dp[i] = calc[distance(calc.begin(),ans)];
    }
    printf("\n");
    return dp[a-1];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,k;
	cin >> a >> k;
    vi v = vi(a,0);
    REP0(i,0,a){
        cin >> v[i];
    }
    printf("%d\n",solve(v,a,k));

    return 0;
}
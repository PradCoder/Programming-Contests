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
typedef vector<long long> vl;
typedef pair<int,int> pi;

const ll INF = 1e18;
const int32_t M = 1e9+7;
const int32_t MM=998244353;

/*
3 8
3 30
4 50
5 60

		0  1  2  3   4   5   6   7   8
3   30  0  0  0  30  30  30  30  30  30
4   50  0  0  0  30  50  50  50  80  80
5   60  0  0  0  30  50  60  60  80  90

1   100
*/
//o(n*w)
void max_self(ll& a, ll b){
	a = max(a,b);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,W;
	scanf("%d%d", &n, &W);
	vl dp(W+1);
	REP0(i,0,n){
		int weight,value;
		scanf("%d%d",&weight,&value);

		for (int weight_already = W - weight; weight_already >= 0; --weight_already){
			
			cout << dp[weight_already+weight] << "-" << dp[weight_already]+value << " ";
			max_self(dp[weight_already+weight],dp[weight_already]+value);
			// cout << weight_already << "-" << (weight_already+weight) << " ";
		}
		cout << "\n";
		for(auto i: dp){
			cout << i << " ";
		}
		cout << "\n";
	}

	ll answer = 0;
	REP1(i,0,W) max_self(answer, dp[i]);
	printf("%lld\n",answer);
}


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
long long solve(vector<vl> vec, int w, int n){
	vector<vl> dp = vector<vl>(n,vl(w+1,0));
	for(int i = 0; i < n; i++){
		for(int j=0; j <= w;j++){
			if(j - vec[i][0] < 0){
				if(i-1<0){
					dp[i][j] = 0;
				}else{
					dp[i][j] = dp[i-1][j];
				}
			}else{
				if(i-1<0){
					dp[i][j] = vec[i][1];
				}else{
					dp[i][j] = max(vec[i][1]+dp[i-1][j-vec[i][0]],dp[i-1][j]);
				}
			}
		}
	}
	// REP0(i,0,n){
	// 	REP1(j,0,w){
	// 		printf("%lld ", dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// long long int i = 5000000000;
	// printf("%lld\n",i);
	return dp[n-1][w];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,w;
	cin >> n >> w;
	vector<vl> v = vector<vl>(n, vl(2,0));
	REP0(i,0,n){
		cin >> v[i][0] >> v[i][1];
	}
	cout << solve(v,w,n) << "\n";
}


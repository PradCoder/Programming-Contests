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

/*
max in current array exclude element at index
3
10 40 70
20 50 80
30 60 90
result: 210

max(exclude non) 10 40 70
newx = 2
max(0,1)
max(exclude 2) 20 50 80
newx = 1
max(0,2)
max(exlude 30 60 90

1
100 10 1
result: 100

7
6 7 8* max(eclude non)
8* 8 3 max(exclude 2) dp[i] + max(s[i], s[])
2 5* 2 max(exclude 1)
7* 8 6 max(exclude )
4 6 8*
2 3* 4
7* 5 1
result: 46
CABACBA

dp[0][0] = v[0][0]
dp[0][1] = v[0][1]
dp[0][2] = v[0][2]
for(i=1;i<n;i++)
	for(j=0;j<3;j++)
	if(j==0){
		dp[i][j] = max | v[j]+dp[i-1][1] , v[j]+dp[i-1][2]
	}else if(j==1){
		dp[i][j] = max | v[j]+dp[i-1][0],v[j]+dp[i-1][2]
	}else if(j==2){
		dp[i][j] = max | v[j]+dp[i-1][0], v[j]+dp[i-1][1]
	}

}

auto ans = max_element(dp[n-1].begin(),calc[n-1].end());
return dp[n-1][ans];
*/

int solve(vector<vi> v, int n){
	vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(3,0));
	dp[0][0] = v[0][0];
	dp[0][1] = v[0][1];
	dp[0][2] = v[0][2];
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			if(j==0){
				dp[i][0] = v[i][j] + max(dp[i-1][1] , dp[i-1][2]);
			}else if(j==1){
				dp[i][1] = v[i][j] + max(dp[i-1][0],dp[i-1][2]);
			}else if(j==2){
				dp[i][2] = v[i][j] + max(dp[i-1][0], dp[i-1][1]);
			}
		}
	}
	auto ans = max_element(dp[n-1].begin(),dp[n-1].end());
	return dp[n-1][distance(dp[n-1].begin(),ans)];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a ;
	vector<vector<int>> vec;
	vec = vector<vector<int>>(a,vi(3,0));
	for(int i = 0; i<a;i++){
		cin >> vec[i][0] >>vec[i][1]>> vec[i][2];
	}
	cout << solve(vec, a);
}


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

#define F first
#define S second
#define PG push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define N 100003

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int dp[N][2][2][2];
int mod = 1000000007;

int f(int n, int t, int r, int s){
	if(n < 0) return 0;
	if(n==0){
		return !(t|r|s);
	}
	if(dp[n][t][r][s] != -1) return dp[n][t][r][s];
	int res = 0;
	if(t != 0){
		res = ((res + f(n-1,1,r,s))%mod) + f(n-1,0,r,s) % mod;
	}
	if(r != 0){
		res = ((res + f(n-2,t,1,s)) % mod) + f(n-2,t,0,s) % mod;
	}
	if(s != 0){
		res = ((res + f(n-3,t,r,1))%mod) + f(n-3,t,r,0) % mod;
	}
	dp[n][t][r][s] = res;
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k< 2; k++){
				for(int l = 0; l < 2; l++){
					dp[i][j][k][l] = -1;
				}
			}
		}
	}

	int n;
	cin >> n;
	cout<<f(n,1,1,1)<<endl;
	return 0;
	
}

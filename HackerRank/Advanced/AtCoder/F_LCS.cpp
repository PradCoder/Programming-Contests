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
typedef pair<int,string> ps;

const ll INF = 1e18;
const int32_t M = 1e9+7;
const int32_t MM=998244353;

/*
    a x y b
a   1 1 1 1
b   1 1 1 2
y   1 1 2 2 
x   1 2 2 3
b   1 2 2 3



*/
string solve(string s, string t){
	int n = s.length();
	int m = t.length();
    vector<vector<pair<int,<pair<int,int>>>> dp(a.length()+1) = vector<vector<int>>(n+1,vector<int>(m+1, 0));
	REP0(i,0,n){
		REP0(j,0,m){
			if(s[i] == t[j]){
				dp[i+1][j+1] = 1+dp[i][j] ; 
			}else{
				dp[i+1][j+1] = (dp[i][j+1] > dp[i+1][j]) ? dp[i][j+1] : dp[i+1][j];
			}
		}
	}
	REP0(i,0,n+1){
		REP0(j,0,m+1){
			cout << "(" << dp[i][j] << ")";
		}
		cout << "\n";
	}
    return "s";//dp[n][m];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s,t;
	cin >> s >> t;
	cout << solve(s,t)<< "\n";
}


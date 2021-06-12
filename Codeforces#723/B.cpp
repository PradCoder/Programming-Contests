/*
P. AMARASEKERA

2021-05-28

11 and 111 should be enough, number theory question in disguise
111 % 11 = 1
1111 - 1*111 
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

void solve(vi v){
	for (int j : v){
		int n = j % 11;
		int a = j-n*111;
		string s = (a >= 0) ? "YES" : "NO";
		cout << s << endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	vi v = vi(t,0);
	REP0(i,0,t){
		cin >> v[i];
	}
	solve(v);
}


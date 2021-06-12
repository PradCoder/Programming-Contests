/*
P. AMARASEKERA
2021-05-28

Codeforces Round 723

The trick here is realizing that the averages can be the same for
each pair or it can be bigger than or less than a certain amount
so pair the numbers at teh opposite ends of the sorted order to
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

const ll INF = 1e18;
const int32_t M = 1e9+7;
const int32_t MM=998244353;

vi solve(vi v, int n){
	sort(v.begin(), v.end());
	vi u = vi(2*n,0);
	for(int i = 0; i < n; i++){
		u[2*i] = v[i];
		u[2*i+1] = v[2*n-(1+i)];
	}
	return u;
}

string printSol(vi v){
	string s = "";
	REP0(i,0,v.size()-1){
		s += to_string(v[i]) + " "; 
	}
	s += to_string(v[v.size()-1]);
	return s;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,b;
	string c;

	int t;
	cin >> t;
	REP0(i,0,t){
		int n;
		cin >> n;
		vi v = vi(2*n,0);
		REP0(j,0,2*n){
			cin >> v[j];
		}
		cout << printSol(solve(v,n)) << endl;
	}
}


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
    a x y b
a   1 1 1 1
b   1 1 1 2
y   1 1 2 2 
x   1 2 2 3
b   1 2 2 3



*/
string solve(string s, string t){
    vector<pi> dp = vector<pi>(s.length()*t.length());

    return s
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,b;
	string s,t;
	cin >> s >> t;
	cout << solve(s,t)<< "\n";
}


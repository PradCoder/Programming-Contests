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

int solve(vi v){
	int count = 0;
	int c  = 1;
	while(c){
		c  = 0;
		REP0(j,0,v.size()-1){
			if(v[j] > v[j+1]){
				int temp = v[j+1];
				v[j+1] = v[j];
				v[j] = temp;
				c++;
				j++;
			}
		}
		if(c)
			count++;
	}
	return count;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	for(int i = 0;i < tc;i++){
		int n;
		cin >> n;
		vi v = vi(n,0);
		REP0(j,0,n){
			cin >> v[j];
		}
		cout << solve(v) << "\n";
	}
}
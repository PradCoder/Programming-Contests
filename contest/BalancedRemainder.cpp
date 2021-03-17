#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>

#define F first
#define S second
#define PG push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

//keep transferring numbers in cyclic order until everything is balanced
int solve(int n, vi v){
	
	vi rem = vi(3,0);
	int mul = n/3;
	REP(i,0,n-1){
		rem[v[i]%3] += 1;
	}
	int cmax = 0;
	REP(i,0,3-1){
		cmax += abs(rem[i]- mul);
	}
	int ans = (cmax>0) ? cmax-1 : 0;
	return ans;
	
	int c[3] = {0,0,0};
	REP(i,0,3-1){
		int x;
		cin >> x;
		c[x % 3]++;
	}

	REP(i,0,3-1){
		if(c[i] > n / 3){
			int diff = c[i] - n/3;
			c[(i+1)%3] += diff
			moves
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(i,0,t-1){
		int n;
		cin >> n;
		vector<int> v = vector<int>(n);
		REP(j,0,n-1){
			cin >> v[j];
		}
		cout << (solve(n, v)) << endl;
	}
}

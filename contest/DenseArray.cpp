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

int solve(int n, vi v);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	string x;
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

int solve(int n, vi v){
	
	int count = 0;
	REP(i,0,n-2){
		int cmax, cmin;
		cmax = max(v[i],v[i+1]);
		cmin = min(v[i],v[i+1]);
		double q = ((double) cmax)/ ((double) cmin);
		if(q <= 2){
			count = count;
		}else{
			 while(q>2){
				cmin = 2*cmin;
				q = ((double) cmax)/ ((double) cmin);
				count++;
			}
		}

	}
	return count;
}

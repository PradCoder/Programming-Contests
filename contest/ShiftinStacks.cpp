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
string solve(int n, vi v){
	
    sort(v.begin(),v.end());
    ll sum = 0;

    for(auto c: v)
        sum += (ll) c;
    return ((sum/(double)n >= 0.5) ? "YES" : "NO");
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

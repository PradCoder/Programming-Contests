#include "bits/stdc++.h"
#include <iostream>

/**
 * Problem B. Index and Maximum Value
*****
All operations must be applied to the array in the given order. 
More than one operation can be applied to a single position.
*/

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
typedef vector<string> vs;

vector<int> solve(vector<int>& vec, vector<tuple<char,int,int>>& ops){
    priority_queue<int> mpq;
    return vector<int>(ops.size(),0);
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> vec(n,0);
        vector<tuple<char,int,int>> ops;
        for (int i = 0; i < n; i++){
            cin >> vec[i];
        }
        for (int i = 0; i < m; i++){
            char c;
            int a, b;
            cin >> c >> a >> b;
            ops.push_back({c,a,b});
        }
        vector<int> outp = solve(vec,ops);
        for (int i = 0; i < m; i++){
            cout << outp[i] << ((i+1<m) ? " ":"\n");
        }
    }
    return 0;
}

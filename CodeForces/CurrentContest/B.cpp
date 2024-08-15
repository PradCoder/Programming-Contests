#include "bits/stdc++.h"
#include <iostream>

/**
 * Problem C. Sofia and the Lost Operations
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

ll solve(int n, vi& a){
    int m = 0;
    multiset<long long> s;
    for (int i = 0; i < n; i++){
        m = max(m,a[i]);
        if (m > a[i]){
            s.insert(m-a[i]);
        }
    }
    ll cum = 0;
    ll ans = 0;
    ll k = s.size();
    for (auto it = s.begin(); it != s.end(); it++){
        ans += ((*it)-cum)*(k+1);
        //cout << (*it) <<' '<< k <<' ' << cum<< '\n';
        cum += (*it)-cum;
        k--;
    }
    //cout << "Size: "<< s.size() << "\n";
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vi  a(n,0);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << solve(n,a) << "\n";
    }
    return 0;
}
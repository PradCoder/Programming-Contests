#include "bits/stdc++.h"
#include <cstdint>
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

bool check (int n,vi& a, vi& b){
    for (int i = 0; i < n; i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

bool solve(int n,int m, int lvl, vi& a, vi& b, vi& d){
    if (lvl == 0){
        return  d[m-lvl]
    }
    bool state = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i] = d[j];
            state = state || solve(n,m) || check(n,a,b);
        }
    }

        return "YES";
        return "NO";
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n,m;
        cin >> n ;
        vi a = vi(n,0);
        vi b = vi(n,0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0l i < n; i++){
            cin >> b[i];
        }
        cin >> m;
        vi d = vi(m,0);
        for (int i = 0; i < m; i++){
            cin >> d[i];
        }
        
        cout << solve(n,m, m,a,b,d) << endl;
    }
    
    return 0;
}
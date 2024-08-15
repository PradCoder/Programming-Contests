#include "bits/stdc++.h"
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

string solve(int n,int m, vi& a, vi& b, vi& d){
    //if b contains last element in d could be valid
    //otherwise it's guaranteed to be false
    //if it is a candidate:
    //we don't do anything if if a_i == b_i
    //if a_i != b_i we check in a dictionary for howmany
    //occurences of b_i = d_k exist and subtract 1
    //if #of d_k < 0 it's not valid otherwise it is
    bool candidate = false;
    for(int i = 0; i < n; i++){
        if(b[i]==d[m-1])
            candidate = true;
    }
    if(!candidate) return "NO";
    map<int,int> counter;
    REP0(i,0,m){counter[d[i]] = 0;}
    for(int i = 0; i < m; i++){
        counter[d[i]]++;
    }
    for(int i = 0; i<n;i++){
        if(a[i] != b[i]){
            counter[b[i]]--;
        }
        if(counter[b[i]]<0){
            return "NO";
        }
    }
    return "YES";
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
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        cin >> m;
        vi d = vi(m,0);
        for (int i = 0; i < m; i++){
            cin >> d[i];
        }
        
        cout << solve(n,m,a,b,d) << endl;
    }
    
    return 0;
}

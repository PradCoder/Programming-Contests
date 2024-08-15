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

int solve(int n,vi a){
    vi vec = vi(n-1,0);
    for(int i = 0; i< n-1; i++){
         vec[i] = max(a[i],a[i+1]);
    }
    sort(vec.begin(),vec.end(),greater<int>());
    return vec[n-2] - 1; 
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
        vi a = vi(n,0);
        REP0(i,0,n){
            cin >> a[i];
        }
        cout << solve(n,a) << endl;
    }
    
    return 0;
}


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

vi solve(int n,vi x){
   vi ans = 
   //vec[i]*ans[i] > ans[j]
   return vi; 
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n;
        vi vec = vi(n,0);
        for (int i = 0; i < n; i++){
            cin >> vec[i];
        }
        cout << solve(n,vec) << endl;
    }
    
    return 0;
}


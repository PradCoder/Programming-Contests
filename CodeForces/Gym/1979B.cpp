#include "bits/stdc++.h"
#include <cstdint>
#include <math.h>

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

ll solve(int x, int y){
    int count = 1;
    int mx = max(x,y);
    int my = min(x,y);
    int diff = mx-my;
    while(!(diff&1)){
        diff >>= 1;
        count <<= 1;
    }
    return count;
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int x,y;
        cin >> x >> y;
        cout << solve(x,y) << endl;
    }
    
    return 0;
}


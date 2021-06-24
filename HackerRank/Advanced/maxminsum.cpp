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

const ll INF = 1e18;
const int32_t M = 1e9+7;
const int32_t MM=998244353;

int solve0(vi v){
    return 0;
}
int solve1(vi v){
    int ans = v[0], sum = 0;
    for(int r = 0; r < v.size(); ++r){
        sum += v[r];
        ans = max(ans,sum);
        sum = max(sum,0);   
    }
   return ans; 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t,n;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        vi v = vi(n,0);
        for(int j = 0; j < n; j++){
            cin >> v[j];
        }
	    cout << solve0(v) << " " << solve1(v) << "\n";
    } 
}


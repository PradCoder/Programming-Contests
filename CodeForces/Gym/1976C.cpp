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

int solve(int n,int m,vi& programmingSkill,vi& testingSkill){
    //n : number of programmers wanted
    //m : number of testers wanted
    vector<int> dp = vector<int>(n+m,0);
    dp[0] = max(programmingSkill[0],testingSkill[0]);
    for(int i = 0; i < n+m+1; i++){
        for (int j = 0; j < n+m; j++){
            if( i!=j ){
                dp[i] = max(dp[j],programmingSkill[i]+testingSkill[i]);
            }
        }
    }

    return dp[n+m+1];
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
    
    while(t--){
        int m,n;
        cin >> n >> m;
        vi programmingSkill = vi(n+m+1,0);
        vi testingSkill = vi(n+m+1,0);
        
        cout << solve(n,m,programmingSkill,testingSkill) << endl;
    }
    
    return 0;
}


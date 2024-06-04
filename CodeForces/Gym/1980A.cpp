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

int solve(int n,int m,string s){
   int ans = 0;
   vector<int> count = vector<int>(7,0);
   for(int i = 0; i < s.size();i++){
        count[s[i]-'A'] += 1;
   }
   for(int i = 0; i < 7;i++){
        int temp = m-count[i];
        if(temp>0){
            ans += temp;
        }
   }
   return ans; 
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n,m;
        string s;
        cin >> n >> m;
        cin >> s;
        cout << solve(n,m,s) << endl;
    }
    
    return 0;
}


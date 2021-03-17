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

vector<vector<int>> adj;
vector<bool> visit;
int num;

int cut = 0;

int solve(int i){
   visit[i] = true;   
   int sum = 0;
   for (int u: adj[i]){
       if(!visit[u]){
            int num_v = solve(u);
            if(num_v%2 == 0){
                cut++;
            }else{
                sum+=num_v;
            }
       }
  }
   return sum+1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, e;
    cin >> n >> e;
    vector<vector<int>> v = vector<vector<int>>(n);
    REP0(i,0,e){
        int t,f;
        cin >> t >> f;
        v[t-1].push_back(f-1);
        v[f-1].push_back(t-1);
    }
    
    adj = v;
    visit = vector<bool>(n,false);
    num = n;
    solve(0);
    printf("%d\n",cut);
}

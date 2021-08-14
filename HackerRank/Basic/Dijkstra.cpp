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
const int IINF = 1e9;
const int32_t M = 1e9+7;
const int32_t MM=998244353;

vector<vector<pi>> adj;

void dijktra(int num, int s){
   int n = num;
   vi d = vi(n,IINF);
   vi p = vi(n,-1);
   vector<bool> u (n,false);
   
   d[s-1] = 0;

   REP0(i,0,n){
        int v = -1;
        REP0(j,0,n){
            if(!u[j] && (v == -1 || d[j] < d[v])){
                  v = j;    
            }
        }

        if(d[v] == IINF){
            break;
        }

        u[v] = true;
        for(auto e : adj[v]){
            int to = e.first;
            int r = e.second;

            if(d[v] + r < d[to]){
                d[to] = d[v] + r;
                p[to] = v;
            }
        }
   }

   for(int i = 0; i< n; i++){
       if(u[i] && i != (s-1)){
            printf("%d ",d[i]);
       }else if(!u[i]){
            printf("-1 ");
       }
   }

   printf("\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m,q;
	cin >> q;
    REP0(i,0,q){
        cin >> n >> m;
        adj = vector<vector<pi>>(n,vector<pi>());
        REP0(i,0,m){
           int t,f,w;
           cin >> t >> f >> w;
           pi p1(f-1,w);
           pi p2(t-1,w);
           adj[t-1].push_back(p1);
           adj[f-1].push_back(p2);
        }
        int s;
        cin >> s;
        dijktra(n,s);
    }
}


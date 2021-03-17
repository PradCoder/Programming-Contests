#include "bits/stdc++.h"
#include <cstdint>
#include <queue>

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

vector<vi> adj;

void bfs(int num, int s){
    vector<bool> visited = vector<bool>(num,false);
    vi d = vi(num,0);
    queue<int> qu;
    qu.push(s-1);
    visited[s-1] = true;
    d[s-1] = 0;
    while(!qu.empty()){
        int c = qu.front();
        qu.pop();
             for(int u: adj[c]){
               if(!visited[u]){
                 visited[u] = true;
                 d[u] = d[c] + 1;
                 qu.push(u);
                }
            }
    }
    REP0(i,0,num){
        if(visited[i] && (i+1 != s)){
            printf("%d ",d[i]*6); 
        }else if(!visited[i]){
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
        adj = vector<vi>(n, vi());
        REP0(i,0,m){
           int t,f;
           cin >> t >> f;
           adj[t-1].push_back(f-1);
           adj[f-1].push_back(t-1);
        }
        int s;
        cin >> s;
        bfs(n,s);
    }
}


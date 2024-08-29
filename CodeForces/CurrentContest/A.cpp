/**
 * A. Cutting Figure 193/A
*/

#include "bits/stdc++.h"

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
typedef vector<short> vs;

vector<vector<pi>> adj;
vector<vector<int>> adj;

int solve(vector<string>& vec){
    int n = vec.size();
    int m = vec[0].size();
    adj(n*m,vector<pi>);
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < m; j++){
            if(i-1>=0 and vec[i-1][j] == "#"){
                adj[i*j].push_back({i-1,j});
            }
            if(i+1<n and vec[i+1][j] == "#"){
                adj[i*j].push_back({i+1,j});
            }
            if(j+1<m and vec[i][j+1] == "#"){
                adj[i*j].push_back({i,j+1});
            }
            if(j-1<m and vec[i][j-1] == "#"){
                adj[i*j].push_back({i,j-1});
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            adj[i*n+j] = adj[i][j];
        }
    }
}

int n;
vector<bool> visited;
vector<int> tin, low;
int timer;
int cutpoint;

void dfs(intv, int p = -1){
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for(int to : adj[v]){
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                cutpoint++;
            ++children;
        }
    }
    if (p == -1 && children > 1)
        cutpoint++;
}

void find_cutpoints(){
    timer = 0;
    visited.assign(n, false);
    tin.assign(n,-1);
    low.assign(n,-1);
    for (int i = 0; i < n; i++){
        if (!visited[i])
            dfs(i);
    }
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> vec(n,"");
    for (int i = 0; i < n; i++){
        string line;
        cin >> line;
        vec[i] = line;
        solve(vec)
        cout << cutpoint << "\n";
    }
    return 0;
}

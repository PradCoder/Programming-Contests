#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;

vector<vi> adj;
vector<bool> visit;

int num;
int cut = 0;

int bfs(int i){
    visit[i] = true;
    vi d = vi(num, 0);

    queue<int> qu;
    qu.push(i-1);
    visit[i-1] = true;
    d[i-1] = 0;

    while(!qu.empty()){
        int c = qu.front();
        qu.pop();
        for(int u: adj[c]){
            if(!visit[u]){
                visit[u] = true;
                d[u] = d[c] + 1;
                qu.push(u);
            }
        }
    }
    for(int j =1; j<= num; j++){
        if(visit[i] && (j != i)){
            cout << (d[i]*6) << " ";
        }else if(!visit[i]){
            cout << "-1 ";
        }
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, e;
    cin >> n >> e;
    vector<vector<int>> v = vector<vi>(n);
    for(int i = 0; i < n; i++){
        int t,f;
        cin >> t >> f;
        v[t-1].push_back(f-1);
        v[f-1].push_back(t-1);
    }
    visit = vector<bool>(n,false);
    adj = v;
    num = n;
    bfs(0);

    return 0;
}
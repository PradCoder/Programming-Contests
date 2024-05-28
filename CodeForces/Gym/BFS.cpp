#include <vector>
#include <queue>

using namespace std;

int main(){
    vector<vector<int>> adj;
    int n,s;

    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n), p(n);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
                used[u] = true;
                q.push(u);
                d[u] = d[v]+1;
                p[u] = v;
        }
    }

    return 0;
}
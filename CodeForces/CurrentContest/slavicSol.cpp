#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()

int n, m;
char c[50][50];
bool vis[50][50];
bool ok(int i, int j) {
    return (min(i, j) >= 0 && i < n && j < m && c[i][j] == '#' && !vis[i][j]);
}

void dfs(int i, int j) {
    vis[i][j] = true;
    if(ok(i + 1, j))dfs(i + 1, j);
    if(ok(i - 1, j))dfs(i - 1, j);
    if(ok(i, j + 1))dfs(i, j + 1);
    if(ok(i, j - 1))dfs(i, j - 1);
}
void solve() { 
    cin >> n >> m;
    int cnt = 0;
    //2 e upper bound
    forn(i, n)forn(j, m) {
        cin >> c[i][j];
        if(c[i][j] == '#')++cnt;
    }

    if(cnt <= 2) {
        cout << "-1\n";
        return;
    }
    for(int i = 0;i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(c[i][j] != '#') continue;
            for(int a = 0;a < n; ++a) {
                for(int b = 0;b < m; ++b) {
                    vis[a][b] = false;
                }
            }
            bool f = false;
            c[i][j] = '.';
            for(int a = 0;a < n; ++a) {
                for(int b = 0;b < m; ++b) {
                    if(!vis[a][b] && c[a][b] == '#') {
                        if(f) {
                            cout << "1\n";
                            return;
                        }
                        f = true;
                        dfs(a, b);
                    }
                }
            }
            c[i][j] = '#';
        }
    }


    cout << 2 << "\n";

}   
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}

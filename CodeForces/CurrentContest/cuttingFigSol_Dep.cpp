#include "bits/stdc++.h"

/**
 * Problem C. Sofia and the Lost Operations
*****
All operations must be applied to the array in the given order. 
More than one operation can be applied to a single position.
*/

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

int n,m;
char c[50][50];
bool vis[50][50];

bool ok(int i, int j) {
    return (min(i,j) >= 0 && i < n && j < m && c[i][j] == '#' && !vis[i][j]);
}

void dfs(int i, int j){
    vis[i][j] = true;
    if(ok(i+1,j))dfs(i+1,j);
    if(ok(i-1,j))dfs(i-1,j);
    if(ok(i,j-1))dfs(i,j-1);
    if(ok(i,j+1))dfs(i,j+1);
}

void solve() {
    cin >> n >> m;
    int cnt = 0;
    REP0(i,0,n)REP0(j,0,m){
        cin >> c[i][j];
        if(c[i][j] == '#')++cnt;
    }
    if(cnt <= 2){
        cout << "-1\n";
        return;
    }
    REP0(i,0,n){
        REP0(j,0,m){
            if(c[i][j] != '#') continue;
            REP0(a,0,n){
                REP0(b,0,m){
                    vis[a][b] = false;
                }
            }
            bool f = false;
            c[i][j] = '.';
            REP0(a,0,n){
                REP0(b,0,m){
                    if(!vis[a][b] && c[a][b] == '#'){
                        if(f){
                            cout << "1\n";
                            return;
                        }
                        f = true;
                        dfs(a,b);
                    }
                }
            }
            c[i][j] = '#';
        }
    }
    cout << 2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}

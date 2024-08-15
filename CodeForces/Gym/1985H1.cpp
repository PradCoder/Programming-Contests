#include "bits/stdc++.h"
#include <cstdint>

#define x                   first
#define y                   second
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
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<string> vs;
typedef unsigned int ui;

int n, m, minR, maxR, minC,maxC,sz, ans;
vi R,C,freeR,freeC;
vector<vector<bool>> vis;
vector<vector<char>> A;

void dfs(int i, int j){
    if (i <= 0 or i > n or j <= 0 or j > m or vis[i][j] or A[i][j] == '.')
        return;
    
    vis[i][j] = true;

    sz++;
    minR = min(minR,i);
    maxR = max(maxR,i);
    minC = min(minC,j);
    maxC = max(maxC,j);

    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        cin >> n >> m;

        R.assign(n+5,0);
        C.assign(m+5,0);
        freeR.assign(n+5,0);
        freeC.assign(m+5,0);
        vis.assign(n+5, vector<bool>(m+5, false));
        A.assign(n+5, vector<char>(m+5, ' '));

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m;j++){
                cin >> A[i][j];
                if(A[i][j] == '.'){
                    freeR[i]++;
                    freeC[j]++;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if (vis[i][j] or A[i][j] == '.')
                    continue;
                // Reset
                sz = 0;
                minR = 1e9;
                maxR = -1e9;
                minC = 1e9;
                maxC = -1e9;

                dfs(i,j);

                // Expand by 1 since adjacent cells also connect
                minR = max(minR - 1, 1);
                maxR = min(maxR + 1, n);
                minC = max(minC - 1, 1);
                maxC = min(maxC + 1,m);

                //Update prefix sums
                R[minR] += sz;
                R[maxR + 1] -= sz;
                C[minC] += sz;
                C[maxC + 1] -= sz;
            }
        }

        ans = 0;

        for (int i = 1; i <= n; i++){
            R[i] += R[i - 1];
            ans = max(ans, freeR[i]+R[i]);
        }
        for(int i = 1; i <= m; i++){
            C[i] += C[i-1];
            ans = max(ans,freeC[i] + C[i]);
        }

        cout << ans << endl;
    }
    return 0;
}

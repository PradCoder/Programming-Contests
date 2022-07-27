#include "bits/stdc++.h"

using namespace std;

template<class T> bool ckmin(T &a, T b) {return a > b ? a = b, true : false;}

#define forn(i,n) for (int i=0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()

struct option {
    int t, p, id;
    option(int _t, int _p, int _id) : t(_t), p(_p), id(_id) {
    }
};

const int INF = INT_MAX >> 1;

vector<int> get_ans(vector<option> &v){
    int n = sz(v);
    vector<vector<int>> dp(101, vector<int>(n+1, INF));
    dp[0][0] = 0;
    for (int k = 1; k <=n; k++){
        auto [t,p,id] = v[k-1];
        dp[0][k] = 0;
        for (int i = 100; i > 0; i--){
            int prev = max(0, i-p);
            dp[i][k] = dp[i][k-1];
            ckmin(dp[i][k], dp[prev][k-1] + t);
        }
    }

    vector<int> ans;
    int t = dp[100][n];
    if (t == INF) return {-1};
    for (int i = 100; k = n; k >= 1; k--){
        if (dp[i][k] == dp[i][k-1]){
            continue;
        }
        ans.emplace_back(v[k-1].id);
        i = max(0, i-v[k-1].p);
    }

    reverse(all(ans));
    ans.emplace_back(t);
    return ans;
}

void solve(bool flag = true){

    int n, m; cin >> n >> m;
    vector<int> a(n);
    forn(i, n){
        
    }
}

#include "bits/stdc++.h"
#include <cstdint>
#include <utility>

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

const ll INF = 1e9+5;
//const int32_t M = 1e9+7;
//const int32_t MM=998244353;

/*
    a x y b
a   1 1 1 1
b   1 1 1 2
y   1 1 2 2 
x   1 2 2 3
b   1 2 2 3

*/

template <typename T> void max_self(T& a, T b) {
    a = max(a,b);
}

bool first_row_or_column(pair<int,int> p){
    return p.first == 0 || p.second == 0;
}

string solve(string s, string t){
    int n = s.length();
    int m = t.length();
    
    vector<vector<pair<int, pair<int,int>>>> dp(n+1, vector<pair<int,pair<int,int>>>(m+1, {-INF,{0,0}}));

    dp[0][0] = {0, {0,0}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i] == t[j]){
                max_self(dp[i+1][j+1], make_pair(dp[i][j].first + 1, make_pair(i,j)));                         
            }
            max_self(dp[i+1][j], make_pair(dp[i][j].first, make_pair(i,j)));
            max_self(dp[i][j+1], make_pair(dp[i][j].first, make_pair(i,j)));
        }
    }
    pair<int,pair<int,int>> answer = {0,{0,0}};
    for(int i = 0; i <= n; i++){
        for(int j = 0;j <= m; j++){
            max_self(answer, make_pair(dp[i][j].first, make_pair(i,j)));
        }
    }
    string ans;
    pair<int,int> cur = answer.second;
    while(!first_row_or_column(cur)){
        int i = cur.first;
        int j = cur.second;
        pair<int,int> previous = dp[i][j].second;
        if(previous == make_pair(i-1,j-1)){
            ans+= s[i-1];
        }
        cur = previous;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s,t;
	cin >> s >> t;
	cout << solve(s,t)<< "\n";
}


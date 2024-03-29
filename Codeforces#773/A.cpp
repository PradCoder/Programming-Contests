/*
P. AMARASEKERA
2021-05-28

Codeforces Round 723

The trick here is realizing that the averages can be the same for
each pair or it can be bigger than or less than a certain amount
so pair the numbers at the opposite ends of the sorted order to
change up the averages
*/
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
const int32_t M = 1e9+7;
const int32_t MM=998244353;
    
typedef struct triangle{
    vector<pair<int,int>> vp;
} triangle;

int solve(triangle t){
    pair<int,int> a,b,c;
    a = t.vp[0];
    b = t.vp[1];
    c = t.vp[2];
    int ans = 0;
    if((a.second == 0 && b.second == 0) ||
        (a.second == 0 && c.second == 0) ||
        (b.second == 0 && c.second == 0)){
        ans = 0;
        return ans;
    }
    if(a.second == b.second){
        ans = abs(a.first - b.first);
        if (a.second - b.second < a.first - b.first){
            ans = 0;
        }
    }else if(a.second == c.second){
        ans = abs(a.first - c.first);
        if (a.second - c.second < a.first - c.first){
            ans = 0;
        }
    }else if(b.second == c.second){
        ans = abs(b.first - c.first);
        if (b.second - c.second < b.first - c.first){
            ans = 0;
        }
    } 
    
    vector<pair<int,int>> ls = t.vp;
    int n = ls.size(); 
    for(int i = 0; i < ls.size(); i++){
        if (ls[i].first > ls[(i+1)%n].first){
            ans = abs(ls[i].first-ls[(i+1)%n].first); 
        }
    }

    return ans;
}

int main(){
    (*cin.tie(0)).sync_with_stdio(0);
    int n;
    cin >> n;
    vector<triangle> ts(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            pair<int,int> p;
            cin >> p.first >> p.second;
            ts[i].vp.push_back(p);
        }
    }
    for(auto i : ts){
        cout << solve(i) <<"\n";
    }
    return 0;
}


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
    return 98;
}

int main(){
    int n;
    cin >> n;
    vector<triangle> ts(5);
    ts.resize(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            pair<int,int> p;
            cin >> p.first >> p.second;
            ts[i].vp.push_back(p);
            cout << p.first << " " << p.second << "\n";
        }
        for(auto i : ts){
            cout << solve(i);
        }
    }
    return 0;
}


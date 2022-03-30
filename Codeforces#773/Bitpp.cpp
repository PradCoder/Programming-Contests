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

int solve(){
}

int main(){
    (*cin.tie(0)).sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s.find('+') != s.end()){
            ans++;
        }else{
            ans--;
        }
    }
    cout << ans;
    return 0;
}


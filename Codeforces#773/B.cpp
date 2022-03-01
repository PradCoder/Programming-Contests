/*
P. AMARASEKERA
2021-05-28

Codeforces Round 773

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

int main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        map <int, int> d;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            d[x]++;
        }
        int cnt = 0;
        for (auto i : d){
            ++cnt;
        }
        int cur_cnt = cnt;
        for (int k = 1; k <= n; k++){
            cout << max(k,cnt) << "\n";
        }
    }
    return 0;
}

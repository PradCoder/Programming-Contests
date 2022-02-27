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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b,c,d,e,f,ans = 0;
        cin >> b >> a >> d >> c >> f >> e;
        if(a == c && e < a) ans = abs(b-d);
        else if (c == e && a < c) ans = abs(f-d);
        else if (a == e && c < a) ans = abs(b-f);
        cout << ans << "\n";
    }
    return 0;
}

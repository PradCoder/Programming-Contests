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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    while(t--){
        int l,r;
        cin >> l >>  r;
        cout << (int)log2(r) << '\n';
    }
    return 0;
}

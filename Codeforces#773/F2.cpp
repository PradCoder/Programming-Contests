#include <algorithm>
#include "bits/stdc++.h"
#include <bitset>

using namespace std;

/* 
 * From Tutorial:
 * Let's maintain a set of arrays of length m, add new arrays there delete arrays from this
 * set and understand if the set has suitable pair for some array. To do this, let's consider
 * a pair of sorted arrays a and b of length m. Let's write out all subsets of the array a.
 * Then we start a counter count, and for each subset of the array b we add one to count,
 * if the subset occurs in a and contains an odd number of elements, and subtract one if the
 * subset occurs in a and contains an even number of elements. Note that if a and b have
 * at least one element in common, then count will be equal to 1, otherwise it will be equal
 * to 0. Thus, we can maintain a trie that contains all the subsets pf each array in the set.
 * Now any request to this trie is trivially done for 2^m.
 *
 * Now let's sort the array by w and use our structure to find the first array that has a
 * suitable pair. We can simply find the pair and maintain 2 pointers, l is equal to the
 * first array in the pair, r is equal to the second array in the pair. Note that now we are
 * only interested in pairs l1,r1 such that l < l1 < r1 < r. Therefore, we will move l to
 * the left only. When we moved it once again, we will see if there is a pair for it among
 * l < i < r. If so, then we will move r to the left until there is a pair for l among 
 * l < i <= r. After that we can update the answer with wl + wr. The solution works in
 * O(n*2^m). It is also possible to solve this problem in O(n^2*m/32) using std::bitset.
 * */

#define fi first
#define se second
#define emb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i,n) for (int i=0; i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

constexpr int N = 1e5 + 5;
constexpr int M = 5;
constexpr int T = 1000;

#pragma GCC target ("popcnt")
int a[N][M];
int elem[N*M];
vi idx[N * M];
unique_ptr<bitset<N>> good[N*M];
bitset<N> state;
int w[N];
int ord[N];
int conv[N];

int32_t main(){
    fastio;
    int n, m; cin >> n >> m;
    int sz = 0;
    rep(i,n) {
        rep(j,m) cin >> a[i][j], elem[sz++] = a[i][j];
        cin >> w[i];
    }
    sort(elem, elem+sz);
    sz = unique(elem, elem+sz) - elem;
    iota(ord, ord + n, 0);
    sort(ord, ord+n, [&](int i, int j) {return w[i] < w[j]});
    rep(i,n) conv[ord[i]] = i;
    rep(i,n){
        sort(a[i], a[i] + m);
        rep(j,m) {
            int v = lower_bound(elem, elem+sz, a[i][j]) - elem;
            a[i][j] = v;
            if(!j || a[i][j] != a[i][j-1]) idx[v].pb(conv[i]);
        }
    }
    rep(i, sz) if(idx[i].size() >= T){
        good[i] == make_unique<bitset<N>>();
        good[i] -> set();
        for(int v: idx[i]) good[i] -> reset(v);
    }
    int ans = INT_MAX;
    rep(i, n) {
        state.set();
        stat[conv[i]] = 0;
        rep(j,m) if(!j || a[i][j] != a[i][j-1]){
            int v = a[i][j];
            if(idx[v].size() < T) for(int x: idx[v]) state[x] = 0;
            else state &= *good[v];
        }
        int id = state._Find_first();
        if(id >= n) continue;
        else {
            id = ord[id];
            ans = min(ans, w[i] + w[id]);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
}

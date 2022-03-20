#include <algorithm>
#include <array>
#include <map>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>

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

#define ll long long
#define ld long double
#define pb push_back
#define emb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(),a.rend()

const int mxk = 10;

struct arr {
    array<int, mxk> a;
    int w;
};


bool operator<(const arr& a1, const arr& a2){
    return a1.w < a2.w;
}

struct node {
    unordered_map<int,int> go;
    int cnt;

    void clear(){
        cnt = 0;
        go.clear();
    }
};

int n, k;
vector<arr> a;
int gsz;
vector<node> g;

int new_node(){
    g[gsz].clear();
    gsz += 1;
    return gsz - 1;
}

int build(){
    gsz = 0;
    g.resize(n * (1 << k) + 1);
    return new_node();
}

inline int go(int v, int c){
    if(g[v].go.find(c) == g[v].go.end()){
        return (g[v].go[c] = new_node());
    }
    return g[v].go[c];
}

void add_to_g(const array<int, mxk>& x, int c, int v, int i){
    if(i == k){
        g[v].cnt += c;
        return;
    }
    add_to_g(x,c,v,i+1);
    add_to_g(x,c,go(v,x[i]), i+1);
}

void add_to_g(const array<int, mxk>& x, int c){
    add_to_g(x,c,0,0);
}

inline void add_to_g(const arr &x, int c){
    return add_to_g(x.a, c);
}

int get_cnt(const array<int,mxk>& x, int v, int i){
    if(i==k){
        return g[v].cnt;
    }
    int res = get_cnt(x,v,i+1);
    if (g[v].go.find(x[i]) != g[v].go.end()){
        res -= get_cnt(x, g[v].go[x[i]], i+1);
    }
    return res;
}

int get_cnt(const array<int, mxk>& x){
    return get_cnt(x,0,0);
}

inline int get_cnt(const arr& x){
    return get_cnt(x.a);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i){
        for(int j=0; j<k; ++j){
            cin >> a[i].a[j];
        }
        cin >> a[i].w;
    }
    sort(all(a));
    for (int i = 0; i < n; ++i){
        sort(a[i].a.begin(), a[i].a.begin() + k);
    }
    build();
    int res = -1;
    int i = 0;
    while (i < n && get_cnt(a[i]) == 0){
        add_to_g(a[i], 1);
        i += 1;
    }
    if (i >= n){
        cout << -1 << "\n";
        return 0;
    }
    int j = i;
    while (get_cnt(a[i]) != 0){
        j -= 1;
        add_to_g(a[j], -1);
    }
    res = a[i].w + a[j].w;
    for (i+= 1; i < n && j > 0; ++i){
        while(get_cnt(a[i]) != 0){
            j -= 1;
            add_to_g(a[j], -1);
        }
        res = min(res, a[i].w + a[j].w);
    }
    cout << res << "\n";
    return 0;
}

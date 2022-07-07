#include "bits/stdc++.h"
#include <cmath>

/*
 *
 * */
using namespace std;

constexpr int MOD = 998244353, ROOT = 3;

int add(int a, int b) {
    a += b;
    return a - MOD * (a >= MOD);
}

int sub(int a, int b) {
    a -= b;
    return a + MOD * (a < 0);
}

int mult(int a, int b) {
    return 1ll * a * b % MOD;
}

int power(int a, int b) {
    int prod = 1;
    for (; b; b >>= 1, a = mult(a,a))
        if (b & 1)
            prod = mult(prod, a);
    return prod;
}

void fft(vector<int> &a) {
    int n = a.size(), lg = floor(log2(n));
    assert((1 << lg) == n);

    for (int i = 0; i < n; i++) {
        int j = 0;
        for (int bit = 0; bit < lg; bit++) {
            j ^= (i >> bit & 1) << (lg - bit - 1);
        }
        if (i < j){
            swap(a[i], a[j]);
        }
    }
    
    for (int length = 1; length < n; length <<= 1) {
        int root = power(ROOT, (MOD - 1) / (length << 1));
        for (int i = 0; i < n; i += length << 1){
            for (int j = 0, x = 1; j < length; j++, x = mult(x, root)) {
                int value = mult(a[i + j + length], x);
                a[i + j + length] = sub(a[i + j], value);
                a[i + j] = add(a[i+j], value);
            } 
        }
    }
}


vector<int> multiply(vector<int> a, vector<int> b){
    int result_size = int(a.size() + b.size()) - 1, n = 1;
    while (n < result_size)
        n <<= 1;

    a.resize(n);
    b.resize(n);
    fft(a), fft(b);

    for (int i = 0; i < n; i++){
        a[i] = mult(a[i], b[i]);
    }

    fft(a);
    reverse(a.begin() + 1, a.end());

    int inv_n = power(n, MOD - 2);
    for (auto &x : a){
        x = mult(x, inv_n);
    }

    a.resize(result_size);
    return a;
}

void solve(int l, int r, const vector<int> &a, const vector<int> &b, vector<int> &c) {
    if (r - l == 1)
        return;
    
    int m = (l + r) >> 1;
    solve(l, m, a, b, c);
    solve(m, r, a, b, c);

    auto prod = multiply(vector<int>(a.begin() + l, a.begin() + m),
                         vector<int>(b.begin() + m, b.begin() + r));

    for (int i = 0; i < int(prod.size()); i++)
        c[i + l + m] = add(c[i + l + m], prod[i]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<int> positions(m);
    vector<bool> is_special(n);
    for (auto &pos : positions) {
        cin >> pos;
        pos--;
        is_special[pos] = true;
    }

    vector<int> p2(m + 1, 1);
    for (int i = 1; i <= m; i++){
        p2[i] = add(p2[i-1],p2[i-1]);
    }

    int sum = 0;
    for (int rot : {0, 1}) {
       vector<int> first(n), second(n);
       for (int i = 0; i < m; i++) {
            first[positions[i]] = p2[i];
            if (positions[i] - rot >= 0){
                second[positions[i] - rot] = p2[m - 1 - i];        
            }
       }

       for (int i = n - 2; i >= 0; i--){
            second[i] = add(second[i], second[i+1]);
       }

       vector<int> ways(2*n);
       solve(0, n, first, second, ways);

       for (int i = 0; i < n; i++){
            first[i] = mult(first[i], i);
       }
       
       vector<int> to_sub(2*n);
       solve(0, n, first, second, to_sub);

       for (int i = 0; i < n; i++){
            sum = add(sum, mult(a[i], sub(mult(i, ways[2 * i]), to_sub[2 * i])));
       }

       for (int i = 0, pref = 0, tot = 0; i < n; i++){
            sum = add(sum, mult(a[i], sub(mult(i, sub(p2[pref],1)), tot)));

            if(is_special[i]){
                tot = add(tot, mult(i, p2[pref]));
                pref++;        
            }
       }

       reverse(a.begin(), a.end());
       reverse(is_special.begin(), is_special.end());
       reverse(positions.begin(), positions.end());
       for (auto &pos : positions)
           pos = n - 1 - pos;
    }

    cout << mult(sum,power(sub(p2[m], 1), MOD - 2)) << '\n';
}

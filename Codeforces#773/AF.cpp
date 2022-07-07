#include "bits/stdc++.h"
#include <random>

using namespace std;

typedef long long ll;
typedef double ld;
mt19937 rnd(228);
#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)

const int M = 5e4 + 239;
const int X = (int_ (int) (1e8) + 239;
const int T = (1<< 17) + 239;
const ld pi = acos((ld)-1.0);

int n, l, k, bd, x[M], y[M];
int idx[M], sz_idx;

int divide(int a, int b) {
    if (a >= 0 || a % b == 0) {
        return a / b;
    }
    return -(abs(a) / b) - 1;
}

class Hasher {
public:
    size_t operator()(const pair<int,int>& key) const {
        return ((ll)(key.first + X) << 30LL) + (ll
    }
};

struct helper {
    int R = 0;
    int l = 0;
    int r = 0;
    unordered_map<pair<int,int>, unordered_set<int>, Hasher> in;

    template <typename P>
    void upload(int x, int y, P pred) {
        int xi = divide(x, R);
        int yi = divide(y, R);
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = 1; dy <= 1; dy++) {
                auto it = in.find(make_pair(xi + dx, yi +dy));
                if (it != in.end()) {
                    for (int i : it->second) {
                        if (pred(i)) {
                            idx[sz_idx++] = i;
                        }
                    }
                }
            }
        }
    }

    void add(int i) {
        int xi = divide(::x[i], R);
        int yi = divide(::y[i], R);
        in[make_pair(xi, yi)].insert(i);
    }
}

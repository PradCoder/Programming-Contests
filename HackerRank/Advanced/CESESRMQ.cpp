#include "bits/stdc++.h"
#include <cstdint>
#include <utility>

using namespace std;

const int MAX_N = 200005;
const int LOG = 18;
int st[MAX_N][LOG];
//int bin_log[MAX_N];

int query(int L, int R){
    int length = R - L + 1;
    // int k = bin_log[length];
    int k = log2(length);
    return (min(st[L][k],st[R-(1<<k)+1][k]));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    // for(int i = 2; i<=n;i++){
    //     bin_log[i] = bin_log[i/2]+1;
    // }

    for(int i = 0; i < n; i++){
        cin >> st[i][0];
        // cout << st[i][0];
    }
    for(int k = 1; k < LOG ;k++){
        for(int j = 0; j + (1<<k) - 1 < n; j++){
            st[j][k] = min(st[j][k-1], st[j+(1<<(k-1))][k-1]);
        }
    }
    // cout << "\n";

    for (int i = 0; i < q; i++){
        int L,R;
        cin >> L >> R;
        // cout << L-1 << R-1 << "\n";
        cout << query(L-1, R-1) << "\n";
    }
    
    return 0;
}

#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    bool ok = false;
    if(a[1] % a[0] == 0)
        ok = true;
    for (int i = 1; i < n; i++){
        if(a[i-1] > a[i] && a[i] % a[0] != 0){
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
    int tt; cin >> tt;
    while (tt--) solve();
}

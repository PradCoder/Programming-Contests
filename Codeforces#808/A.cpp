#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    bool ok = true;
    for (int i = 1; i < n; i++){
        if(a[i] % a[0] != 0){
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

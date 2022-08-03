#include "bits/stdc++.h"

using namespace std;

void solve(){
    int l, r, x;
    cin >> l >> r >> x;
    int ans = r/x + r%x;
    int m = r / x * x - 1;
    if(m >= l){
        ans = max(ans, m/x + m % x);
    }
    cout << ans;
}

int main(){
    int t = 1;
    bool multi = true;
    if (multi) {
        cin >> t;
    }
    for (; t != 0; --t) {
        solve();
        cout << "\n";
    }
    return 0;
}

#include "bits/stdc++.h"

using namespace std;

void solve(){
    int n, minX, minY, maxX, maxY;
    cin >> n;
    minX = minY = maxX = maxY = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        minX = min(x, minX);
        minY = min(y, minY);
        maxX = max(x, maxX);
        maxY = max(y, maxY);
    }
    cout << (2 * (maxX + maxY - minX - minY)) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

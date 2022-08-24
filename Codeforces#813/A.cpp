#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t, n, k; 
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x > k and i <= k) ans++;
    } 
    cout << ans << "\n";
  }
  
}

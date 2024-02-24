#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, ans = 1;
    cin >> n;
    const unsigned long mod = 1e9+7;
    for(int i = 0; i < n; i++){
        ans = (ans << 1) % mod;
    }
    cout << ans << "\n";
    return 0;
}

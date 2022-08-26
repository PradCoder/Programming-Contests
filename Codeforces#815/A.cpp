#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long x = a * d;
        long long y = c * b;
        if (x == y) {
            cout << "0";
        } else if (y != 0 && x % y == 0 || x != 0 && y % x == 0){
            cout << "1";
        } else {
            cout << "2";
        }
        cout << "\n";
    }
    return 0;
}

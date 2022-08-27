#include "bits/stdc++.h"

using namespace std;

int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << ((a == b && b == 1) ? 0 : ((a + b) + min(a,b) - 2)) << "\n";
    }
    return 0;
}

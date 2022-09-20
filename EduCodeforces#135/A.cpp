#include "bits/stdc++.h"
#include <algorithm>

using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        cout << max_element(a.begin(), a.end()) - a.begin() + 1 << "\n";
    }
    return 0;
}

#include "bits/stdc++.h"

using namespace std;

int main(){
    int t, a;
    string s;
    cin >> t;
    while(t--){
        cin >> a >> s;
        sort(s.begin(), s.end());
        cout << ((a == 5 && s == "Timru") ? "YES" : "NO") << "\n";
    }
    return 0;
}

#include "bits/stdc++.h"

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)

int main(){
    int t;
    cin >> t;
    forn(tt,t) {
        string s, a;
        cin >> s >> a;
        bool yes = false;
        forn(i, s.length())
            if (s[i] == a[0] && i % 2 == 0)
                yes = true;
        cout << (yes ? "YES" : "NO") << "\n";
    }
    return 0;
}

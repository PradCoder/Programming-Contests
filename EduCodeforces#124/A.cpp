#include "bits/stdc++.h"

#define forn(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main(){
    int t; cin >> t;
    forn(i,t){
        int n;
        cin >> n;
        cout << int(pow(2,n)-1) << "\n";
    }
    return 0;
}

#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> d;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            d.insert(x);
        }
        int cnt = d.size();
        for(int i = 1; i <= n;i++){
            cout << max(i,cnt) << " ";
        }
        cout << "\n";
    }
    return 0;
}

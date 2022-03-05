#include "bits/stdc++.h"

using namespace std;

int solve(int x, vector<int> v){
    return
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        vector<int> v;
        for(int i = 0; i < n; i++){
            cin >> v[i]; 
        }
        cout << solve(x,v) << "\n";
    } 
    return 0;
}

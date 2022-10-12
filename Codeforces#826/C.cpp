#include "bits/stdc++.h"

using namespace std;

long long solve(vector<int> vec){
    long long acc = 0;
    for (int i : vec){
        acc += i;
    }
    return acc;
}

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> vec(n,0);
        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }
        cout << solve(vec) << "\n";
    }
    return 0;
}

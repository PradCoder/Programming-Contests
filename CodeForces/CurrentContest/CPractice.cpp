#include "bits/stdc++.h"

using namespace std;

int measure(int k, vector<int> p, vector<int> v){
    int val = 0;
    for (int i = 0; i < k; i++){
        val += abs(p[i]-v[i]);
    }
    return val;
}

void search(int m, int k, vector<int> v1, vector<int> v2){
    if(k == n){
        v1.push_back(k);
        v2.push_back(k);
    } else {
        search(m,k+1,v1,v2);
        
    }

}

void good(int m, vector<int> p){
    vector<int> a1;

    vector<int> a2;
    return -1;
}

int main(){
    int t;
    cin >> t;
    int n;
    while (t--){
        cin >> n;
        vector<int> p(2*n,0);
        for (int i = 0; i < 2*n; i++){
            cin >> p[i];
        }
        cout << p.size() << "\n";
        cout << good(n,p) << "\n";
    }
    return 0;
}
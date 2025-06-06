#include "bits/stdc++.h"

using namespace std;

bool check (vector<pair<int,int>> &v, double m){
    int count = 0;
    for (int i = 0; i < v.size(); i++){
        int mile = i+1;
        if (!(v[i].first <= m * mile && m * mile <= v[i].second)){
                count++;
        }
    }
    return count;
}

double solve(vector<pair<int,int>> &v){
    double m, l, r;
    pair<int, int> lst =  v[v.size()];
    l = lst.first;
    r = lst.second;
    m = double((float(r-l)/2)/(float(v.size())));
    while (l < r ){
        if (check(v,l) < check(v, r)) {
            l = m;
        }else if (check(v,l) > check(v, r)){
            r = m;
        }
        m = double((float(r-l)/2)/(float(v.size())));
    }
    return m;
}

int main(){
    int t;
    cin >> t;
    int k = 0;
    while(t--){
        k++;
        int n;
        vector<pair<int,int>> v;
        cin >> n;
        for (int i = 0; i < n; i++){
            int f,s;
            cin >> f >> s;
            v.push_back({f,s});
        }
        cout << "Case #" << k << ": " << solve(v) << "\n";
    }
    return 0;
}

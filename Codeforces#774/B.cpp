#include "bits/stdc++.h"

using namespace std;

bool Sum (vector<int> ai) {
    bool al = true;
    //make partitions of sets and try solving those?
    for (int i = 0; i < ai.size(); i++){
        
    }
    return al;
}

bool Count (vector<int> ai) {
    bool bl = true;

    return bl;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        vector<int> ai;
        cin >> n;
        for(int j = 0; j < n; j++){
            int ip;
            cin >> ip;
            ai.push_back(ip);
        }
        string s;
        s = (Sum(ai) && Count(ai)) ? "YES\n" :"NO\n";
    }
    return 0;
}


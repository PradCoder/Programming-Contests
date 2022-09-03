#include "bits/stdc++.h"

using namespace std;

int gcd_(int a, int b){
    while(b != 0){
        int t = a;
        a = b;
        b = t%b;
    }
    return a;
}

int main(){
    int t, a;
    cin >> t;
    vector<int> prev;
    while(t--){
        cin >> a;
        int count = 0;
        unordered_map<int, int> prev;
        if(prev[a] != prev.end()){
            for (int i = 1; i < a+1; i++){
                for (int j = 1; j < a+1; j++){
                    int gcd = (i < j) ? gcd_(i, j) : gcd_(j, i);
                    int lcm = (i*j)/gcd;
                    if((lcm/gcd) <= 3){
                        count++;
                    }                
                }
            }
        }
        prev.push_back(count);
        cout << count << "\n";
    }
    return 0;
}

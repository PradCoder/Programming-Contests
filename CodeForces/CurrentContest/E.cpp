#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> val(51,0);
    int t = n*50;
    while(t--){
        int i;
        cin >> i;
        val[i] += 1;
    }
    int count = 0;
    for (int i = 1; i < 51; i++){
        if (2*n < val[i]){
            cout << i << " "; 
            count++;
        }
    }
    if (count == 0){
        cout << "-1";
    }
    return 0;
}
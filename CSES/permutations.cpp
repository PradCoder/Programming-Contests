#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ar(n,0);
    int j = 0;
    bool exists = true;
    for (int i = 0; i < n; i++){
        if(j>=n){
            exists = false;
            cout << "NO SOLUTION";
            break;
        }
        ar[j] = i+1;
        if(n&1){
            j = (i&1) ? (j-2) : (j+3);
        }else{
            j = (i&1) ? (j-1) : (j+2);
        }
    }
    if(exists){
        for (int i = 0; i < n; i++){
            cout << ar[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}

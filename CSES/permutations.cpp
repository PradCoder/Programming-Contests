#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n > 1 && n <= 3){
        cout << "NO SOLUTION";
    }else{
        vector<int> ar(n,0);
        for(int i = 0; i < n/2; i++){
            ar[i] = (i+1)*2;
        }
        for(int i = n/2; i < n; i++){
            ar[i] = (i-n/2)*2+1;
        }
        for(int i = 0; i < n; i++){
            cout << ar[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

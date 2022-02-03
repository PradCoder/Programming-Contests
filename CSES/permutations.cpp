#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1;
    }else if( n&1 && n > 3){
        vector<int> vec = vector<int>(n,0);
        for(int i = 0; i < n; i++){
            vec[((1+i)*i+n-1)%n] = i+1;
        }
        int i = 0;
        for(; i < n-1; i++){
            cout << vec[i] << " ";
        }
        cout << vec[i+1];
    }else{
        cout << "NO SOLUTION";
    }
    return 0;
}

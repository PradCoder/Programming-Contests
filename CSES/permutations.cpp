#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1;
    }else if( n&1 && n > 3){
        vector<int> vec = vector<int>(n,0);
        for(int i = 0; i < n; i++){
            vec[(1*i+n-1)%n] = i+1;
        }
        for(int i : vec)
            cout << i;
    }else{
        cout << "NO SOLUTION";
    }
    return 0;
}

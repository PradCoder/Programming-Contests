/* 2nd question CSES
 * 
 *
 * */

#include "bits/stdc++.h"

using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> vec = vector<int>(n-1,0);
    
    for (int i = 0; i < n-1; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    int i = 0;
    for(; i < n-1; i++){
        if(i+1 != vec[i]){
           break; 
        }
    }
    
    cout << i+1;
    return 0;
}

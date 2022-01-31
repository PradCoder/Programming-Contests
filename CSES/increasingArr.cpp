#include "bits/stdc++.h"

using namespace std;

long int solve(int n, vector<long int> vec){
    if(n == 1){
        return 0;
    }
    long int m = 0;
    for(int i = 1; i < n; i++){
       if(vec[i-1] > vec[i]){
           m += vec[i-1] - vec[i];
           vec[i] += vec[i-1] - vec[i];

       } 
    }
    return m;
}

int main(){
    int n;
    vector<long int> vec;
    cin >> n;
    vec = vector<long int>(n,0);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    cout << solve(n,vec);
    return 0;
}

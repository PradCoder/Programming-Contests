#include "bits/stdc++.h"

using namespace std;

bool check(vector<int> vec){
    bool state = true;
    int n = vec.size();
    for(int i = 0; i < n; i++){
        bool temp = false;
        if(i+1 < n){
            temp = temp || (vec[i] == vec[i+1]+1) || (vec[i]+1 == vec[i+1]);
        }
        if(i-1 >= 0){
            temp = temp || (vec[i]+1 == vec[i-1]) || (vec[i] == vec[i-1]+1);
        }
        state = state && temp;
    }
    return state;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vec(n,0);
        for (int i = n/2; i < n; i++){
            vec[i] = i-n/2+1;
        }
        for(int i = 0; i < n/2; i++){
            vec[i] = n-n/2+1+i;
        }
        if(check(vec)){
            for (int i : vec){
                cout << i << " ";
            }
            cout << "\n";
        }else{
            cout << "-1\n";
        }
    }
    return 0;
}

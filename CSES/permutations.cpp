#include "bits/stdc++.h"

using namespace std;

bool check(vector<int> arr){
    bool sa = true;
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        cout << arr[i] << " " << arr[i+1] << "\n";
        if (abs(arr[i]-arr[i+1]) == 1){
            sa = !sa;
        }
    }
    cout << sa << "\n";
    return sa;
}

int main(){
    int n;
    cin >> n;
    vector<int> ar(n,0);
    for (int i = 1; i <= n; i++){
        ar[i-1] = i; 
        cout << i << " ";
    }

    cout << "\n";

    for (int i = 0; i < n; i++){
        for(int j = i; j < n; j+=2){
           int a = ar[i%n];
           ar[i%n] = ar[(i+1)%n];
           ar[(i+1)%n] = a;
        }
        if(check(ar)){
           break;         
        }
        for (int i = 1; i <= n; i++){
            ar[i-1] = i; 
            cout << i << " ";
        }
        cout << "\n"; 
    }

    if(check(ar)){
        for (auto i : ar){
            cout << i << " ";
        }
    }else{
        cout << "NO SOLUTION";
    }
    cout << "\n";
    return 0;
}

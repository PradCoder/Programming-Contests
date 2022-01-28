/**
 * Problem 1 from the CSES problem set
 * 
 **/

#include "bits/stdc++.h"

using namespace std;

int main(){
    long long n;
    cin >> n;
    while (n != 1){
        if(!(n&1)){
            cout << n;
            n = n/2;
        }else{
            cout << n;
            n = n * 3 + 1;
        }
        if(n != 1){
            cout << " ";
        }
    }
    cout << " " << n;

    return 0;
}

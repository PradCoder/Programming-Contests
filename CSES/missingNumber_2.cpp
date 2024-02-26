/* 2nd question CSES
 * 
 *
 * */

#include "bits/stdc++.h"

using namespace std;

int main(){
    long n,sum; 
    sum = 0;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int j = 0;
        cin >> j;
        sum += j;
    }

    cout << (n*(n+1))/2-sum;
    return 0;
}

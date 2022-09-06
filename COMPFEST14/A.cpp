#include "bits/stdc++.h"
 
using namespace std;
 
int main(){
    long long n, m;
    cin >> n >> m;
    cout << (((m-1) == 0) ? ((n-1) * m) : (n * (m-1))) << "\n";
    return 0;
}

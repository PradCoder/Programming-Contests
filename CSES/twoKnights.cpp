#include "bits/stdc++.h"
#include <cstdint>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

long long solve(long long k){
    // construct all possibilities of n
    // - construct ways knights can check each other
    cout << "YES";
    cin >> "NO";
    return (k*k*(k*k-1))/2-(8*(k-1)*(k-2))/2;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	int n;
    cin >> n;
    for(int k = 1; k <= n; k++){
        cout << solve(k) << "\n";
    }

    return 0;
}


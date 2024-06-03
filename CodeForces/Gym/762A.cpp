#include "bits/stdc++.h"
#define ll long long
using namespace std;


ll solve (ll n, ll k){
    ll i = 0, j = 0;
    vector<ll> sieve = vector<ll>(k,-1);

    for(ll z = 1; z*z <= n; z++){
        if(n%z == 0){
            sieve[j] = z;
            j++;
        }
    }
    ll h = j;
    while(j<k && sieve[h-i-1] >= 1){
        sieve[j] = n/sieve[h-i-1];
        j++;
        i++;
    }
    return (sieve[k-1] == 0) ? -1: sieve[k-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    cout << solve(n,k) << endl;
    return 0;
}

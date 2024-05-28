#include "bits/stdc++.h"
#include <cstdint>

using namespaces std;
typedef long long ll;
typedef long long ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int characterCost[n];
    for(int i = 0; i < n;i++){
        cin >> characterCost[i];
    }
    pi friends[m];
    for(int i = 0; i < m; i++){
        int friend1, friend2;
        cin >> friend1 >> friend2;
        friends[i] = make_pair(friend1,friend2);
    }
    return 0;
}

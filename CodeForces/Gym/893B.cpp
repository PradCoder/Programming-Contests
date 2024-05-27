#include "bits/stdc++.h"
#include <cstdint>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

const ll INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,ans,test=0;
    ans = 1;
    cin >> n;
    for(int k=1; test <= 1e5 ;k++){
        test = (((1<<k)-1)<<(k-1));
        if(n%test==0){
            ans = max(ans,test);
        }
    }
    cout << ans;
    return 0;
}

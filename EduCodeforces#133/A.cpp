#include "bits/stdc++.h"

using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int x;
        cin >> x;
        vector<int> dp(x+1,0);
        dp[0] = 0;
        dp[1] = 2;
        dp[2] = 1;
        dp[3] = 1;
        for(int i = 4; i <= x; i++){
            if(i%2 == 0){
                dp[i] = 1+dp[i-2];
            }
            if(i%3 == 0){
                dp[i] = 1+dp[i-3];
            }
            if(i%2 != 0 && i%3 != 0){
               dp[i] = 1+min({dp[i-2], dp[i-3]});
            }
        }
        cout << dp[x] << "\n";
    }
    return 0;
}

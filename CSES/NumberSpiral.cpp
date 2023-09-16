#include "bits/stdc++.h"

using namespace std;

//Approach O(1)
//Using a bijection from N x N -> N 
int main(){
    int n;
    cin >> n;
    unsigned long long ans = 0;
    for (int i = 0; i < n; i++){
        unsigned long long x, y;
        cin >> y >> x;
        if(x >= y){
            if(x%2 == 1){
               ans = x*x-(y-1); 
            }else{
               ans = (x-1)*(x-1)+y; 
            }
        }else{
            if(y%2 == 1){
                    ans = (y-1)*(y-1)+x; 
            }else{
                    ans = y*y-(x-1); 
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

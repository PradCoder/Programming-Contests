#include "bits/stdc++.h"

using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        cin >> x ;
        arr[x[0]-'a'] += 1;
        arr[x[1]-'a'] += 1;
        arr[y[0]-'a'] += 1;
        arr[y[1]-'a'] += 1;
        int onecount = 0;
        int twocount = 0;
        for (int i = 0; i < 26; i++){
            if(arr[i] == 1){
               onecount += 1; 
            }else if (arr[i] == 2){
               twocount += 1;
            }
        }
        cout << (min(onecount,3) + twocount/2) << "\n";
    }
    return 0;
}

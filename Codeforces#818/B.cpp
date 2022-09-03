#include "bits/stdc++.h"

using namespace std;

int main(){
    int t, n;
    string s1, s2;
    cin >> t;
    while(t--){
        cin >> n >> s1 >> s2;
        //G == B
        bool state = true;
        for(int i = 0; i < n ; i++){
            if(s1[i] == s2[i]){
               state = state && true;
            }else{
                if((s1[i] == 'G' || s1[i] == 'B') && (s2[i] == 'G' || s2[i] == 'B')){
                    state = state && true;
                }else{
                    state = state && false;
                    break;
                }
            }
        }
        cout << ((state) ? "YES" : "NO" ) << "\n";
    }
    return 0;
}

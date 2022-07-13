#include "bits/stdc++.h"
#include <string.h>

using namespace std;


int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> cm = vector<int> (n,0);
        for (int j = 0; j < n; j++){
            cin >> cm[j];
        }
        for (int j = 0; j < n; j++){
            int bi;
            cin >> bi;
            string s;
            cin >> s;
            for(int k = 0; k < bi; k++){
                if('D' == s[k]){
                    cm[j] = (10+cm[j]+1)%10;
                }else{
                    cm[j] = (10+cm[j]-1)%10;
                }
            }
        }
        for(int j = 0;j < n-1; j++){
            cout << cm[j] << " ";
        }
        cout << cm[n-1] << "\n";
    }
    return 0;
}

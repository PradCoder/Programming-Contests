#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> vi = vector<int> (n,0);

        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            vi[j] = a;
        }
        for(int i : vi){
            //cout << i << " ";
        }

        cout << endl;
        int r = 0, l = n-1;

        while( vi[r+1] != 0){
            r++;
        }
        while( vi[l-1] != 0){
            l--;
        }
        
        /*
        if(r == 0 && l == n-1){
            cout << "0\n";
        }else{
            cout << (l-r) << endl;
        }
        */
    }
    return 0;
}

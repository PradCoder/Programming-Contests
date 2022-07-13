#include "bits/stdc++.h"
#include <string.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<string> vm = vector<string> (n,0);
        for (int i = 0; i < n; i++){
            cin >> vm[i];    
        }
        string s = "";
        for(int h = 0; h < n; h++){
            bool sf = false; 
            for (int j = 0; j < n && !sf; j++){
                for (int k = 0; k < n && !sf; k++){
                    if(vm[h] == (vm[j]+vm[k])){
                        sf = true;
                    }
                }
            }
            if(sf){
                s+= "1";
            }else{
                s+= "0";
            }
        }
        cout << s << endl;
    }
    return 0;
}


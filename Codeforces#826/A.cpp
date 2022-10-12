#include "bits/stdc++.h"

using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        string a,b;
        cin >> a >> b;
        int na = a.length()-1;
        int nb = b.length()-1;
        if(a[na] > b[nb]){
            cout << "<\n"; 
        }else if (a[na] < b[nb]){
            cout << ">\n";
        }else{
            if(na == nb){
                cout << "=\n";
            }else if(a[na] == 'L'){
                cout << ((na < nb) ? "<": ">") << "\n";
            }else if(a[na] == 'S'){
                cout << ((na > nb) ? "<": ">") << "\n";
            }
        }
    }
    return 0;
}

#include "bits/stdc++.h"

using namespace std;

int main(){
    int tt, x, elem;
    cin >> tt;
    while(tt--){
        cin >> x;
        map <int, pair<int, bool>> dict;
        for (int i = 0; i < 3; i++){
            cin >> elem;
            dict.insert({i+1, pair<int,bool>(elem, false)});
        }
        int count = 0;
        for(int i = 0; i < 3; i++){
            dict[x].second = true;
            x = dict[x].first;
        }
        for(int i = 0; i < 3; i++){
            if(dict[i+1].second){
                count++;
            }
        }
        cout << ((count == 3) ? "YES" : "NO") << "\n";
    }
    return 0;
}

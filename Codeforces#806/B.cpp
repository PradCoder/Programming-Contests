#include "bits/stdc++.h"
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int slen;
        map<char,int> mp;
        string s;
        cin >> slen;
        cin >> s;
        int c = 0;
        for(int j = 0; j < slen; j++){
            if(mp[s[j]] == 0){
                mp[s[j]]++;
                ++c,c++;
            }else{
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}


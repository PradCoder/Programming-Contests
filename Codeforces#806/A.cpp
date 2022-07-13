#include "bits/stdc++.h"
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;
int main(){
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> s;
        transform(s.begin(),s.end(),s.begin(), ::tolower);
        if(s == "yes"){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

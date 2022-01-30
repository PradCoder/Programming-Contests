#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;
    string str;
    cin >> str;
    n = str.length();
    int count = 1;
    int m = 0;
    int i = 0;
    if(n > 1 && str[i] == str[i+1]){
        count = 2;
    }else{
        count = 1; 
    }
    m = count;
    for(i = 2; i < n; i++){
        if(str[i] == str[i-1]){
            count++;
        }else{
            m = max(m,count);
            count = 1;
        }
    }
    m = max(m,count); 
    cout << m;
    return 0;
}

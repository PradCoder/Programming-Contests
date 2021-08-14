#include "bits/stdc++.h"

using namespace std;

int main(){
    int i=0,j=0,fact[20000],k=0,l=1,n,temp=0;
    
    fact[0] = 1;
    cin >> n;
    for(i = 2; i <= n; i++){
        for(j = 0; j < l; j++){
            k = temp+i*fact[j];
            fact[j] = k%10;
            temp = k/10;
        }
        while(temp>0){
            fact[l] = temp%10;
            temp = temp/10;
            l++;
        }
    }
    string str = "";
    for(i=l-1;i>-1;i--)
        str += to_string(fact[i]);
    cout << str << "\n";
    return 0;
}
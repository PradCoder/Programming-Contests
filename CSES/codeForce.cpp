#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long int inp;
    cin>>inp;
    string  s = "";

    for(unsigned long long int i=1;i<=inp;i++){
        s += to_string(i); 
    }
    /*
    900000000000 * 9 = 1,000,000,000,000

    123456789101112131415
    inp%10
    
    */
    cout<<(s[inp-1])<<"\n";
    return 0;
}
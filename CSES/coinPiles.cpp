#include <iostream>
#include "bits/stdc++.h"
typedef unsigned int ui;
using namespace std;

bool solve(long a, long b){

    if(((a%3)+(b%3))%3 == 0){
	if(a - b > b || b - a > a){
		return false;
	}else{
		return true;
	} 
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ui t;
    long a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << (solve (a,b) ? "YES" : "NO") << "\n";
    }
    return 0;
}

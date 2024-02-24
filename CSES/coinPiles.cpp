#include <iostream>
#include "bits/stdc++.h"
typedef unsigned int ui;
using namespace std;

//Check the algorithms here out for a bit
bool solve(long a, long b){
   /* Actions: Remove 2 from L and 1 from R
    *          Remove 1 from L and 2 from R
    *
    * Directive: Find the most efficient way of Emptying both piles doing 1 and 2 
    *
    * */
    //simulation take 2 from max take 1 from min

    /*while(){

        a-=1;
        b-=2;
    }*/
    //Inefficient Recursion
    if((a > 0 || b > 0) && (a >= 0 && b >= 0)){
        return (solve(a-1,b-2) || solve(a-2,b-1));
    }else if (a == 0 && b == 0){
        return true;
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

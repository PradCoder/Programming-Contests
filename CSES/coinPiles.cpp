#include <iostream>

typedef unsigned int ui;
using namespace std;

//Check the algorithms here out for a bit
string solve(ui a, ui b){
   /* Actions: Remove 2 from L and 1 from R
    *          Remove 1 from L and 2 from R
    *
    * Directive: Find the most efficient way of doing this 
    *
    * */
    //simulation take 2 from max take 1 from min
    bool state = false;
    if((a+b) % 3 == 0){
        if((a%2 == 1 && b%2 == 0) || (a%2 == 0 && b%2 == 1)){
            state = true;
        }
    }
    return (state) ? "YES" : "NO" ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    unsigned int a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << solve (a,b) << "\n";
    }
    return 0;
}

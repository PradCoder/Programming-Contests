#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v = vector<int> v(n,0);
    while(n--){
        cin >> v[i];
    }
    bool ok = true; 
    for(int i = 0; i < v.size()-1; i++){
       if(v[i] < v[i+1]){
            ok = i;
            ok = i+1;
       }else{
            ok = false;
       }
    }
	return 0;	
}

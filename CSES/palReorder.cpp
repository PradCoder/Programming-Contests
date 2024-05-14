#include "bits/stdc++.h"

using namespace std;

int main(){
    map<char,int> m;

    string str;
    cin >> str;
    n = str.length();
    
    for(int i = 0; i < n; i++){
        m[str[i]] = 0;
    }

    for(int i = 0; i < n; i++){
        m[str[i]] += 1;
    }
    
    int count = 0;
    string n_str = "";

    if(n%2 == 1){
        for (const auto & [key, value] : m){
            if(value%2 == 1){
                count += 1;
            }
            if(count>1){
                cout << "NO SOLUTION";
                break;
            }
        }
        if (count == 1){
            //find character of value%2 = 1 and start adding to the end deleting half or half and 1 more
            //isolate the singular one and build symmetrically
           for(int i = 0; i < n; i++){
                if(m[str[i]] == 1){
                n_str += str[i];
                }else{
                   for(int i = 0; i < m[str[i]]/2; i++){
                        if(m[str[i]] > 1){
                            for(
                            n_str += str[i];
                        }
                   }
                }
           }
        }
    }else{
        for (const auto & [key, value] : m){
            if(value == 1){
                count += 1;
            }
            if(count==1){
                cout << "NO SOLUTION";
                break;
            }
        }
        if (count == 0){
    //find character of value%2 = 1 and start adding to end
        }
    }
    
    return 0;
}

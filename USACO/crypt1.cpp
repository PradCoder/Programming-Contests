/*
ID: 2010pes1
TASK: gift1
LANG: C++
*/
#include "bits/stdc++.h"
// This entire thing will take me an entire year if I plan on solving
// it solidly

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ofstream fout("crypt1.out");
    ifstream fin("crypt1.in");    

    int n;
    fin >> n;
    vector<int> vi = vector<int>(n,0);
    for (int i = 0; i < n; i++) {
        fin >> v[i];
        
        /*
          a b c 
         x  d e
         _______
           * * *
         * * *
         _______
         * * * *      
         * */
    }
    vector<set<int>> vec(n*n*n*n,{0,0,0,0,0});
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                for (int l = 0; l < n; l++){
                    for (int m = 0; m < n; m++){
                        vec[(i*n*n*n*n)+(j*n*n*n)+(k*n*n)+(l*n)+m] = {{v[i], v[j], v[k], v[l], v[m]}
                        v[i], v[j], v[k], v[l], v[m]}
                    }
                }
            }
        }
    }
    return 0;
}

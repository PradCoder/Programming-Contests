/*
ID: 2010pes1
TASK: crypt1
LANG: C++
*/
#include "bits/stdc++.h"
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ofstream fout("crypt1.out");
    ifstream fin("crypt1.in");

    int n;
    fin >> n;
    vector<int> v = vector<int>(n,0);
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }

    int count = 0;
    
    vector<vector<int>> vec(n*n*n*n*n,{0,0,0,0,0});
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                for (int l = 0; l < n; l++){
                    for (int m = 0; m < n; m++){
                        vector<int> temp = {v[i], v[j], v[k], v[l], v[m]};
                        vec[(i*n*n*n*n)+(j*n*n*n)+(k*n*n)+(l*n)+m] = temp;
                        string a, b, c, d, e;
                        a = to_string(v[i]);
                        b = to_string(v[j]);
                        c = to_string(v[k]);
                        d = to_string(v[l]);
                        e = to_string(v[m]);

                        for (int i = 0; i < temp.size(); i++){
                            cout << temp[i] << " ";
                        }
                        cout << "\n";
                    }
                }
            }
        }
    }
}

/*
ID: 2010pes1
TASK: combo
LANG: C++
*/
#include "bits/stdc++.h"

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ofstream fout("combo.out");
    ifstream fin("combo.in");
    
    int n;
    fin >> n;
    vector<int> v1 = vector<int>(3,0);
    vector<int> v2 = vector<int>(3,0);
    for (int i = 0; i < 3; i++){
        fin >> v1[i];
    }
    for (int i = 0; i < 3; i++){
        fin >> v2[i];
    }
    return 0;
}

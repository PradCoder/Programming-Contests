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
    
    vector<set<int>> vec(n*n*n*n*n,{0,0,0,0,0});

}

/*
ID: 2010pes1
TASK: milk2
LANG: C++
*/

#include "bits/stdc++.h"
#include <cstdio>

using namespace std;

int solve(int n, vector<string> v){
    return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    ifstream fin ("beads.in");
    ofstream fout ("beads.out");

    int n;
    fin >> n;
    vector<string> vb,va;
    vb = vector<string>(n,"");
    va = vector<string>(n,"");

    for(int i = 0; i < n; i++){
        fin >> vb[i]; 
    }

    for(int i = 0; i < n; i++){
        fin >> va[i];
    }
    return 0;
}

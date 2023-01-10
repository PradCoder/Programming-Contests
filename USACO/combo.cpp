/*
ID: 2010pes1
TASK: combo
LANG: C++
*/
#include "bits/stdc++.h"

using namespace std;

int testCombinations(vector<int>& inputs_1, vector<int>& inputs_2,int n){
    int a = 0;
    for (int i = 0; i < inputs_1.size(); i++) {
        for (int j = 0; j < n; j++)
         if(i+1 == inputs_1[i]){
            int a = (i+1)%n;
            if (a < 0) {a += n;}
         }else if (i+2 == 50){
            
         }
    }
    for (int i = 0; i < inputs_2.size(); i++) {
        if(i+
    
    }
    return a;
}

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
    testCombinations(inputs_1, inputs_2,N);
    return 0;
}

/*
ID: 2010pes1
TASK: combo
LANG: C++
*/
#include "bits/stdc++.h"

using namespace std;

int testCombinations(vector<int>& inputs_1, vector<int>& inputs_2,int n){
    int count = 0;
    int mult = 1;
    int n_a = inputs_1.size();
    for (int i = 0; i < n_a; i++) {
        for (int j = 1; j < n; j++){
            if(((j+1)%n == inputs_1[i] || (j+2)%n == inputs_1[i]) || 
                    ((j+1)%n == inputs_2[i] || (j+2)%n == inputs_2[i])){//Try something here yaaay!
                cout << "jth term: " << j << "Johns elem in check "<< inputs_1[i] << " ";
                cout << "Master elem in check " << inputs_2[i] << "\n";
                count += 1;
         }
        }
            mult *= count;
    }
    return mult;
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
    cout << testCombinations(v1, v2,n) << "\n";
    fout << testCombinations(v1, v2,n) << "\n";
    return 0;
}

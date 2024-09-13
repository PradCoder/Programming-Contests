/*
ID 2010pes1
TASK: skidesign
LANG: C++
*/
#include "bits/stdc++.h"
using namespace std;

int solve(vector<int>& hills){
    int n = hills.size();
    sort(hills.begin(), hills.end());  
    vector<pair<int,int>> greater_than_allowed;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if((hills[j]-hills[i])>17){
               greater_than_allowed.push_back(); 
            }
        }
    }
}

int main(void){
    ifstream fin ("skidesign.in");
    int N;
    fin >> N;
    int vector<int>(N,0);
    for(int i = 1; i <= N; i++){
        fin >> hills[i];
    }
    fin.close();
    ofstream fout ("skidesign.out");
    fout << solve(hills) << "\n";
    fout.close();
    return 0;
}

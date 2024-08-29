/*
ID 2010pes1
TASK: wormhole
LANG: C++
*/
#include "bits/stdc++.h"

//gotta figure out how to setup the checking mechanism
using namespace std;

int N;

bool test(int a, int b){
    if(abs(a-b)<=2 || abs(a-b)>=N-2){
        return true;
    }
    return false;
}

bool testComb(vector<int> v1, vector<int> v2){
    bool s = true;
    for (int i = 0; i < 3; i++){
        s = s && test(v1[i],v2[i]); 
    }
    return s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ofstream fout("combo.out");
    ifstream fin("combo.in");
    
    int ans = 0;
    fin >> N;
    vector<int> v1 = vector<int>(3,0);
    vector<int> v2 = vector<int>(3,0);
    for (int i = 0; i < 3; i++){
        fin >> v1[i];
    }
    for (int i = 0; i < 3; i++){
        fin >> v2[i];
    }
    fin.close();
    for (int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(testComb({i,j,k},v1) || testComb({i,j,k},v2)){
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    fout << ans << "\n";
    fout.close();
    return 0;
}

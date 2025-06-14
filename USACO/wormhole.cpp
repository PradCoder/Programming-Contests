/*
ID 2010pes1
TASK: wormhole
LANG: C++
*/
#include "bits/stdc++.h"
using namespace std;
#define MAX_N 12

int N, X[MAX_N+1], Y[MAX_N+1];
int partner[MAX_N+1];
int next_on_right[MAX_N+1];

//So everything is horizontally connected on a line
bool cycle_exists(void){
    for (int start = 1; start <= N; start++){
        int pos = start;
        for (int count = 0; count < N; count++){
            pos = next_on_right[partner[pos]];
        }
        if (pos != 0){
            return true;
        }
    }
    return false;
}

//count all solutions
int solve(void){
    int i, total = 0;
    for (i = 1; i <= N; i++){
        if(partner[i] == 0){
            break;
        }
    }
    if (i>N){
        if (cycle_exists()){
            return 1;
        }else{
            return 0;
        }
    }
    for(int j = i+1; j <= N; j++){
        if (partner[j] == 0){
            partner[j] = i;
            partner[i] = j;
            total += solve();
            partner[i] = partner[j] = 0;
        }
    }
    return total;
}

int main(void){
    ifstream fin ("wormhole.in");
    fin >> N;
    for(int i = 1; i <= N; i++) fin >> X[i] >> Y[i];
    fin.close();
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if (X[j] > X[i] && Y[i] == Y[j]){
                if (next_on_right[i] == 0 || 
                    X[j]-X[i] < X[next_on_right[i]]-X[i]){
                    next_on_right[i] = j;
                }
            }
        }
    }

    ofstream fout ("wormhole.out");
    fout << solve() << "\n";
    fout.close();
    return 0;
}
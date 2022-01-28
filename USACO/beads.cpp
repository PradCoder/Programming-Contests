/*
ID: 2010pes1
TASK: beads
LANG: C++
*/

#include "bits/stdc++.h"

using namespace std;
/*
Collect Beads of 2 colours from opposite ends
White beads can be colored anything.
*/

int solve1 (int n, string str){
    int count_w_r = 0;
    for(int i = 0; i < n; i++){
        int count_w_b = 0;
        for(int j = 0; j < i; j++){
            if(str[i] == 'w' || str[j] == 'b'){
               count_w_b++;
            }else if(str[i] == 'w' || str[j] == 'r'){
               count_w_r++;
            } 
        }
    }
    return val;    
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    ifstream fin ("beads.in");
    ofstream fout ("beads.out");
    int n;
    string str;

    fin >> n;
    fin >> str;
    fout << solve1(n,str) << "\n";
    return 0;
}

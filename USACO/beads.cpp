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
    int cal = 0;
    string nStr = str+str;
    for(int j = 0; j < n ; j++){
        //look at markers
        for(int i = 0; i < n; i++){
             if(nStr[i] == 'w' || nStr[i+1] == 'r'){
                                
             }else if(nStr[i] == 'w' || nStr[i+1] == 'b'){
             
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

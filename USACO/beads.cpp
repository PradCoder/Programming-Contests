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
    int val = 0;
    string nStr = str+str;
    for(int j = 0; j < n ; j++){
        //look at markers
        int cW = 0;
        int cR = 0;
        int cB = 0;
        bool encountB = false;
        bool encountR = false;
        for(int i = 0; i < n; i++){
             if(nStr[i] == 'w'){
                 cW++;
             }else if(nStr[i] == 'b'){
                 if(encountB && encountR){
                    break;
                 }
                 cB = cW;
                 cW = 0;
                 cB++;
                 encountB = true;
             }else if(nStr[i] == 'r'){
                 if(encountB && encountR){
                    break;
                 }
                 cR = cW;
                 cW = 0;
                 cR++;
                 encountR = true;
             }
        }
        val = cW + cB + cR;
        
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

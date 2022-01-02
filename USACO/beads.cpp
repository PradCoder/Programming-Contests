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

int mod (int v, int n){
    return (n + (v % n)) % n;
}

int solve(int n,string str){
    int countw, countb, countr;
    int mx1, mx2;
    string nstr = str+str;

    countw = 0;
    countb = 0;
    countr = 0;
    char c; 

    for(int i = 0; i < 2*n; i++){
        c = nstr[i];

        if(c == 'w'){
            countw++;
        }else if(c == 'r'){
            countr += countw;
            countw = 0;
            countr++;
            mx1 = max(countr+countb, countb+countr);
        }else if(c == 'b'){
            countb += countw;
            countw = 0;
            countb++;
        }
    }
    
    
    countw = 0;
    countb = 0;
    countr = 0;

    for(int i = 2*n-1; i >= 0; i--){
        c = nstr[i];

        if(c == 'w'){
            countw++;
        }else if(c == 'r'){
            countr += countw;
            countw = 0;
            countr++;
        }else if(c == 'b'){
            countb += countw;
            countw = 0;
            countb++;
        }
    }
    return 
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

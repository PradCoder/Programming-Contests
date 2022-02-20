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
29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
11
*/

int solve1 (int n, string str){
   int valr = 0;
   int cr = 0;
   int valb = 0;
   int cb = 0;
   int cw = 0;
   for(int i = 0; i < n;  i++){
       //longest consecutive chain b and r
       cr = 0;
       cb = 0;
       cw = 0;
       for(int j = i; j < n;j++){
            if(str[j] == 'b' || str[j] == 'w'){
                cb++;
            }else{
                break;
            }
       }
       for(int j = i; j < n;j++){
            if(str[j] == 'r' || str[j] == 'w'){
                cr++;
            }else{
                break;
            }
       }
        valr = max(valr,cr);
        valb = max(valb,cb);
   } 
   return valr;    
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

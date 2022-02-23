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

   char x = 'w';
   for(int i = 0; i < n;  i++){
       //longest consecutive chain b and r
       cr = cb = cw = 0;
       for(int j = i; j < i+n;j++){
            if(str[j] == 'b' && x == 'r' || str[j] == 'r' && x == 'b'){
                break;
            }else{
                x = str[j%n];
                cb++;
            }
       }
       for(int j = i-1; j >= i-n;j--){
            int ew = (j+n) % n
            if(str[j] == 'b' && x == 'r' || str[j] == 'r' && x == 'b'){
                break;
            }else{
                cr++;
            }
       }
       if(cr+cb > n){
            cr = cb-n;
       }
   }
   return max(valr,valb);    
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

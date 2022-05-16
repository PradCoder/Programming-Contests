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
   string beads = str;
   
   char x;
   int ans = 0;
   for(int a = 0, b, c, t1, t2; a < n;  a++){
       t1 = t2 = 0;
       
       for(b = a, x = 'w'; b < n + a; b++, t1++){
            if((beads[b%n] == 'r' && x == 'b') || (beads[b%n] == 'b' && x == 'r')){
                break;
            }else if (x == 'w'){
                x = beads[b%n];
            }
       }
       
       for(c = a-1, x = 'w'; c > a - 1 - n; c--, t2++){
            if((beads[(c+n)%n] == 'r' && x == 'b') || (beads[(c+n)%n] == 'b' && x == 'r')){
                break;
            }else if (x == 'w'){
                x = beads[(c+n)%n];
            }
       }
       //double count correction
       if(t1+t2 > n){
            t1 = n-t2;
       }
       //cout << cr << " "<< cb << "\n"; 
       ans = max(ans, t1+t2);
   }
   return ans;
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

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
   int cr,cb, ans = 0;
   char x;
   for(int i = 0; i < n;  i++){
       cr = cb = 0;
       x = 'w';
       for(int j = i; j < i+n; j++,cr++){
            if((str[j%n] == 'b' && x == 'r') || (str[j%n] == 'r' && x == 'b')){
                break;
            }else if (x == 'w'){
                x = str[j%n];
            }
       }
       
       x = 'w';
       for(int j = i-1; j >= i-n;j--,cb++){
            int ew = (j+n) % n;
            if((str[ew] == 'b' && x == 'r') || (str[ew] == 'r' && x == 'b')){
                break;
            }else if (x == 'w'){
                x = str[ew];
            }
       }
       //double count correction
       if(cr+cb > n){
            cr = n-cb;
       }
       cout << cr << " "<< cb << "\n"; 
       ans = max(ans, cr+cb);
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

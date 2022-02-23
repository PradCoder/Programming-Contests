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
   //Try every breaking spot
   char x;
   int ans = 0;
   for(int a = 0, b, c, t1, t2; a < n; a++){
       t1 = t2 = 0;//bead counter

       //Right side.
       for (b = a, x = 'w'; b < n + a; b++, t1++){
            if((beads[b%n] == 'r' && x == 'b') || (beads[b%n] == 'b' && x == 'r')){
                //Use mods to 'loop' around
                break;
            }else if (x == 'w'){
                x = beads[b%n];
            }
       }

       //Left side.
       for (c = a-1, x = 'w'; c > a - 1 - n; c--, t2++){
            if((beads[(c+n) % n] == 'r' && x == 'b') || (beads[(c+n)%n] == 'b' && x == 'r')){
                break;
            }else if(x == 'w'){
                x = beads[(c+n)%n];
            }
       }

       //Did we double count beads?
       if(t1+t2 > n){
            t1 = n -t2; //If so, that means we can reach all the beads.
       }

       ans = max(t1+t2, ans);

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

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

int solve (int n,string str){

    int countw, countb, countr;
    int mx1 = 0, mx2 = 0;
    string nstr = str+str;

    countw = 0;
    countb = 0;
    countr = 0;

    int counts = 0;
    char c,cn; 
    
    // wwwbbrwrbrbrrbrbrwrwwrbwrwrrb | wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
    // take and travel along w
    // add w to b travel after b, 
    // switch to r travel after r, travel after w
    // travel after r, hit b calculate max b-r string save to variable
    // take b, travel to next terminal r
    //
    // In general take starting term then travel to terminal term, compare distance
    // with current and previous
    
    for(int i = 0; i < 2*n-1; i++){
        c = nstr[i];
        cn = nstr[i+1];
        
        if(c == 'w'){
            countw++;
        }else if(c == 'r'){
            countr += countw;
            countw = 0;
            counts++;
            countr++;
            mx1 = max(countr+countb, mx1);
        }else if(c == 'b'){
            countb += countw;
            countw = 0;
            counts++;
            countb++;
            mx2 = max(countr+countb, mx2);
        }

        if(c != cn){
            if(c == 'r'){
                if(cn == 'b'){
                    mx1 = max(countr;
                }else if(cn == 'r'){
                    countr++;
                    mx1 = (countr+countw+countb,mx2);
                }else{
                    countw++;
                }
            }
            if(c == 'b'){
                if(cn == 'b'){
                    countb++;
                    mx2 = (countr+countw+countb,mx1);
                }else if(cn == 'r'){
                    countr++;
                }else{
                    countw++;
                }
            
            }
            if(c == 'w'){
            
            }    
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

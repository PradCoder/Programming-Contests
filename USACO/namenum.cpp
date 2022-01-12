/*
ID: 2010pes1
TASK: namenum
LANG: C++
*/

#include "bits/stdc++.h"

using namespace std;

int main(){
    string myline = "";
    fstream myfile;

    myfile.open("dict.txt", ios::in);
    if(myfile.is_open()){
       string tp;
       while(getline(myfile, tp)){
           myline += tp + "\n";
       }
       myfile.close(); //close the file object
    }
    
    map<int,string> m;
    m[2] = "ABC";
    m[3] = "DEF";
    m[4] = "GHI";
    m[5] = "JKL";
    m[6] = "MNO";
    m[7] = "PRS";
    m[8] = "TUV";
    m[9] = "WXY";

    /*
          2: A,B,C     5: J,K,L    8: T,U,V
          3: D,E,F     6: M,N,O    9: W,X,Y
          4: G,H,I     7: P,R,S
    */

    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    string s;
    scanf("%s",&s);
    int n = s.length();
    for(int i = 0; i<n;i++){
        if(m[atoi(s[i])]){
        
        }
    }
    return 0;
}

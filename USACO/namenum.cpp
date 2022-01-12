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
    
    cout << myline;
   // freopen("namenum.in", "r", stdin);
   // freopen("namenum.out", "w", stdout);
    return 0;
}

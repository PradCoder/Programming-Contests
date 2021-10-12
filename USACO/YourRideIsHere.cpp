/*
ID: 2010pes1
TASK: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include "bits/stdc++.h"

using namespace std;

int main(){
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string str1, str2;
    fin >> str1;
    fin >> str2;
    int n1 =  str1.length();
    int n2 =  str2.length();
    int sum1 = 1; 
    int sum2 = 1; 
    for(int i = 0; i < n1;i++){
        sum1 = (sum1 * (str1[i]-'A'+1)) % 47;
        cout << (str1[i]-'A'+1) << "\n";
    }
    for(int i = 0; i < n2;i++){
        sum2 = (sum2 * ((str2[i]-'A')+1)) % 47;
        cout << (str2[i]-'A'+1) << "\n";
    }
    sum1 = sum1 % 47;
    sum2 = sum2 % 47;
    if(sum1 == sum2){
        fout << "GO" << "\n"; 
    }else{
        fout << "STAY" << "\n";
    }
}

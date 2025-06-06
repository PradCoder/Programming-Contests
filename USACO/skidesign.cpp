/*
ID 2010pes1
TASK: skidesign
LANG: C++
*/
#include "bits/stdc++.h"
using namespace std;

int n,hills[1000];

/* We are doing a complete search on all allowable elevations of
    the form (i,i+17) and cecking the difference
    (0,17)
    (1,18)
    (2,19)
    (3,20)
    (4,21)
    (5,22)
*/
int main(void){
    ifstream fin ("skidesign.in");
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> hills[i];
    }
    fin.close();

    int mincost = 1000000000;
    for (int i = 0; i <= 83; i++){
        int cost = 0, x;
        for (int j = 0; j < n; j++){
            if (hills[j] < i){
                x = i - hills[j];
            }else if (hills[j] > i+17){
                x = hills[j]-(i+17);
            }else{
                x = 0;
            }
            cost+=x*x;
        }
        mincost = min(mincost, cost);
    }
    ofstream fout("skidesign.out");
    fout << mincost << "\n";
    fout.close();
    return 0;
}

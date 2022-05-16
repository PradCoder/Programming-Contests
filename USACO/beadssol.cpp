/*
ID: 2010pes1
TASK: beads
LANG: C++
*/

#include "bits/stdc++.h"

using namespace std;

int n;
char s[355];

int md(int j){
    while(j<0) j+=n;
    return j%n;
}

int bp(int pos, int dir){
}

int main(){
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int ma=0;
    scanf("%d", &n);
    scanf("%s", s);
    for(int i=0; i<n; i++){
        ma=max(bp(i,-1)+bp(i,1),ma);
    }
    if(ma>n){
        ma = n;
    }
    printf("%d\n", ma);
    return 0;
}

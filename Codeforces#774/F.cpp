#include "bits/stdc++.h"
#define fore(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

const int MAXN = 1010;

//c[i][j] = number of cards player i has. with the number j
int c[MAXN][MAXN];

//extras[i] is the stack of repeated cards for player i
vector<int> extras [MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    fore(i,0,n){
        fore(j,0,n){
            int x; cin >> x; x--;
            c[i][x]++;
            if(c[i][x] > 1) extras.push_back(x);
        }
    }
    vector<vector<int> res;
    //First part
    return 0;
}

/*
P. Amarasekera
YYYY/MM/DD
2021/04/01 - ?



*/
#include "bits/stdc++.h"
#include <cstdint>

#define F                   first
#define S                   second
#define PG                  push_back
#define PPB                 pop_back
#define PF                  push_front
#define MP                  make_pair
#define REP0(i,a,b)         for (int i = a; i < b; i++)
#define REP1(i,a,b)         for (int i = a; i <= b; i++)

#define PPC                 __builtin_popcount
#define PPCLL               __builtin_popcountll

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

const ll INF = 1e18;
const int32_t M = 1e9+7;
const int32_t MM=998244353;
const int IINF = 1e9;



string solve(string s, string t){
    vector<string> dp = vector<string>();
    for(int i = 0; i< s.length(); i++){
        for(int j = 0; j < t.length(); j++){
            if(c == l){
                
            }
        }
    }
    /* a  x    y     b
    a  a {ax} {axy} {axyb}
    b  
    x
    y
    b
    */
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s,t;
	cin >> s >> t;
    
    printf("%s\n",solve(s,t));

    return 0;
}
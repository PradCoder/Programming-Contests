/*
ID: 2010pes1
TASK: gift1
LANG: C++
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


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");

    int n;
    fin >> n;
    unordered_map<string,int> m;
    vector<string> v;
    for(int i = 0;i<n;i++){
        string temp;
        fin >> temp;
        v.push_back(temp);
        m[temp] = 0;
    }
    for(int i = 0;i<n;i++){
        string name;
        fin >> name;
        int amt, ppl;
        amt = 0;
        ppl = 0;
        fin >> amt >> ppl;
        if(ppl != 0){
            int dist = (int) (amt / ppl);
            int rem = amt % ppl;
            m[name] += -amt + rem;
            for(int j = 0; j < ppl; j++){
               fin >> name;
               m[name] += dist;
            }
        }
    }
    for(auto str : v){
        fout << str << " " << m[str] << "\n";

    }
    return 0;
}


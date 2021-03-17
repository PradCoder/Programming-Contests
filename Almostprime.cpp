#include "bits/stdc++.h"
#include <cstdint>
#include <cstdio>

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

vi sieve;

int solve(int n){
    sieve = vi(n+1,0);
    for(int i = 2; i <=n; i++){
        if(sieve[i] == 0){
        for(int j = 2*i; j<=n; j+=i){
           sieve[j] += 1; 
        }
      }
    }
    int count = 0;
    REP1(i,0,n){
        if(sieve[i] == 2){
            count++;
        } 
    }
    return count;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    cin >> n;
    printf("%d\n",solve(n));
}



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

template<typename T>
void Print(T value){
	cout << value <<"\n";
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	Print<int>(5);
    int term = 1;
    int old = 0;
    long sum = 0;
    while(term < 4000000){
        if (term % 2 == 0){
            sum += term;
        }
        int temp = old;
        old = term;
        term = temp + term;
    }
    Print(sum);
}


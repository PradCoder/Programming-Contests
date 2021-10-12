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

// const ll INF = 1e18;
// const int32_t M = 1e9+7;
// const int32_t MM=998244353;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
    vi solutions = vi(10001,0);
    cin >> n;
    int i = 0;
    int it = 1;
    // cout << to_string(0).find("0") << "\n";
	while(i<10001){
        int len = to_string(it).length();
        if((((to_string(it).find("3") == string::npos) || (to_string(it).find("3") < len-1)) || (it%3 > 0))
            && (((to_string(it).find("3") == string::npos) || (to_string(it).find("3") < len-1)) && (it%3 != 0))
            ){
            solutions[i] = it;
            i++;
        }
        it++;
       //cout << i << "\n";
    }

    for(int j = 0;j<n;j++){
        int pos;
        cin >> pos;
        cout << solutions[pos-1] << "\n";
    }
    // for(int a = 0; a < 10001; a++){
    //     if(solutions[a] == 1666){
    //         cout << "True"<< a <<"\n";
    //     }
    // }
    return 0;
}


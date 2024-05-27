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

	int n;
	cin >> n;
    int victors[n];

    for(int i = 0; i < n; i++){
        cin >> victors[i];
    }

    int spectator = 3;
    int player1,player2;
    player1 = 1;
    player2 = 2;
    bool fair = true;
    for(int i =0; i < n; i++){
        if(spectator == victors[i]){
            fair = false;
            break;
        }else{
            switch (victors[i]){
                case 1:
                    if(spectator == 3){
                        spectator = 2;
                        player1 = 1;
                        player2 = 3;
                    }else{
                        spectator = 3;
                        player1 = 1;
                        player2 = 2;
                    }
                    break;
                case 2:
                    if(spectator == 1){
                        spectator = 3;
                        player1 = 1;
                        player2 = 2;
                    }else{
                        spectator = 1;
                        player1 = 2;
                        player2 = 3;
                    }
                    break;
                case 3:
                    if(spectator == 1){
                        spectator = 2;
                        player1 = 1;
                        player2 = 3;
                    }else{
                        spectator = 1;
                        player1 = 2;
                        player2 = 3;
                    }
                    break;
                default:
                    cout << "Error";
                    break;
            }
    }
    }
    cout << ((fair) ? "YES" : "NO");
}


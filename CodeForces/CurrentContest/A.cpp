/**
 * A. Cutting Figure 193/A
*/

#include "bits/stdc++.h"

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
typedef vector<short> vs;

int gcd(int a,int b){
    if (b==0){
        return a;
    }
    return gcd(b,a%b);
}

int solve(int l, int r){
    int count = 0;
    while(l+2<=r){
        int k = l+2;
        if(k <= r && (l%2 == 0) && ((l+1)%2 == 1)){
            while(gcd(k,l) != 1 && k <= r){
                k++;
            }
        }else if(k <= r && (l%2==1) && ((l+1)%2 == 0)){
            while(gcd(k,l) != 1 && k <= r){
                k++;
            }
        }
        if(gcd(k,l) && k<=r)
            count++;
        l = k+1;
        while(l%2 == 0 && l%3 == 0){
            l++;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        cout << solve(l,r) << "\n";
    }
    return 0;
}

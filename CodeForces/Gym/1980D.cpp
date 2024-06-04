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

int gcd(int c, int d){
    int a = max(c,d);
    int b = min(c,d);
    while(a>b){
        a = a-b;
        int temp0 = b;
        int temp1 = a;
        a = max(temp1,temp0);
        b = min(temp1,temp0);
    }
    return a;
}
string solve(int n,vi& a){
    int prev = gcd(a[0],a[1]);
    int indCount = 0;
    bool state = false;
    int consCount = 0;
    for(int i = 1; i < n-1;i++){
        int current = gcd(a[i],a[i+1]);
        if((prev>current) || (state && prev == current)){
            if(state == false){
                indCount++;
            }
            state = true;
            consCount++;
        }else if(prev < current){
            state = false;
            consCount = 0;
        }
        prev = current;
        if(indCount > 2 || consCount>2){
            return "NO";
        }
    }
    
    return "YES";
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vi a = vi(n,0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << solve(n,a) << endl;
    }
    
    return 0;
}
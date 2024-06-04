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

string solve(int n,int f,int k, vi& a){
    int fav = a[f-1];
    vi removed = vi(k,0);
    int countFav = 0;
    for(int i = 0; i < n; i++){
        if(fav == a[i]){
            countFav++;
        }
    }
    int initialFav = countFav;
    sort(a.begin(),a.end(),greater<int>());
    for(int i = 0; i < k;i++){
        removed[i] = a[i];
        if(removed[i] == fav){
            countFav--;
        }
    }

    if(countFav == 0){
        return "YES";
    }else if (countFav == initialFav){
        return "NO";
    }

    return "MAYBE";
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n,f,k;
        cin >> n >> f >> k;
        vi a = vi(n,0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << solve(n,f,k,a) << endl;
    }
    
    return 0;
}
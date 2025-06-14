#include "bits/stdc++.h"

/**
 * Problem C. Sofia and the Lost Operations
*****
All operations must be applied to the array in the given order. 
More than one operation can be applied to a single position.
*/

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

bool check(int n, int m, vi& b, vi& d){
    REP0(i,0,n)
        if(b[i] == d[m-1])
            return true;
    return false;
}

string solve(int n,int m, vi& a, vi& b, vi& d){
    int k = 0;
    vi buff = vi(n,0);
    for(int i = 0; i < n; i++){
        if(a[i] != b[i])
            buff[k++] = b[i];
    }
    sort(buff.begin(),buff.begin()+k);
    if(!check(n,m,b,d)) return "NO";
    sort(d.begin(),d.end());
    int ib = 0, id = 0;
    while (ib < k && id < m){
        if(buff[ib] == d[id]){
            ib++, id++;
        }else if( buff[ib] < d[id]){
            return "NO";
        }else{
            id++;
        }
    }
    return (ib == k) ? "YES" : "NO";
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n,m;
        cin >> n ;
        vi a = vi(n,0);
        vi b = vi(n,0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        cin >> m;
        vi d = vi(m,0);
        for (int i = 0; i < m; i++){
            cin >> d[i];
        }
        
        cout << solve(n,m,a,b,d) << endl;
    }
    
    return 0;
}

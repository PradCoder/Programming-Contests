#include <bits/stdc++.h>

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
typedef vector<short> vs;

bool compareTuple(tuple<int,int,int> a, tuple<int,int,int> b){
    if(get<0>(a) != get<0>(b)){
        return get<0>(a) < get<0>(b);
    }
    return get<1>(a) < get<1>(b);
}
bool check(vector<vs>&a, vector<vs>&b){
    for (int i = 0; i < a.size();i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] != b[i][j]){
                return false;
            }
        }
    }
    return true;
}

string solve(int n, int m, vector<vs> st, vector<vs> ed){
    queue<tuple<pi,pi,vector<vs>>> q;
    set<vector<vs>> visited;
    q.push({{0,0},{n,m},st});
    while (!q.empty()){
        vector<vs> cur; 
        pi p1,p2;
        tie(p1,p2,cur) = q.front();
        set<vector<vs>> a;
        if(check(cur,ed)){
            return "YES";
        }else{
            a = {p1.F+1,p1.S}
            if(p1.F+1 < n){
                
            }

        }
        q.pop()
    }
    return "NO"
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vector<short>> a(n,vector<short>(m,0)),b(n,vector<short>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j]; 
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> b[i][j]; 
            }
        }
        cout << solve(n,m,a,b) << "\n";
    }
    return 0;
}

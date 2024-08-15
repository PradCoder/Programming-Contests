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
typedef vector<vi> vvi;
typedef vector<pi> vpi;

//If I swap the rows or columns of one number
//other numbers in that same row or column in that number
//should swap rows (if rows are swapped rows of the other numbers swapped,
//respectively for columns)
string solve(int n, int m, vpi a,vpi b){
    vi x(n,-1), y(m,-1);
    int dim = n*m;
    for(int i = 0; i < dim;i++){
        if(x[a[i].F] == -1){
            x[a[i].F] = b[i].F;
        }else if (x[a[i].F] != b[i].F){
            return "NO";
        }
        if(y[a[i].S] == -1){
            y[a[i].S] = b[i].S;
        }else if (y[a[i].S] != b[i].S){
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
        int n,m;
        string s;
        
        cin >> n >> m;
        vector<pi> a(n*m);
        vector<pi> b(n*m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m;j++){
                int ai;
                cin >> ai;
                a[ai-1] = {i,j};
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m;j++){
                int bi;
                cin >> bi;
                b[bi-1] = {i,j};
            }
        }
        cout << solve(n,m,a,b) << "\n";
    }
    
    return 0;
}


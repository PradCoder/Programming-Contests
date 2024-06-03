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

vector<int> solve(int n,int m,vi& programmingSkill,vi& testingSkill){
    int bad = -1, badType = -1, ans = 0;
    vi bounds{n,m};
    int cur[2] = {0,0};
    vector<vi> a;
    a.push_back(programmingSkill);
    a.push_back(testingSkill);
    vi types =  vi(n+m+1,0);
    for(int i = 0; i < n+m+1; i++){
        int curType = 0;
        if(a[0][i] < a[i][i]){
            curType = 1;
        }
        if(cur[curType] == bounds[curType]){
            curType = 1 - curType;
            if(bad == -1){
                bad = i;
                badType = 1 - curType;
            }
        }
        types[i] = curType;
        ans += a[types[i]][i];
        cur[types[i]] += 1;
    }

    vi res = vi();
    for(int i = 0; i < n+m; i++){
        int val = ans - a[types[i]][i];
        if((bad != -1) && (i < bad) && (types[i] == badType)){
            val = val + a[badType][bad] - a[1 - badType][bad] + a[1 - badType][n+m]; 
        }else{
            val = val + a[types[i]][n+m];    
        }
        res.push_back(val);
    }
    res.push_back(ans);
        
    return res;
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	int t;
	cin >> t;
    
    while(t--){
        int m,n;
        cin >> n >> m;
        cout << n << " " << m << endl;
        vi programmingSkill = vi(n+m+1,0);
        vi testingSkill = vi(n+m+1,0);
        for(int i = 0; i < n+m+1; i++){
            cin >> programmingSkill[i];
        }
        for(int i = 0; i < n+m+1; i++){
            cin >> testingSkill[i];
        } 
        vector<int> arr = solve(n,m,programmingSkill,testingSkill);
        for(int i = 0; i < n+m+1; i++){
            cout << arr[i] << ((i== n+m) ? "\n" : " ");
        }
    }
    
    return 0;
}


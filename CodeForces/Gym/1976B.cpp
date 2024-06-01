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
#define INF 1e9

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

long long solve(int n, vector<int>& a, vector<int>& b){
    long long ans = 0;
    //always calculate the diff
    for(int i=0; i< n;i++){
        ans+=abs(a[i]-b[i]);
    }
    bool inMiddle = false;
    int i = 0;
    vector<int> v;
    int minDIF = INF;
    //for the special case where localMin <= b[n] <= localMax
    while(!inMiddle && i < n){
        int localMax = max(a[i],b[i]);
        int localMin = min(a[i],b[i]);
        if(localMin <= b[n] && b[n] <= localMax){
            ans++;
            inMiddle = true;
            return ans;
        }
        i++;
    }
    for(int i = 0; i < n ; i++)
        minDIF = min(min(abs(b[n]-b[i]),abs(b[n]-a[i])),minDIF);
    return ans+minDIF+1;
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
        vector<int> vec1 = vector<int>(n,0);
        vector<int> vec2 = vector<int>(n+1,0);
        for(int i = 0; i < n; i++){
            cin >> vec1[i];
        }
        for(int i = 0; i < n+1; i++){
            cin >> vec2[i];
        }
        cout << solve(n, vec1, vec2) << endl;
    }
    
    return 0;
}
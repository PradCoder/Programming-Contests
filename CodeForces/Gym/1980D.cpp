#include "bits/stdc++.h"
#include <algorithm>
#include <iostream>
#include <numeric>

#define F                   first
#define S                   second
#define PG                  push_back
#define PPB                 pop_back
#define PF                  push_front
#define MP                  make_pair
#define REP0(i,a,b)          for (int i = a; i < b; i++)
#define REP1(i,a,b)         for (int i = a; i <= b; i++)

#define PPC                 __builtin_popcount
#define PPCLL               __builtin_popcountll

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

bool generateTest(int idx,int n, vi& a){
    vi ans = vi();
    for(int i = 0; i < n;i++){
        if(i != idx)
            ans.push_back(a[i]);
    }
    int prev = gcd(ans[0],ans[1]);
    for(int i = 1; i < n-2;i++){
        int current = gcd(ans[i],ans[i+1]);
        if(prev>current){
            return false;
        }
        prev = current;
    }
    return true;
}

string solve(int n,vi& a){
    int prev = gcd(a[0],a[1]);
    int idx = 0;
    for(int i = 1; i < n-1;i++){
        int current = gcd(a[i],a[i+1]);
        if(prev>current){
            idx = i;
            break;
        }
        prev = current;
    }
    if(idx == n-2){
        return "YES";
    }else{
        bool extra = generateTest(idx, n,a);
        if(extra) return "YES";
        bool extra_down = generateTest(idx-1, n,a);
        if(extra_down) return "YES";
        bool extra_up = generateTest(idx+1, n,a);
        if(extra_up) return "YES";
    }
    return "NO";
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
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

int bs(vector<int> v, int t){
    int mid = floor((v.size()-1)/2);
    int low = 0;
    int hi = v.size()-1;
    while(low<=hi){
        if(v[mid] == t){
            return mid;
        }else if(v[mid] < t){
            low = mid+1;
        }else{
            hi = mid-1;
        }
        mid = floor((low+hi)/2);
    }
    return -1;
}

int main() {
    int n,t;
    cin >> n;
    vector<int> v = vector<int> (n,0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> t;
    sort(v.begin(),v.end());
    cout << bs(v,t) <<endl;
    return 0;
}

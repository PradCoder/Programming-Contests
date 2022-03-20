#include "bits/stdc++.h"
using namespace std;


#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i,n) for (int i=0; i<(n);i++)
#define repl(i,n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;


/* 
 * From Tutorial:
 * If the i-th persion is not ill the following query exists: 0 l r 0, such that l <= i <= r.
 * 
 * Otherwise, the person's status is either unkown or they are ill.
 *
 * If i-th person is ill, the following query exists: 0 l r 1, such that l <= i <= r, and 
 * every person i such that l <= j <= r are not ill. If there is such person j that they
 * are not ill, and j != i, l <= j <= r. In this case, it is impossible to determine if i-th
 * person is ill or not.
 *
 * Let's maintain the indices of the people who might be ill using set. When we get a query
 * 0 l r 0, we can find the first possible ill person with an index of at least l using
 * lower_bound, after that, we need to delete this person from our set, find the next one
 * and do the same thing until we find the first index greater than r. This works in O(nlogn).
 *
 * If a person is not in the set, he is totally healthy. Otherwise, we can use a segment tree 
 * to store such index j that there is a query 0 i j 1 and store it in the i-th slot of our se
 * -gment tree. We can update it when we get a new query. When we understand that the i-th pers
 * -on might be ill, we can find the first elements to the left (l) and to the right (r) of i,
 * which might be ill using our set. The i-th person is ill when the minimal element on segment
 * [l+1; i] is < r.
 *
 * The solution is O(nlogn + qlogn).
 * */
int32_t main(){
    fastio;
    int n,q; cin >> n >> q;
    set<int> active;
    rep(i, n+1) active.insert(i);
    vi m(n, INT_MAX);
    vi ans(n, -1);
    while(q--){
        int t; cin>> t;
        if(t==0){
            int l,r,x; cin >> l >> r >> x; --l, --r;
            if(x == 1){
                int v = *active.lower_bound(l);
                m[v] = min(m[v], r);
                if (m[v] < *active.upper_bound(v)) ans[v] = 1;
            }
            else{
                int nxt = *active.upper_bound(r);
                for(auto itr = active.lower_bound(l); *itr <= r;){
                    if(nxt != n) m[nxt] = min(m[nxt], m[*itr]);
                    ans[*itr] = 0;
                    active.erase(itr);
                    itr = active.lower_bound(l);
                }
                if(nxt != n && m[nxt] < *active.upper_bound(nxt)) ans[nxt] = 1;
                if(*active.begin() < l){
                    int prv = *prev(active.lower_bound(l));
                    if(m[prv] < *active.upper_bound(prv)) ans[prv] = 1;
                }
            
            }
        }
        else {
            int p; cin >> p; --p;
            if(ans[p] == -1) cout << "N/A\n";
            else if(ans[p] == 0) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}

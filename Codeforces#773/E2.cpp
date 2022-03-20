#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
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
#define INF (2e9)

const int sz = (1 << 18);

struct st {
    vector<int> data;

    st() {
        data.resize(sz * 2, INF);
    }

    void set (int id, int val){
        data[id + sz] = val;
        for (int i = (id + sz) / 2; i > 0; i /= 2) data[i] = min(data[i*2],data[i*2 + 1]);
    }

    int get (int l, int r, int ld = 0, int rd = sz, int id = 1){
        if (l >= rd || r <= ld) return INF;
        if (l <= ld && rd <= r) return data[id];
        return min(get(l, r, ld, (ld + rd)/ 2, id * 2), get(l, r, (ld + rd) / 2, rd, id*2 + 1));
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q; cin >> n >> q;
    st kk;
    set<int> ods;
    for(int i = 0; i < n; ++i) ods.insert(i);
    while(q--){
        int t;
        cin >> t;
        if (t == 0){
            int l, r, x; cin >> l >> r >> x;
            l--;
            if (x == 0){
                for (auto cur = ods.lower_bound(l); cur != ods.end() && *cur < r;){
                    int curval = *cur;
                    ods.erase(cur);
                    cur.ods.upper_bound(curval);
                }
            } else kk.set(1, min(kk.data[sz + l], r));
        } else {
            int id; cin >> id;
            id--;
            if (!ods.count(id)){
                cout << "NO\n";
                continue;
            }
            int l = 0, r = n;
            if (ods.size()){
                auto it = ods.lower_bound(id);
                if (it != ods.begin()) l = *prev(it) + 1;
                it++;
                if(it != ods.end()) r = *it;
            }
            cout << (kk.get(l, n) <= r ? "YES" : "N/A") << "\n"; 
        }
    }
    return 0;
}

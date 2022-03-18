#define _USE_MATH_DEFINES

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
 * Proving that we can turn the array into a concatenation of tandem
 * repeats using the operations given if and only if every letter occurs
 * an even number of times.
 *
 *
 * If there is such letter x that it occurs an odd number of times there
 * is no such sequence of operations, since the parity of occurences if letter x
 * stays the same. If we insert a different letter, the number of occurrences of
 * letter x does not change, if we insert letter x, we add 2 occurrences of it. Thus,
 * it will be impossible to split the array into tandem repeats.
 *
 * If we have an array s1s2..sn, and we want to reverse its prefix of length k<= n
 * we can insert a pair of letters equal to s1 after the kth symbol, a pair of letters
 * equal to s1 after the kth symbol, a pair of letters equal to s2 after (K+1)-th symbol
 * and etc.
 *
 * S1 S2... Sk Sk+1... Sn
 * S1 S2... Sk S1 S1 Sk+1... Sn
 * S1 S2... Sk S1 S2 S2 S1 Sk+1... Sn
 * ...
 * S1 S2... Sk S1 S2... Sk Sk ... S2 S1 Sk+1 ... Sn
 *
 *
 * */

void reverse_pref(vector<int> &ar, vector<pair<int, int>> &ans,
                  vector<int> &lens, int &mdf, int len){
    for (int i = 0; i < len; ++i){
        ans.emplace_back(len + mdf + i, ar[i]);
    }
    if (len != 0){
        lens.push_back(len*2);
    }
    mdf += len * 2;
    reverse(ar.begin(), ar.begin() + len);
}

void move_to_front(vector<int> &ar, vector<pair<int, int>> &ans,
                   vector<int> &lens, int &mdf, int id){
    reverse_pref(ar, ans, lens ,mdf, id);
    reverse_pref(ar, ans, lens, mdf, id+1);
}

signed solve(int n, vector<int> ar){
    int xr = 0;
    unordered_map<int, int> cnt;
    for (auto &it : ar){
        cnt[it]++;
    }
    for (auto &it : cnt){
        if (it.second % 2){
            cout << "-1\n";
            return 0;
        }
    }
    vector<int> br = ar;
    sort(br.rbegin(), br.rend());
    vector<pair<int,int>> ans;
    vector<int> lens;
    ans.reserve(n * n * 2);
    lens.reserve(n * 2);
    int mdf = 0;
    for (int i = 0; i < n; ++i){
        int fnd = (int) (find(ar.begin() + i, ar.end(), br[i]) - ar.begin());
        move_to_front(ar, ans, lens, mdf, fnd);
    }
    for (int i = 0; i < n; ++i){
        int lst = i;
        for (; lst < n && ar[lst] == ar[i]; ++lst){
        }
        lens.push_back(lst - i);
        i = lst - 1;
    }
    cout << (int)ans.size() << "\n";
    for (auto &it : ans){
        cout << it.first << " " << it.second << "\n";
    }
    cout << (int) lens.size() << "\n";
    for(auto &it : lens){
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> aux(n);
        for(auto& it : aux){
            cin >> it;
        }
        solve(n, aux);
    }
    return 0;
}

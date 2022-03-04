#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;


#define int long long

const int loga = 70;

signed main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int x;
        cin >> x;
        if(x == 1){
            set<int> v;
            for (int j = 0; j < n; j++){
                int a;
                cin >> a;
                if (v.find(a) == v.end()){
                    v.insert(a);        
                }else{
                    v.erase(a);
                }
            }
            cout << v.size() << endl;
            for (auto num : v){
                cout << num << ' ';
            }
            continue;
        }
        int zero_cnt = 0;
        map<int, vector<int>> mp;
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            if (a == 0){
                zero_cnt++;
                continue;
            }
            int p = 0;
            while (a % x == 0){
                p++;
                a /= x;
            }
            if (mp.find(a) != mp.end()){
                mp[a][p]++;
            } else {
                mp[a] = vector<int> (loga);
                mp[a][p]++;
            }
        }
        vector<int> res;
        for (auto [w, v] : mp){
            int p = 1;
            for (int j = 0; j < loga -1; j++){
                int dec = min(v[i], v[i+1]);
                v[i] -= dec;
                v[i+1] -= dec;
                for (int k = 0; k < v[j]; j++){
                    res.push_back(w * (p * x));
                }
                p *= x;             
            }
            for (int k = 0; k < v[loga - 1]; k++){
                res.push_back(w * (p * x));
            }
        }
        if (zero_cnt % 2 == 1){
            res.push_back(0);
        }
        cout << res.size() << endl;
    }  
}

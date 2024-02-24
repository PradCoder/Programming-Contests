#include <set>
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;
typedef vector<int> vi;
typedef set<int> si;

inline void printVec(vi &v){
        cout << v.size() << "\n";
        for (int i = 0; i < v.size()-1; i++)
            cout << v[i] << " ";
        cout << v.back() << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	unsigned long n, res;
    cin >> n;
    if ( n * (n+1) % 4 != 0){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vi v1,v2;
        res = (n*(n+1))>>2;
        for (int i = n; i >= 1; i--){
            if (res >= i){
                   res = res-i;
                   v1.push_back(i);
                   continue;
            }else{
                   v2.push_bac (i);
            }
        }
        printVec(v1);
        printVec(v2);
    }
    return 0;
}

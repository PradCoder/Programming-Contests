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

bool solve(int n,string s){
    bool strong = true;
    for(int i = 0; i < n; i++){
        if((0 <= s[i]-'0' && s[i]-'0' <= 9) || (0 <= s[i]-'a' && s[i]-'a' <= 25)){
            strong = true;
        }else{
            return false;
        }
    }
    for(int i=0; i < n-1; i++){
        if((0 <= s[i]-'a' && s[i]-'a' <= 25) && (0 <= s[i+1]-'0' && s[i+1]-'0' <= 9)){
            return false;
        }else{
            strong = true;
        }
    }

    for(int i = 0; i < n-1; i++){
        int num1 = s[i]-'0';
        int num2 = s[i+1]-'0';
        if((0 <= num1 && num1 <= 9) && (0 <=  num2 && num2 <= 9)){
            if(num1<=num2){
                strong = true;
            }else{
                return false;
            }
        }
    }

    for(int i = 0; i < n-1; i++){
        int num1 = s[i]-'a';
        int num2 = s[i+1]-'a';
        if((0 <= num1 && num1 <= 25) && (0 <=  num2 && num2 <= 25)){
            if(num1<=num2){
                strong = true;
            }else{
                return false;
            }
        }
    }

    return strong;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
    
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        cout << (solve(n,s) ? "YES" : "NO") << endl;
    }
    
    return 0;
}


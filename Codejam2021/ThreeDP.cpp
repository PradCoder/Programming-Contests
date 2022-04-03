#include "bits/stdc++.h"
#include <cstdint>

using namespace std;

bool cmp(pair<string,int> &a, pair<string,int> &b){
    return a.second > b.second;
}
void solve(vector<vector<int>> v){
   int mCi = min(min(v[0][0],v[1][0]),v[2][0]);
   int mMi = min(min(v[0][1],v[1][1]),v[2][1]);
   int mYi = min(min(v[0][2],v[1][2]),v[2][2]);
   int mRi = min(min(v[0][3],v[1][3]),v[2][3]);
   if(mCi+mMi+mYi+mRi<1e6){
        printf("IMPOSSIBLE");
   }else{
        vector<int> mv = {mCi, mMi, mYi, mRi};
        int dif = mCi+mMi+mYi+mRi - 1e6;
        map<string,int> ms;
        vector<pair<string,int>> mx = {{"mCi", mv[0]},
                                       {"mMi", mv[1]},
                                       {"mYi", mv[2]},
                                       {"mRi", mv[3]}};
        for(pair<string,int> psi : mx){
               ms[psi.first] = psi.second;
        }
        if(dif > 0){
           sort(mx.begin(),mx.end(),cmp);
           for(int i = 0; i < mx.size(); i++){
               if(dif != 0){
                    if(mx[i].second < dif){
                       dif = dif - mx[i].second;
                       mx[i].second = 0;
                    }else{
                       mx[i].second = mx[i].second - dif;
                       dif = 0;
                    }
                }    
           } 
           for(pair<string,int> psi : mx){
               ms[psi.first] = psi.second;
           }
        }
           printf("%d %d %d %d",ms["mCi"],ms["mMi"], ms["mYi"], ms["mRi"]);
   }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t;
    vector<vector<int>> v = vector<vector<int>>(3,vector<int>(4,0));
    cin >> t;
    for(int i = 1; i <= t; i++){
        for(int j = 0; j< 3;j++){
            for(int k = 0; k < 4; k++){
                cin >> v[j][k];
            }
        }
        printf("Case #%d: ",i);
        solve(v);
        printf("\n");
    }
    return 0;
}


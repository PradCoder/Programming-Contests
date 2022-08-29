#include "bits/stdc++.h"

using namespace std;

int solve(int ans, int x, int y, int n, int m, vector<vector<int>> ans){
     if(){
        if((x >= 0 && x < m) && (y >= 0 && y < n){
                
        }
     }else{
         return min(solve(x,y+1,ans)+solve(x+1,y,ans)+solve(x,y-1,ans)+solve(x-1,y,ans));
     }
}

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(m,0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int x = i+1;
                int y = j+1;
                if((abs(x - sx) + abs(y - sy)) <= d){
                    ans[i][j] = 1; 
                }else{
                    ans[i][j] = 0;
                }
            }
            solve(0, sx, sy, n, m, ans);
        }
            
        /*
         s 0 1 0 0
         0 1 1 1 0
         1 1 x 1 1
         0 1 1 1 0
         0 0 1 0 e
         seems generative
         */ 
    }
    return 0;
}

#include "bits/stdc++.h"

using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<string>> strs = vector<vector<string>>(3,vector<string>(n,""));
        map<string,vector<bool>> dict;
        vector<int> score(3,0);
        for (int i = 0; i < 3; i++) {
            for(int j = 0; j < n; j++){
                cin >> strs[i][j];
                auto it = dict.find(strs[i][j]);
                if(it != dict.end()){
                    dict[strs[i][j]] = vector<bool>(3,false);
                }
                dict[strs[i][j]][i] = true;
            }
        }

       for (const auto &entry : dict) {
           if(entry.second[0] == entry.second[1] == entry.second[2]){
                continue;
           }else if(entry.second[0] == entry.second[1]){
                score[0] += 1; score[1] += 1;
           }else if(entry.second[0] == entry.second[2]){
                score[0] += 1; score[2] += 1;
           }else if(entry.second[2] == entry.second[1]){
                score[2] += 1; score[1] += 1;
           }else{
                if(entry.second[0]){
                    score[0] += 3;
                }else if(entry.second[1]){
                    score[1] += 3;
                }else if(entry.second[2]){
                    score[2] += 3;
                }
           }
       } 
       for (int i = 0; i < 2; i++){
            cout << score[i] << " ";
       } cout << score[2] << "\n";
    }
    return 0;
}

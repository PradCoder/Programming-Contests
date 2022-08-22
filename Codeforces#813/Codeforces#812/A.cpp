#include "bits/stdc++.h"
 
using namespace std;
 
bool compare(pair<int,int> a, pair<int,int> b){
    return (a.second < b.second);
}

int solve(vector<pair<int,int>> a){
    //find mag
    int n = a.size();
    int x, y;
    vector<pair<int,int>> weights = vector<pair<int,int>> (n,{0,0});
    for (int i = 0; i < n; i++){
        x = a[i].first;
        y = a[i].second;
        int dist = abs(x-0)+abs(y-0);
        weights[i] = {i,dist};
    }

    sort(weights.begin(),weights.end(), compare);
    pair<int,int> first_node = a[weights[0].first]; 
    vector<pair<int,int>> direction;
    direction.push_back(first_node);
    weights.erase(weights.begin());

    while(!weights.empty()){
        weights = vector<pair<int,int>>(weights.size(),{0,0});

        for (int i = 0; i < n; i++){
            x = a[i].first;
            y = a[i].second;
            int dist = abs(x-0)+abs(y-0);
            weights[i] = {i,dist};
        }
        
        sort(weights.begin(),weights.end(), compare);
        pair<int,int> first_node = a[weights[0].first]; 
        direction.push_back(first_node);
        weights.erase(weights.begin());
    }

    int dist = 0;
    for(int i = 0; i < n-1; i++){
        dist += abs(direction[i].first-direction[i+1].first) + abs(direction[i].second-direction[i+1].second);
    }
    return dist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t, n; 
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<int,int>> a(n,{0,0});
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    cout << solve(a) << "\n";
  }
     
}

/*Tree Algorithms*/

#include <bits/stdc++.h>
using namespace std;

const int N =8;
vector<int> adj[N];
//Tree traversal
void dfs(int s, int e){
    //process node s
    for (auto u : adj[s]){
        if(u != e) dfs(u,s);
    }
}

//dynamic programming dfs for counting number of nodes of subtrees
int count1[N]; 
void dfs(int s, int e){
    count1[s] = 1;
    for(auto u : adj[s]){
        if( u==e) continue;
        dfs(u,s);
        count1[s] += count1[u];//the leaf nodes have 1 at the very end 
        //and the previous node consists of the leaf nodes thus it's count
        //consists of the leaf nodes and thus it recursively goes up the tree
    }
}

int main(){
    //start search at node x the root node
    int x = 1;
    dfs(x,0);
    //TODO: Compleltely implement diameter algorithms
    //TODO: Implement Longest paths algorithms
    
    return 0;
}

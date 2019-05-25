/*Graph Traversal*/
//TODO: Complete implementation of Algorithms
#include <bits/stdc++.h>

using namespace std;

const int N = 8;
vector<int> adj[N];
bool visited[N];

//DFS -Assume graph is in adjacency list
void dfs(int s){
    if (visited[s]) return;
    visited[s] = true;
    //process node s;
    for (auto u : adj[s]){
        dfs(u);
    }
}

//BFS-Assume that the graph is in an adjacency list
queue<int> q;
bool visited1[N];
int distance1[N];

void bfs(int x){
    visited1[x] = true;
    distance1[x] = 0;
    q.push(x);
    while(!q.empty()){
        int s = q.front(); q.pop();
        //process nodes s
        for(auto u: adj[s]){
            if(visited1[u]) continue;
            visited1[u] = true;
            distance1[u] = distance1[s]+1;
            q.push(u); 
        }
    }
}

int main(){ 

    /*TODO: implement an example of connectivity check,
    Finding cycles, Bipartiteness check
    
    Note: if a component contains c nodes it must have exactly c-1
    edges for it to not be a cycle.

    For the general case of graph coloring it is difficult to find out
    if the nodes in a graph can be colored using k colors so that no adjacent
    nodes have the same color - no efficient algorithm exists for k=3 and the 
    Problem in NP hard (Important question - can machine learning yield substantially
    accurate answers for NP hard problems? DNN's can find good solution for NP hard
    problems such as Facial Recognition). 

    Google works because of the Perron-Frobenius theorem

    */
    return 0;
}
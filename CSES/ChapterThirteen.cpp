/*Shortest Paths*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    //TODO: Fully implement Belmann-Ford algorithm
    //assumes that the graph is stored as an edge list
    const int INF = pow(2,sizeof(int)-1)-1;//ideally the max weight+1
    int n =0;
    //cin>>n;
    int distance[n];
    vector<tuple<int,int,int>>edges;
    edges.push_back({1,2,5});
    edges.push_back({2,3,7});
    edges.push_back({2,4,6});
    edges.push_back({3,4,5});
    edges.push_back({4,1,2});
    int x = 0;//start node
    for(int i =1;i<=n;i++) distance[i] = INF;
    distance[x] = 0;
    for(int i=1;i<=n-1;i++){
        for(auto e: edges){
            int a,b,w;
            tie(a,b,w) = e;
            distance[b] = min(distance[b],distance[a]+w);
        }
    }
    //Negative cycles - a negative cycle can be detected by running Bellman-Ford n rounds
    //if the last round reduces the any distance they there exists a negative cycle
    /*
    TODO: SPFA Algorithm (Shortest Path Faster Algorithm): variant of the Bellman-Ford
    */

    //Dijkstra's Algorithm
    /*TODO: Completely implement Dijkstra's Algorithm*/
    //Graph is stored as adjacency list
    vector<pair<int,int>> adj[n];
    priority_queue<pair<int,int>> q;
    for(int i =1;i<=n;i++) distance[i] = INF;
    bool processed[n];
    distance[x] = 0;
    q.push({0,x});
    while(!q.empty()){
        int a = q.top().second; q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for (auto u:adj[a]){
            int b = u.first, w = u.second;
            if(distance[a]+w<distance[b]){
                distance[b] = distance[a]+w;
                q.push({-distance[b],b});
            }
        }
    }
    //instead of using negative distances because c++ sorts the priority
    //queue in descending order by default the priority queue can be implemented
    //thus
    priority_queue<int,vector<int>,greater<int>> q;//sort in ascending order
    //This implementation would be a bit longer
    //TODO: implement Dijkstra's with this queue aswell

    /*
    Floyd-Warshall algorithm
    Fully Implement it
    */
    int distance1[n][n];
    int adj1[n][n];
    //Initialize distances
    for(int i=1;i<=n;i++){
        for (int j = 1; i <=n; j++){
            if(i==j) distance1[i][j] = 0;
            else if (adj1[i][j]) distance1[i][j] = adj1[i][j];
            else distance1[i][j] = INF;
        }
    }
    //compute the distances
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                distance1[i][j] = min(distance1[i][j],distance1[i][k]+distance1[k][j]);
            }
        }
    }
    //not very scalable
    return 0;
}

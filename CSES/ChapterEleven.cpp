/*Basics of Graphs*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    typedef vector<int> vi;
    /*A graph consists of nodes and edges*/

    //Adjacency list representation
    //Indicates the neighboring nodes for a given node
    int N=4;
    //scanf("%d\n",&N);
    N++;//for cheaper one based indexing
    vi adj[N];//N is the number of nodes
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);
    adj[4].push_back(1);
    //weighted graph
    vector<pair<int,int>> adj1[N];
    adj1[1].push_back({2,5});
    adj1[2].push_back({3,7});
    adj1[2].push_back({4,6});
    adj1[3].push_back({4,5});
    adj1[3].push_back({4,2});
    int s = 1;
    for(auto u: adj1[s]){
        //process node u
    }

    /*Adjacency matrix representation*/
    //connectivity
    //Indicates which edges the graph contains
    int adj2[N][N] = {
        {0,1,0,0},
        {0,0,1,1},
        {0,0,0,1},
        {1,0,0,0}
    };
    //weighted format
    int adj3[N][N] = {
        {0,5,0,0},
        {0,0,7,6},
        {0,0,0,5},
        {2,0,0,0}
    };

    //Edge List representation
    //conatains all edges in some order: good for complete traversal
    vector<pair<int,int>> edges;
    edges.push_back({1,2});
    edges.push_back({2,3});
    edges.push_back({2,4});
    edges.push_back({3,4});
    edges.push_back({4,1});
    //with weights
    vector<tuple<int,int,int>> edges1;
    edges1.push_back({1,2,5});
    edges1.push_back({2,3,7});
    edges1.push_back({2,4,6});
    edges1.push_back({3,4,5});
    edges1.push_back({4,1,2});
    return 0;
}

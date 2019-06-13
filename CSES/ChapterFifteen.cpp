/*Spanning trees*/
#include <bits/stdc++.h>

using namespace std;

const int N = 8;
int n = N;
int link[N];int size1[N];
//comparison function for sorting
bool myfunction(tuple<int,int,int> node1,tuple<int,int,int> node2){
    int i,j;
    tie(ignore,ignore,i)=node1;
    tie(ignore,ignore,j)=node1;
    return(i<j);
}

int main(){
    /*TODO: fully implement Kruskal's algorithm*/
    vector<tuple<int,int,int>>edges;
    edges.push_back({1,2,3});
    edges.push_back({1,5,5});
    edges.push_back({2,3,5});
    edges.push_back({5,6,2});
    edges.push_back({3,4,9});
    edges.push_back({6,4,7});
    sort(edges.begin(),edges.end(),myfunction);
    //Implementation
    /*
    TODO: make a function same to identify if two nodes are in the same component
            make a function to unite two different cimponents
    The functions can be implemented using graph traversal but it would be slower
    than if union-find was used
    */ 
    for(...){
        if(!same(a,b)) unite(a,b);
    }
    //Union find implementation 
    //TODO: Integrate with partially completed Kruskal's
    for(int i=1;i<=n;i++) link[i]=i;
    for(int i=1;i<=n;i++) size1[i]=1;

    /*Prim's Algorithms*/
    //TODO: Full implementation
    
    return 0;
}

int find(int x){
    while(x!=link[x]) x = link[x];
    return x;
}

bool same(int a,int b){
    return find(a) == find(b);
}

void unite(int a,int b){
    a = find(a);
    b = find(b);
    if(size1[a]<size1[b]) swap(a,b);
    size1[a]+= size1[b];
    link[b] = a;
}

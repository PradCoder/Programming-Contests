#include "bits/stdc++.h"
#include <algorithm>
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

const ll INF = 1e18;
const int32_t M = 1e9+7;
const int32_t MM=998244353;

vi parent;
int components;

int find(int node){
    if (parent[node] != node)
        parent[node] = find(parent[node]);
    return parent[node];
}

void union_set(int node0, int node1){
    int parentOfNode0 = find(node0);
    int parentOfNode1 = find(node1);

    if (parentOfNode0 != parentOfNode1){
        parent[parentOfNode0] = parentOfNode1;
        components--;
    }
}

void solve(int node0, int node1){
    bool beforeU = false;
    if(find(node0) == find(node1)){
        beforeU = true;
    }
    union_set(node0, node1);
    printf("%d", components);
    if(beforeU){
        printf(" CYCLE FORMED!");
    }
    printf("\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
    cin >> n;
    components = n;
    parent = vi(n);
    REP0(i,0,n){
        parent[i] = i;
    }
    int a,b;
    while(1){
        if(!(cin >> a >> b)) break; 
        solve(a-1,b-1);
    }
}


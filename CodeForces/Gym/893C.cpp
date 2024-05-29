#include "bits/stdc++.h"
#include <cstdint>
#include <set>

using namespace std;
typedef long long ll;
typedef long long ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

class UF{
    private:
        int count;
        unsigned int *cost;
        vector<int> id;
        set<unsigned int> components;

    public:
        UF(int n, unsigned int* costs){
            count = n;
            id = vector<int>(n,0);
            cost = costs;
            for(int i = 0; i < n; i++){
                id[i] = i;
            }
        }

        int getCount(){
            return count;
        }

        unsigned int* getCostList(){
            return cost;
        }

        unsigned long long getCostVal(){
            unsigned long long sum = 0;
            for (int i : components){
                sum += cost[i];
            }
            return sum;
        }

        void setCost(){
            for(int i = 0 ; i < id.size(); i++){
                components.insert(id[i]);
            }
        }

        bool connected(int p, int q){
            return find(p) == find(q);
        }

        int find(int p){
            while( p != id[p] ){
                p = id[p];
            }
            return p;
        }

        void combine(int p, int q){
            int i = find(p);
            int j = find(q);

            if(i == j){
                return;
            }

            if(cost[i] <= cost[j]){
                id[j] = i;
            }else{
                id[i] = j;
            }
            count--;
        }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    unsigned int characterCost[n];
    for(int i = 0; i < n;i++){
        cin >> characterCost[i];
    }
    UF graph(n,characterCost);
    for(int i = 0; i < m; i++){
        int friend1, friend2;
        cin >> friend1 >> friend2;
        graph.combine(friend1-1,friend2-1);
    }
    graph.setCost();
    cout << graph.getCostVal() << endl;
    return 0;
}
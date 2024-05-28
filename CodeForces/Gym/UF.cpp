#include <iostream>

using namespace std;

class UF{
    private:
        int *id, *sz,count;

    public:
        UF (int n){
            count = n;
            id = new int[n];
            sz = new int[n];
            for(int i = 0; i < n; i++){
                id[i] = i;
                sz[i] = 1;
            }
        }

        int getCount(){
            return count;
        }

        bool connected(int p, int q){
            return find(p) == find(q);
        }
    
        int find(int p){
            while(p != id[p] ){
                p = id[p];
            }
            return p;
        }

        void combine(int p, int q){
            int i = find(p);
            int j = find(q);
            
            if (i==j) {
                return;
            }

            if (sz[i] < sz[j]){
                id[i] = j;
                sz[j] += sz[i];
            }else{
                id[j] = i;
                sz[i] += sz[j];
            }
            count--;
        }

};

int main(){
    int n;
    cin >> n;
    UF uf = UF(n);
    int p,q;
    while(cin >> p >> q){
        if(uf.connected(p,q)) continue;
        uf.combine(p,q);
        printf("%d %d\n", p,q);
    }
    printf("%d components\n", uf.getCount());
    return 0;
}
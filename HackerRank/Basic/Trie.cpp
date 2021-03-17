#include "bits/stdc++.h"
#include <cstddef>
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

typedef struct node node;

struct node{
    int cur;
    node* child[2];

    node(){
       cur = 0;
       REP0(i,0,2)
           child[i] = NULL;
    }
};

/*Add a bits then search greedly for the negation*/
node* root = new node();

int resetbit(int a, int i){
    return a & ~(1<<i);
}

int setbit(int a, int i){
    return a | (1<<i);
}

bool check(int mask, int i){
    return mask & (1<<i);
}

void insert(int num, int i, node* root){
    node* crawl = root;
    while(i>=0){
            int id = check(num,i);
                
            if(crawl->child[id] == NULL){
                node* t = new node();
                crawl->child[id] = t;
            }
            crawl->child[id]->cur++;
            i--;
            crawl = crawl->child[id];
    }
}

void delet(int num, int i, node* root){
    node* crawl = root;
    while(i>=0){
        int id = check(num,i);
        crawl->child[id]->cur--;
        i--;
        crawl=crawl->child[id];
    }
}

int query(int num, int i, node* root){
    node* crawl = root;
    int ans = num;
    while(i>=0){
        int id = 1-check(num,i);
        if(crawl->child[id] == NULL || crawl->child[id]->cur == 0){
            id = 1-id;
            ans = resetbit(ans,i);
        }else{
            ans = setbit(ans,i);
        }
        i--;
        crawl = crawl->child[id];
    }
    return ans;
}

void solve(char q, int h){
    if(q == '+'){
        insert(h,31,root);
    }else if( q == '-'){
        delet(h, 31, root);
    }else{
        int ans = query(h, 31, root);
        printf("%d\n",ans);
    }    
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
    insert(0,31,root);
    cin >> n;
    REP0(i,0,n){
    	char q;
        int  h;
    	cin >> q >> h;        
        solve(q,h);
    }
}


/*Range queries*/

#include <bits/stdc++.h>

using namespace std;

int arr[1000];//array is a datastructure in the stl thus a keyword

//runs in O(n) time. With q queries it will run in O(nq) time
int sum(int a,int b){
    int s = 0;
    for(int i =0;i<=b;i++){
        s += arr[i];
    }
    return s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    TODO:
    Sum queries, Min/Max queries, Binary Indexed Trees (One Indexed), Segment trees,
    Index compression, Range updates
    
    NOTE: 
    For Min/Max queries to find the number of elements in the container take 
    find nlogn where n is the number of elements in the array (log n should be floored)

    Binary indexed trees assume 1 based indexing    

    Part of the implementation is already done ie: sum

    Segment trees are useful in finding sums,min/max and many more queries
    which can be branched into two paths 
    */
    
    return 0;
}


//Binary indexed tree implementation
string arr = "";
getline(cin,arr);
string spltstr[arr.size()];
split(spltstr,arr,is_any_of(" "));
int tree[arr.size()];
for (int i = 0;i<arr.size();i++){
    tree[i]=(int)arr[i];
}

int sum(int k){
    int s = 0;
    while(k>=1){
        s+=tree[k-1];
        k -= k&-k;
    }
    return s;
}

int n = arr.size();
void add(int k,int x){
    while(k<=n){
        tree[k-1] += x;
        k += k&-k;
    }
}
int a = 1;int b = 7;

for(int i =1;i<=n;i++){
    tree[i-1] = sum(i);
}

int ans = sum(b)-sum(a);

//Segment Tree
int sum(int a,int b){
    int n = n;
    a+=n; b+=n;
    int s = 0;
    while(a<=b){
        if(a%2 == 1) s += tree[a++];
        if(b%2 == 1) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

void add(int k,int x){
    k+=n;
    tree[k] += x;
    for (k/=2;k>=1;k/=2){
        tree[k] = tree[2*k]+tree[2*k+1];
    } 
}

//
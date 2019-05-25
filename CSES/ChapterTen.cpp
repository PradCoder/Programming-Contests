/*Bit Manipulation*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int hamming(int a, int b);

int main(){
    //Bit representation
    int x = -43;//-43
    unsigned int y = x; //4294967253
    cout << x << "\n";
    cout << y << "\n";

    x = 2147483647;
    cout << x << "\n";//2147483647
    x++;
    cout << x << "\n";//2147483648

    //Bit operations
    x = 22 & 26 ;//18
    cout << x << "\n";
    //more generally x is divisibly by pow(2,k) when x&(pow(2,k)-1) = 0
    x = 22 | 26; // 30
    cout << x << "\n";
    //Xor operation
    x = 22 ^ 26; // 12
    //not operation ~ inverts the bits
    //Bit shifts x>>k removes last k bits x<<k appends k zeros
    //x>>k means floor(x/pow(2,k)) x<<k means x*pow(2,k)

    /*bit representation printer*/
    x = 5328;//00000000000000000001010011010000 
    for (int i = 31; i >= 0; i--){
        if(x&(1<<i)) cout << "1";
        else cout << "0";
    }
    cout<<"\n";
    
    cout<< __builtin_clz(x) <<"\n";//19 number of init 0
    cout<< __builtin_ctz(x) << "\n";//4 number of tail 0
    cout<< __builtin_popcount(x) << "\n"; // 5 number of 1
    cout<< __builtin_parity(x) << "\n"; // 1 parity (odd or even) of ones

    //Representing Sets
    //set implementation
    //{1,3,4,8}
    x =0;
    x |= (1<<1); // x|(1<<k) sets the kth bit to one
    x |= (1<<3);
    x |= (1<<4);
    x |= (1<<8);
    cout << __builtin_popcount(x)<<"\n";//4
    //for printing the elements in the set
    for(int i = 0;i<32;i++){
        if(x&(1<<i)) cout <<i<<" ";
    }
    cout<<"\n";
    //intersection a&b
    //union a|b
    //complement ~a
    //difference a&(~b)

    x = (1<<1)|(1<<3)|(1<<4)|(1<<8);
    y = (1<<3)|(1<<6)|(1<<8)|(1<<9);
    int z = x|y;
    cout << __builtin_popcount(z)<<"\n"; // 6

    //Iterating through subsets
    //go through subset {0,1,..,n-1}
    int n = 0; //cin>>n;
    for(int b=0;b<(1<<n);b++){
        //process subset
    }

    int k =0;//cin>>k;
    for(int b =0;b<(1<<n);b++){
        if(__builtin_popcount(b) == k){
            //process subset b
        }
    }

    //go through the subsets of x
    int b =0;
    do{
        //process subset b
    }while((b=((b-x)&x)));

    //Hamming distance
    string a = "01101";string c = "11001";
    //(cin >> a);(cin>>c);
    int sum1 = 0;int sum2 = 0;
    for(unsigned int i=0;i<a.size();i++){
        sum1 = 2*sum1+(a[i])-'0';
        sum2 = 2*sum2+(c[i])-'0';
    }
    cout<<hamming(sum1,sum2)<<"\n";//2

    //Counting subgrids
    //TODO: Complete the algorithm so it can be used properly
    //initialize coloring, initialize I/O
    int color[2][2] = {{1,0},{0,1}};//color is the grid in an array form
    int count = 0;
    for(int i = 0;i<n;i++){
        if(color[a][i]==1 && color[b][i]==1) count++;
    }
    //using bit operations
    count = 0;
    //works in O(n^3/N)
    for(int i=0;i <= n/N;i++){
        count+= __builtin_popcount(color[a][i]&color[b][i]);// N can be anything
    }

    //Dynamic Programming
    /*TODO: complete the algorithm implementation and testing*/
    //Optimal selection, complexity O(n*2^k*k)
    int total[1<<K][N];//K products N days
    //cases for d =0
    for(int x =0;x<k;x++){//k=K
        total[1<<x][0] = price[x][0];
    }
    //recurrence
    for(int d=1;d<n;d++){
        for(int s =0;s<(1<<k);s++){
            total[s][d] = total[s][d-1];
            for(int x=0;x<k;x++){
                if(s&(1<<x)){
                    total[s][d] = min(total[s][d],total[s^(1<<x)][d-1]+price[x][d]);
                }
            }
        }
    }
    
    //Permutations to subsets
    //TODO: complete implementation
    //dynamic programming
    pair<int,int> best[1<<N];
    best[0] = {0,0};
    for(int s=1;s<(1<<n);s++){
        //initial value: n rides are needed
        best[s] = {n,0};
        for(int p=0;p<n;p++){
            if(s&(1<<p)){
                auto option = best[s^(1<<p)];
                if(option.second+=weight[p]<=x){
                    //add p to an existing ride
                    option.second += weight[p];
                }else{
                    //reserve a new ride for p
                    option.first++;
                    option.second = weight[p];
                }
                best[s] = min(best[s],option);
            }
        }
    }

    //counting subsets
    /*TODO: fully implement the following algorithm*/
    int sum[1<<N];
    for(int s =0;s<(1<<N);s++){
        sum[s] = value[s];
    }
    for(int k=0;k<n;k++){
        for(int s=0;s<(1<<n);s++){
            if(s&(1<<k)) sum[s] += sum[s^(1<<k)];
        }
    }
    return 0;
}

//Bit optimizations
//optimizations do not change the complexity but the running time of the algorithm

/*Hamming distance in O(n^2*k)*/
int hamming(string a, string b){
    int d = 0;int k =b.size(); 
    for (int i = 0; i < k; i++){
        if(a[i] != b[i]) d++;
    }
    return d;
}

//if k is small i.e: k<=32
int hamming(int a, int b){
    return __builtin_popcount(a^b); //30 times faster than the
}


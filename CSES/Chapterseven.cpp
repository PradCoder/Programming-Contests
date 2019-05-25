#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <limits>

using namespace __gnu_pbds;
using namespace std;

//Global variables
int INF = numeric_limits<int>::infinity();
vector<int> count = {}; vector<int> coins = {1,3,4};
int main(){
    /*Dynamic Programming*/
    /*It's a programming technique that combines the correctness of 
    complete search and the efficiency of greedy algorithms (so it's fast
    and correct or atleast tries to be (heehee)). There are two uses for
    dynamic programming:
        1.Finding an optimal solution.
        2.Counting the number of solutions.
    Understanding dynamic programming is a milestone in every competitive 
    programmer's career. The basic idea is simple, the challenge is how 
    to apply it in different problems.
    */
    /*Coin problem Revisited (from chapter 6 in cses and chapter)*/
    /*Recursive formulation*/

        /*Basic definition*/
    int solve (x){
        if(x<0) return INF;
        if(x==0) return 0;
        int best = INF;
        for (auto c : coins){
            best = min(best,solve(c-1)+1);
        }
        return best;
    }
        /*Optimized with memoization*/
        /*assume the inputs are integer values*/
    bool ready[N];
    int value[N];

    int solve(int x){
        /*base cases*/
        if(x<0) return INF;
        if(x==0) return 0;
        /*using memoization to state that a 
        solution for the case has been found*/
        if(ready[x]) return value[x];
        int best = INF;
        for (auto c: coins){
            best = min(best,solve(x-c)+1)
        }
        value[x] = best;
        ready[x] = true;
        return best;
    }

    /*iterative approach to coin counting problem*/
    value[0] = 0;
    for(int x=1;x<=n;x++){
        value[x]=INF;
        for(auto c:coins){
            if(x-c>=0){
                value[x] = min(value[x],values[x-c]+1);
            }
        }
    }

    /*solution construction*/
    int first[N];
    value[0] = 0;
    for (int x = 1;x<=1;x++){
        value[x] = INF;
        for(auto c:coins){
            if(x-c>=0 && value[x-c]+1<value[x]){
                value[x] = value[x-c];
                first[x] = c;
            }
        }
    }
    /*a way of showing the construction in terms of how it
    is dependent on previous calculations*/
    while(n>0){
        cout<<first[n]<<"\n";
        n-=first[n];
    }

    /*counting the number of solutions*/
    /*very straight forward comments*/
    long count[100000L]; 
    count[0] = 1;
    
    for(int x =1; x<=n;x++){
        for (auto c : coins){
            if(x-c >= 0){
                if(x-c >= 0){
                    count[x] += count[x-c]
                    /*for giving a congruent modulus*/
                    count[x] %= m;
                }
            }
        }
    }

    //Longest Increasing Subsequence
    /*TODO:find a way to do the code below in O(nlogn) time*/
    for (int k=0; k<n;k++){
        length[k] = 1;
        for (int i=0;i<k;i++){
            if(array[i]<array[k]){
                length[k] = max(length[k],length[i]+1);
            }
        }
    }
    
    /*Path in a grid*/
    int N = 0;
    cin >> N; //To get input is a viable  way
    int sum[N][N];
    sum[0][0] = 0; //these are for inits
    for (int y=1;y<=N;y++){
        sum[y][0]=0; //these are for inits
        for(int x=1;x<=N;x++){
            sum[y][x] = 0;sum[0][x] = 0; //these are for inits
            sum[y][x] = max(sum[y][x-1],sum[y-1][x])+value[y][x];
        }
    }

    /*Knapsack problems*/ 
    /*ierative arrays can be used to store results of a recursive function*/
    bool possible[0][0] = true;
    int n = arr.size();
    int W = arr.sum();
    for(int k=1;k<=n;k++){
        for(int x=0;x<=W;x++){
            if(x-w[k]>=0) possible[x][k] |= possible[x-w[k]][k-1];
            possible[x][k] |= possible[x][k-1];
        }
    }

    /*implementation with one dimensional array*/
    vector<int> possible = {true};
    int maxl = 0;//too find max
    possible.resize(w.sum()+1,false);//making the vector big enough
    possible[0] = true;
    for(int k=1;k<=n;k++){
        for(int x = W; x >= 0;x--){
            if(possible[x]) {
                possible[x+w[k]] = true;
                if(x>maxl)maxl=x;
            }
        }
    }
    cout<<maxl<<"\n"; //print max value

    /*Edit distance*/
    //Levenshtein distance
    //TODO algorithm -- DONE
    string xin= ""; string yin = "";
    getline(cin,xin);getline(cin,yin);//get inputs
    int a = xin.size();int b = yin.size();//get sizes
    vector<vector<int>> distance(a+1,vector<int>(b+1));//initialization
    distance[0][0] = 0;//initialzie the 0,0
    int cost = 0; // initialize cost
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
			if(i>0&&j>0){
                //calculate cost depending on letter
            	(xin[i-1]==yin[j-1]) ? (cost=0):(cost=1);
                //find the distance (the minimum)
				distance[i][j] = min({distance[i][j-1]+1,distance[i-1][j]+1,distance[i-1][j-1]+cost});
			}else{
                //For the 0th column and row
				if (i==0 && j > 0) distance[i][j] = distance[i][j-1] + 1;
				if (i>0 && j == 0) distance[i][j] = distance[i-1][j] + 1;
			}
        }
    }
    /*printing vector of vectors*/
    for(vector<int> xout : distance){
        for(int elem : xout){
            printf("%i ",elem);
        }
        printf("\n");
    }
	printf("Min edits: %i\n",distance[a][b]);

    /*Counting tilings*/
    //Create tilings using different 1X2 tiles
    //an algorithm can be used to find this that works in O(n2^(2m)) time if optimized
    //a formula can also create the solution though subject to floating point errors
	n = 4; int m=7; long double ans = 1;
    //cin>>n>>m;
    for(int a=1;a<=ceil(n/2);a++){
        for(int b=1;b<=ceil(m/2);b++){
            ans = ans*4*(pow((cos(M_PI*a/(n+1))),2)+pow((cos(M_PI*b/(m+1))),2));
        }
    }
    printf("%i \n",(int) ans);
    //TODO: Create a non-formulaic solution
    //good problems to read about if you are thinking about P vs NP problems
    return 0;
}

#include <bits/stdc++11.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

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
    to apply it in different problems.*/
    /*Coin problem Revisited (from chapter 6 in cses and chapter 5 in my 
    notes)*/
    /*The greedy algorithm works when the coins are the euro coins but in
    general is not the optimal solution. The dynamic programming approach
    creates the optimal solution for any coin set.*/
    /*The dynamic programming algorithm is based on a recursive function
    that goes through all possibilities (like a brute force algorithm).
    The dynamic programming algorithm is efficient because it uses
    memoization (storing outputs in memory to be used later)*/
    /*Recursive fomulation*/
    /*The dynamic programming idea is to formulate the problem recursively
    so that the solution can be found by the solutions to smaller subproblems.
    Thus the problem can be states as thus: "what is the smallest number of
    coins required to form a sum x?"*/
    /*let solve(x) be the function that is used to calculate the minimum
    number of coins from the set required to form a sum of x. Focus should
    be placed on the first coin that we choose for the sum, for when we 
    choose one coin we have to find the number of coins needed to form
    the remainder that is left (the subproblem). So if the set of coins is
    {1,3,4} the recursive formula can be given as follows:
                            solve(x) = min(solve(x-1)+1,
                                           solve(x-3)+1,
                                           solve(x-4)+1)
    The base case is set to solve(0) = 0. Now we create a general recursive
    function for the problem (my best attempt to write a piecewise function
    in comments):
                                    [infinitiy                 x<0 
                            solve(x)| 0                        x=0 
                                    [min (cEcoins) solve(x-c)+1  x>0  
    once a recursive function that solves the problem has been found we can
    implement a solution (basically turning the algorithm into an executable
    form)*/
    /*Define your constants with reasonable values*/
    int solve(int x){
        if(x < 0) return INF;//INF denotes infinity 
        if(x == 0) return 0;
        int best = INF;
        for (auto c : coins){
            best = min(best,solve(x-c)+1);
        }
        return best;
    }
    /*This algorithm is not the most efficient, because there may be an 
    exponential number of ways to construct the correct sum. To make
    the algorithm more efficient we implement memoization.*/
    /*Using memoization*/
    /*We store the values of the function in an array after calculating
    them so for each parameter the value is calculated only once 
    recursively. After the value is stored it can be accessed faster from
    the array*/
    /*The following arrays will be used:*/
    /*The constant N has been chosen so that all required vlaues
    fit in the arrays (or we could use a vector)*/
    bool ready[N]://states whether a solution has been calculated
    int value[N];//stores the solutions
    /*Function with memoization is shown below*/
    int solve(x){
        if(x<0) return INF;
        if (x==0) return 0;
        if (ready[x]) return value[x];//direct access
        int best = INF;
        /*coins can be a set or any othe data structure that supports 
        indexing*/
        for(auto c : coins){
            best = min(best,solve(x-c)+1);
        }
        value[x] = best;//stores value
        ready[x] = true;//stores state of whether x is in value[] 
        return best;
    }
    /*The time complexity of the algorithm is O(nk) where n is the target sum
     and k is the number of coins (n function calls (max) and k in the loop)*/
    /*We can also use an iterative approach for constructing the value[]
    that has values for the solve() from 0...n*/
    value[0] = 0;
    for(int x = 1; x <= n;x++){
        value[x] = INF;
        for (auto c : coins){
            if(x-c>=0){
                value[x] = min{value[x],value[x-c]+1};
            }
        }
    }
    /*The above implementation is more preferred, because it is shorter
    and has lower constant factors in runtime complexity, but it is often
    easier to think about dynamic programming approaches using recursion*/
    /*Constructing a Solution*/
    /*If we want to also construct an example of a how a solution can be 
    constructed we can declare another array array that indicates for each
    sum of money the first coin in the optimal solution*/
    int first[N];
    /*Then the algorithm can be modified*/
    value[0] =  0;
    for(int x = 1; x <= n; x++){
        value[x] = INF;
        for (auto c : coins){
            if (x-c >= 0 && value[x-c]+1 < value[x]){//comparison
                value[x] = value[x-c]+1;
                first[x] = c;
            }
        }
    }
    //print out all coins in the soluntion for a sum n
    while(n > 0){
        cout << first[n] << "\n";
        n=-first[n];
    }
    /*Counting the number of solutions*/
    /*Let us now consider another flavour of the coin problem where this time
    our task is to calculate the total number of ways to produce sum x*/
    /*Let solve(x) denote the number of ways we can form the sum x*/
    /*We define the recursive formula:
                                solve(x) = solve(x-1)+
                                           solve(x-3)+
                                           solve(x-4)
    The we generate the general recursive function as follows:
                               [ 0                        x<0
                    solve(x) = | 1                        x=0
                               [ sigma(cEcoins)solve(x-c) x>0      */
    //Below is the implementation
    count[0] = 1;
    for(int x =1; x<=n; x++){
        for(auto c: coins){
            if(x-c >= 0){
                count[x] += count[x-c];
            }
        }
    }
    /*sometimes the number of solutions can be large enough we'd only need
    a modulo m to do this the line:*/
    count[x] %= m;
    /*can be added after count[x] += count[x-c]*/

    /*Now we discuss more about dynamic programming*/
    /**Longest increasing subsequence**/
    /*The idea of the longest increasing subsequence problem is to find in an
    array of n elements the mmaximum-length sequence that increases from left
    to right.*/
    /*length(k) denote the length of the longest increasing subsequence that ends
    at position k. Thus, if we do the calculation for length(k) where 
    0<=k<=n-1 we will find out the length of the longest increasing subsequence
    it indicates the number of elements in the subsequence. To calculate a value
    of length(k) start with i<k for which array[i]<array[k] and length(i) is as
    large as possible. Then we know that length(k)=length(i)+1 (because 
    array[i]<array[k]),because this is an optimal way to add array[k] to a 
    subsequence. If there is no such position i, then length(k)=1 (because only
    array[k] exists). We can use dynamic programmming since all values can be
    calculated from previous values and we can genearate (complete search) the
    solution space*/
    for(int i = 0; i < n; i++) {
        length[i] = 1;
        for(int j = 0; j < i; j++){
            if (array[j]<array[i]) {
                length[i] = max(length[i],length[j]+1);
            }  
        }
    }
    /*It is also possible the algorithm more efficiently in O(nlogn) time.*/
    //TODO: Find a way to do this.
    
    /*Paths in a grid*/
    /*Find a path from the upper-left corner to the lower-right corner of an
    n X n grid, such that we only move down and right. Each square contains a
    positive integer and the path should contain the largest sum of these as 
    possible. Assume the rows and columns are numbered from 1 to n, and value[y][x]
    equals value of square(y,x). sum(y,x) is the function denotes the maximum
    sum on a path from the upper-left corner to square(y,x).*/
    /*The recursive formula is as follows: 
    sum(y,x)=max(sum(y,x-1),sum(y-1,x))+value[y][x]*/
    /*To start with we select the direction that maximizes the sum. We start
    with the basecase that sum(x,y) = 0 if y = 0 and x = 0. since the function has
    two parameters, the dynamic programming array also has two dimensions.*/
    for(int x=1;u<=n)
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            sum[y][x] = max(sum[y][x-1],sum[y-1][x])+value[y][x];
        }
    }
    /*Knapsack problems*/
    /*Knapsack in this case refers to sets of objects that are to be operated
    on in these types of problems, usually particular subsets with certain 
    properties have to be found. They can often be solved using dynamic 
    programming.*/
    /*The following is a Knapsack problem: Given a list of weights 
    [w1,w2,w3,w4...,wn] determine all sums that can be constructed using the 
    weights. For instance if the weights [1,3,3,5] are given the possible
    sums would be:
                    0,1,3,4,5,6,7,8,9,11,12
    To solve the problem, we focus on subproblems where we only use the 
    first k weights to construct sums. Let the function possible(x,k)=true if it
    is possible to construct a sum x using the first k weights, and otherwise
    possible(x,k)=false the recursive function can be given thus:
                    (the \/ means disjunction)
                    possible(x,k) = possible(x-wk,k-1)(\/)possible(x,k-1)
    We either use or not use wk in the sum(that is why we have a disjuncition)
    */
    return 0;
}

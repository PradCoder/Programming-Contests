/*Note to self do implementations of these algorithms by the end of this 
month*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

int main(){
    /*Greedy Algorithms*/
    /*A greedy algorithms constructs a solution to the problem by 
    always making the best choice at the moment and it doesn't take
    back its choices and thus it directly constructs the final solution.
    For this reason greedy algorithms are very efficient.*/
    /*Note: it can be difficult to prove that a greedy algorithm always
    works, if it doesn't then we will have to use other programming 
    techniques.*/

    /*Greedy algorithms can be used to solve scheduling problems*/
    /*The greedy approach would be to choose the next event that
    ends as early as possible*/

    /*Tasks and Deadlines*/
    /*For each task we are given d-x points where d is the deadline
    and x is the moment when we finish the task. The goal is to maximize
    score.*/
    /*Surprisingly, the optimal solution to the problem does not depend 
    on the deadlines at all, but the correct greedy strategy to perform
    the tasks in sorted durations by oder. This is becuase the length of
    the longer task minus the length of the smaller task is greater than 
    0 thus the points gained is maximized (which shows that the solution
    is optimal)*/

    /*Minimizing sums*/
    /*We are given n numbers a1,a2,a3,...,an and our task is to find a value
    x that minimizes the sum: |a1-x|^c+|a2-x|^c...+|an-x|^c. Focus on c=1 and
    c=2*/
    /*Case c=1*/
    /* In this case the sum becomes |a1-x|+|a2-x|...+|an-x|. For example if
    we were given {1,2,9,2,6} the best number for x would be the median after
    the list is sorted (in this case two). The median s the optimal choice,
    because if x is smaller than the median. The median is an optimal choice
    because it is not too far and not too close the extremes (as x approaches
    the median from both sides the sum decreases). If n is even and there
    are two medians, both those medians and all values between then are
    optimal choices (since you still get the same sum at the end with the
    values moved around)*/
    /*Case c=2*/
    /*In this case the sum becomes: |a1-x|^2+|a2-x|^2...+|an-x|^2. If the
    list ist is same as before (as in {1,2,9,2,6}) then the best solution is
    to set x=4. So generally x should be set to the average (mean) of the set.
    The result can be derived by presenting the sum as follows:
    nx^2-2x(a1+a2+...+an)+(a1^2+a2^2+...+an^2) which is just the sum expanded
    and distributed into pieces of a quadratic formula. The parts that don't
    depend on x are excluded in the derivation leaving nx^2-2xs where s
    is the sum of a1..an and the parabola has roots at x=0 and x= 2s/n and
    the minimum value is the average of the two (the middle x value) or
    x =s/n to be more specific, which is the average of the numbers.*/

    /*Data compression*/
    /*A binary code assigns for each character of a string a codeword that
    consists of bits. we can compress a string by replacing the characters
    by there corresponding binary codes. Take the following example:
                                A --> 00
                                B --> 01
                                C --> 10
                                D --> 11
    This is constant-length code because the length of each codeword is the 
    same. A better approach is by using variable-length code where codewords
    may have different lengths. Then we can give short codewords for characters
    that appear often and long codewords for characters that appear rarely.
    We require that no codeword is a prefix of another codeword. For
    example it is not allowed that a code would contain bothe codewords 10 and
    1011. This is because it would lead to errors in decompressing*/
    /*Huffman coding*/
    /*Huffman coding is an optimal code for compressing a given string. The
    algorithm builds a binary tree based on the frequencies of the characters
    in the string, and each character's codeword can be read by following a
    path from the root to the corresponding node. A move to the left 
    corresponds to bit 0, and a move to the right corresponds to bit 1. At the
    beginning the chracters of the string are represented by nodes with
    weights equal to their character count. Then at each step two nodes with
    minimum weights (at the same level) are combined 
    by creating a new node that has its weight equal to the sum of 
    the weights of the original nodes, this process is continued until all 
    nodes have been combined. For example the Huffman coding for the string
    "AABACDACA" is as follows:
                                A -->0
                                B --> 110
                                C --> 10
                                D --> 111                        
                            
    */
    return 0;
}

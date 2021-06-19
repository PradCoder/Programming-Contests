/* FenwickTrees
 * For Prefix Sums
 *
 * */

#include "bits/stdc++.h"

#include <stdio.h>

using namespace std;

class BIT
{

    public:
        int size;
        vector<int> table;
        
        BIT(int s){
            table = vector<int>(s);
            size = s;
        }
    
        void update(int i, int delta){
            while (i < size){
                table[i] += delta;
                i += i&-i;
            }
        }

        int sum (int i){
            int sum = 0;
            while(i > 0){
                sum += table[i];
                i -= i&-i;
            }
            return sum;
        }

        int rangeSum(int i, int j){
            return sum(j) - sum(i - 1);
        }
};


int main(){
return 0;
}

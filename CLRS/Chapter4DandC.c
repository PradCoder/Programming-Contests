#include <stdlib.h>
#include <stdio.h>

#define INFINITY (1<<30)-1+(1<<30)

typedef struct Tuple{
    int max_l;
    int max_r;
    int sum;
} Tuple;

Tuple MaxCrossingSubarray(int A[],int low,int mid,int high);

Tuple MaxCrossingSubarray(int A[],int low,int mid,int high){
    int left_sum= INFINITY;
    int sum = 0;
    int max_left, max_right;

    for(int i=mid;i>=low;i--){
        sum = sum+A[i];
        if (sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = -INFINITY;
    sum = 0;

    for(int j=mid+1;j<high;j++){
        sum = sum+A[j];
        if(sum>right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    Tuple r = {max_left, max_right,left_sum+right_sum};
    return r;
}

int main(){
    return 0;
}
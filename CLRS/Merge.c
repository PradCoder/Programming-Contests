#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void Merge(int A[],int p,int q,int r);

void Merge(int A[],int p,int q,int r){
    int i,j,k;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1], R[n2+1];
    for(i=0;i<n1;i++)
        L[i] = A[p+i];
    for(j=0;j<n2;j++)
        R[i] = A[q+j+1];
    L[n1+1] = INFINITY;
    R[n1+1] = INFINITY;
    i = 0;
    j = 0;
    for(k=p;k<=r;k++)
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
}

int main(){
    FILE* fp = freopen("output.txt","w",stdout);
    int A[] = {1,0,2,9,3,8,4,7,5,6};
    int n = sizeof(A)/sizeof(A[0]);

    return 0;
}
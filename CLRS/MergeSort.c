#include <stdlib.h>
#include <stdio.h>

#define INFINITY (1<<30)-1+(1<<30)

void Merge(int A[],int p,int q,int r);
void MergeSort(int A[],int p,int r);

void Merge(int A[],int p,int q,int r){
    int i,j,k;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[100], R[100];
    for(i=0;i<n1;i++)
        L[i] = A[p+i];
    for(j=0;j<n2;j++)
        R[j] = A[q+j+1];
    L[n1] = INFINITY;
    R[n2] = INFINITY;
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

void MergeSort(int A[],int p,int r){
    if(p<r){
        int q =(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}
int main(){
    FILE* fp = freopen("output.txt","w",stdout);
    int A[] = {1,0,2,9,3,8,4,7,5,6};
    int n = sizeof(A)/sizeof(A[0]);
    int i;
    MergeSort(A,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    printf("%d",INFINITY);
    fclose(fp);
    return 0;
}
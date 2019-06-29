#include <stdlib.h>
#include <stdio.h>

#define INFINITY (1<<30)-1+(1<<30)

void Merge(int A[],int p,int q,int r);
void MergeSort(int A[],int p,int r);

void Merge(int A[],int p,int q,int r){
    int i,j,k;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[1000000],R[1000000];

    for(i=0;i<n1;i++)
        L[i] = A[p+i];
    for(j=0;j<n2;j++)
        R[j] = A[q+j+1];

    i=0,j=0;
    k=p;

    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(k<=r){
        if(i<n1){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    /* 
    Non-stop single loop also works but 
    not exactly what the book was suggesting I think
    since it said the procedure should stop
    for(k=p;k<=r;k++)
        if(L[i]<=R[j] && i<n1){
            A[k] = L[i];
            i++;
        }else if(L[i]>R[j] && j<n2){
            A[k] = R[j];
            j++;
        }else{
            if(i<n1){
                A[k] = L[i];
                i++;
            }else{
                A[k] = R[j];
                j++;
            }
        }
    */
}

void MergeSort(int A[],int p,int r){
    if(p<r){
        int q = (p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

int main(){
    FILE* fp = freopen("output.txt","w",stdout);
    int A[] = {3,41,52,26,38,57,9,49,7,5,6};
    int n = sizeof(A)/sizeof(A[0]);
    int i;
    MergeSort(A,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    fclose(fp);
    return 0;
}
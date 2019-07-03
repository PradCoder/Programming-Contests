/*
Author: Pesara Amarasekera
With some help from CLRS solution presented in: http://sites.math.rutgers.edu/~ajl213/CLRS/Ch2.pdf
I was able to build an inversions calculator using a modified Merge of my own making (it only works for ascending sorts though)
This is another one of my solutions to the CLRS Exercises in C
*/
#include <stdlib.h>
#include <stdio.h>

int Merge(int A[],int p,int q,int r);
int MergeSort(int A[],int p,int r);

/**
 * This Merge is of my own making but very much similar to that found in CLRS chapter 2
 */
int Merge(int A[],int p,int q,int r){
    int i,j,k;
    int n1 = q-p+1;
    int n2 = r-q;
    int Invs = 0;
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
            /*since we are sorting in ascending order*/
            Invs +=n1-i;
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
    return Invs;
}

/**
 * Very similar to the one found in:
 * http://sites.math.rutgers.edu/~ajl213/CLRS/Ch2.pdf
*/
int MergeSort(int A[],int p,int r){
    int Inv = 0;
    if(p<r){
        int q = (p+r)/2;
        Inv += MergeSort(A,p,q);
        Inv += MergeSort(A,q+1,r);
        Inv += Merge(A,p,q,r);
    }
    return Inv;
}

int main(){
    FILE* fp = freopen("output.txt","w",stdout);
    int A[] = {1,2,6,5,4,3};
    int n = sizeof(A)/sizeof(A[0]);
    int i;
    int Inv = MergeSort(A,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n%d",Inv);
    fclose(fp);
    return 0;
}    
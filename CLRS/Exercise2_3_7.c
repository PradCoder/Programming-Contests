#include <stdlib.h>
#include <stdio.h>

void Merge(int A[],int l,int m,int r);
void MergeSort(int A[],int l,int r);
int SumExist(int A[],int x,int n);

void Merge(int A[],int l,int m,int r){
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[1000000],R[1000000];

    for(i=0;i<n1;i++)
        L[i] = A[l+i];
    for(j=0;j<n2;j++)
        R[j] = A[m+j+1];

    i=0,j=0;

    for(k=l;k<=r;k++)
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
}

void MergeSort(int A[],int l,int r){
    int m = (l+r)/2;
    if(l<r){
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        Merge(A,l,m,r);
    }
}

int SumExist(int A[],int x,int n){
    int l=0;
    int r=n-1;
    while(l<r){
        if((A[l]+A[r])==x){
            return 1;
        }else if((A[l]+A[r])<x){
            l++;
        }else if((A[l]+A[r])>x){
            r--;
        }
    }
    return 0;
}

int main(){
    FILE* fp = freopen("output.txt","w",stdout);
    int A[] = {3,41,52,26,38,57,9,49,7,5,6};
    int n = sizeof(A)/sizeof(A[0]);
    int i;

    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");

    MergeSort(A,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");

    printf("Does Sum of 41 exist? ");
    if(SumExist(A,41,n)){
        printf("True\n");
    }else{
        printf("False\n");
    }

    fclose(fp);
    return 0;
}

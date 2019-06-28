#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE* fp = freopen("output.txt","w",stdout);
    int A[] = {1,0,2,9,3,8,4,7,5,6};
    int n = sizeof(A)/sizeof(A[0]);
    //selection sort
    for(int i=0;i<n-1;i++){
        int key = A[i];
        int minin = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<key){
                minin = j;
                key = A[j];
            }
        }
        int temp = A[i];
        A[i] = A[minin];
        A[minin] = temp;
    }
    for(int j=0;j<n;j++)
            printf("%d ",A[j]);
    fclose(fp);
    return 0;
}
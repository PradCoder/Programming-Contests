#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE* fp = freopen("output.txt","w",stdout);
    int A[] = {1,0,2,9,3,8,4,7,5,6};
    int n = sizeof(A)/sizeof(A[0]);
    //insertion sort
    for(int j=1;j<n;j++){
        int key = A[j];
        int i=j-1;
        while(i>-1&&A[i]>key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
    for(int j=0;j<n;j++)
        printf("%d ",A[j]);
    fclose(fp);
    return 0;
}
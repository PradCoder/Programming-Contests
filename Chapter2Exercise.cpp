#include <bits/stdc++.h>
using namespace std;

int main(){
    int A[] = {1,1,1,1,0};
    int B[] = {1,1,1,0,1};
    int n = sizeof(A)/sizeof(A[0]);
    int total = 0;
    int C[n+1]; 
    for(int j = 0;j<n;j++){
        total = total*2+A[j]+B[j];
    }
    for(int j=n; j>=0;j--){
        C[j] = total%2;
        total/=2;
    }
    for(int i=0;i<n+1;i++){
        printf("%d",C[i]);
    }
    printf("\n");
    return 0;
}
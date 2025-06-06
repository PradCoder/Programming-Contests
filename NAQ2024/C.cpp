#include "bits/stdc++.h"

int main(){
    int i;
    int count = 0;
    while(scanf("%d",&i)){
        if (i & 1){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}

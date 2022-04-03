#include "bits/stdc++.h"
#include <cstdint>


using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t,r,c;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
        scanf("%d %d",&r,&c);
        printf("Case #%d:\n",i);
        for(int i = 0; i < 2*r+1; i++){
            for(int j = 0; j< 2*c+1; j++){
                if(i<2 && j < 2){
                    printf(".");
                }else if (i % 2 == 0){
                    if(j%2 == 0){
                        printf("+");
                    }else{
                        printf("-");
                    }
                }else{
                    if(j%2 == 0){
                        printf("|");
                    }else{
                        printf(".");
                    }
                }
            }
            printf("\n");
        }
    }
}


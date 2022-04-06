#include "bits/stdc++.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
    int amt = 2*n+1;
    //I've definitely lost something important, speed and creativity
    //are essential for this task.
    for(int i = 0; i < amt/2+1; i++){
        for(int j = amt/2+1; j >= i; j++){
            printf(" ");
        }
        for(int j = 0; j < i+1; j++){
            printf("%d",j);
        }
        for(int j = i-1; j >= 0; j--){
            printf("%d",j);
        }
        printf("\n");
    }
    for(int i = amt/2-1; i >= 0; i--){
        for(int j = 0; j < i+1; j++){
            printf("%d",j);
        }
        for(int j = i-1; j >= 0; j--){
            printf("%d",j);
        }
        printf("\n");
    }
	return 0;	
}

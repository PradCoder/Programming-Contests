/*
ID: 2010pes1
TASK: transform
LANG: C++
*/

#include "bits/stdc++.h"
#include <cstdio>

using namespace std;

/*
#1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
#2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
#3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
#4: Reflection: The pattern was reflected horizontally (turned into a mirror 
    image of itself by reflecting around a vertical line in the middle of the image).
#5: Combination: The pattern was reflected horizontally and then subjected to one 
    of the rotations (#1-#3).
#6: No Change: The original pattern was not changed.
#7: Invalid Transformation: The new pattern was not obtained by any of the above methods.
*/

int mod(int n,int j){
    while(j < 0){
        j += n;
    }
    return (j % n);
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    ifstream input;
    ofstream output;

    int number, x, y, a, b, before[10][10, after[10[10], middle[10][10], same = 0;
    bool answer[6], five[3];
    string temp;
    
    input.open ("transform.in");
    input >> number;

    for(x = 0; x < 6 ; x++){
        answer[x] = false;
    }

    for(x = 0; x < 3 ;x++){
        five[x] = false;
    }

    for(x = 0; x < number; x++){
        input >> temp;
        for( y = 0; y < number; y++){
            after[x][y] = temp[y];
        }
    }

    input.close();

    //Test for #1
    for(x = 0; x < number; x++){
        for(y = 0; y < number; y++){
            if(before[y][x] == after[x][number-1-y]){
                same++;
            }
        }
    }

    if(same == number * number){
        answer[0] = true;
    }

    same = 0;

    //Test for #2
    for(x = 0; x < number; x++){
        for(y = 0;y < number;y++){
            if(before[y][x] == after[number-1-y][number-1-x]){
                same++;
            }
        }
    }

    if(same == number * number){
        answer[1] = true;
    }

    same = 0;

    //Test for #3
    for(x = 0; x < number; x++){
        for(y = 0; y < number; y++){
            if(before[y][x] == after[number-1-x][y]){
                same++;
            }
        }
    }

    if(same == number * number){
        answer[2] = true;        
    }

    same = 0;

    //Test for #4
    for(x = 0; x < number; x++){
        for(y = 0; y < number;y++){
            if(before[y][x] == after[y][number - 1 - x]){
                same++;
            }
        }
    }
    return 0;
}

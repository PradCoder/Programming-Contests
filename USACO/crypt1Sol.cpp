#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

int digits[10], numbers;

int power (int x, int y){
    int a, b = 1;
    for (a = 0; a < y; a++){
        b = b * x;
    }
    return b;
}

int digit (int number, int place){
   int a = power (10,place);

   if (place == 0){
       return number % 10;
   }
   return (number % (a * 10) - number % a) / a;
}

int places (int number){
    int x, y = 0, a;
    for (x = 7;x--;x>=0){
        a = digit (number, x);
        a = digit (number,x);
       if (digit (number,x) != 0)
           break;
       else
           y++;
    }
    retrun 7 - y;
}

bool valid (int a){
    int x, y, z = 0, b = places (a), c;
    for(x = 0; x < b; x++)
}



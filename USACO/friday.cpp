/*
ID: 2010pes1
TASK: friday
LANG: C++
*/
#include "bits/stdc++.h"
#include <cstdint>

#define F                   first
#define S                   second
#define PG                  push_back
#define PPB                 pop_back
#define PF                  push_front
#define MP                  make_pair
#define REP0(i,a,b)         for (int i = a; i < b; i++)
#define REP1(i,a,b)         for (int i = a; i <= b; i++)

#define PPC                 __builtin_popcount
#define PPCLL               __builtin_popcountll

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void solveNotLeap(int state, int &n, vi &days){
    int i = 1;
    //SEP,APR,JUN,NOV have 30, FEB has 28 except on leap years its 29
    for(int month = 1; month <= 12;){
        if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && i == 31){
             i = 0;
             month++;
        }else if (month == 2 && ((state == 0 && i == 28) || (state == 1 && i == 29))){
            i = 0;
            month++;
        }else if((month == 4 || month == 6 || month == 9 || month == 11) && i == 30){
            i = 0;
            month++;
        }
        if(i == 13){
          days[n%7] += 1;
        }
        i++;
        n++;
    }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    ifstream fin ("friday.in");
    ofstream fout ("friday.out");
    
    int n;
    fin >> n;
    vi days = vi(7);
    //January 1st 1900 was a Monday
    //SEP,APR,JUN,NOV have 30, FEB has 28 except on leap years its 29
    //All other months have 31
    //Every year evenly divisible by 4 is a leap year 
    //The above rule doesn't apply for century years not divisible by 400
    int day = 1;
    for(int i = 0 ; i < n; i++){
        if((1900+i)%4 == 0){
            if((1900+i)%100 == 0 && (1900+i)%400 == 0){
                solveNotLeap(1,day,days);
            }else if ((1900+i)%100 == 0 && (1900+i)%400 != 0){
                solveNotLeap(0,day,days);
            }else{
                solveNotLeap(1,day,days);
            }
        }else{
            solveNotLeap(0,day,days);
        }
    }
    
    for(int i = 0; i < 6; i++){
        fout << days[(i+6)%7] << " ";
    }
    fout << days[(6+6)%7] << "\n";
    return 0;
}

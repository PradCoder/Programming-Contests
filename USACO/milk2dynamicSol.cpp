/*
ID: 2010pes1
TASK: milk2
LANG: C++
*/

#include "bits/stdc++.h"
#include <cstdio>
#include <utility>

using namespace std;

/* So solving for longest interval works 
 * solve1: by scanning for the intersects of schedules 
 * solve2: by scanning for ranges 
 *         sort for start and end time (of first task)
 *         check if following ending time is below after first task end time
 *         take difference between current task being scanned and next task
 *
 * 100 200
 * 150 300
 * 200 400
 * 300 500
 * 400 600
 * 200 1000
 *
 * 100 200
 * 150 300
 * 200 400 
 * 200 1000
 * 2000 2900
 * 2400 2600
 *
 * s    e
 *    s       e
 *        s       e
 *             s      e
 *
*/

FILE *in, *out;

int main (){
    in = fopen("beads.in","r");
    out = fopen("beads.out","w");

    int n;
    char tmp[400], s[800];
    fscanf(in, "%d %s", &n, tmp);

    strcpy(s, tmp);
    strcat(s, tmp);

    int left[800][2], right[800][2];
    left[0][0] = left[0][1] = 0;

    for (int i=1; i<=2 * n; i++){
        if(s[i-1] == 'r'){
            left[i][0] = left[i-1][0]+1;
            left[i][1] = 0;
        } else if (s[i-1] == 'b'){
            left[i][1] = left[i-1][1]+1;
            left[i][0] = 0;
        } else {
            left[i][0] = left[i-1][0]+1;
            left[i][1] = left[i-1][1]+1;
        }
    }

    right[2*n][0] = right[2*n][1] = 0;
    for (int i=2*n-1; i >= 0; i--){
        if(s[i] == 'r'){
            right[i][0] = right[i+1][0]+1;
            right[i][1] = 0;
        }else if(s[i] == 'b'){
            right[i][1] = right[i+1][1]+1;
            right[i][0] = 0;
        }else{
            right[i][0] = right[i+1][0]+1;
            right[i][1] = right[i+1][1]+1;
        }
    }

    int m = 0;
    for(int i = 0; i<2*n;i++){
        m = max(m, max(left[i][0],left[i][1]) + max(right[i][0],right[i][1]));
    }
    m = min(m,n);
    fprintf(out,"%d\n",m);
    fclose(in); fclose(out);
    return 0;
}

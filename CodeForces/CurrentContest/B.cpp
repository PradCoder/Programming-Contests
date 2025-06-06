#include "bits/stdc++.h"
#include <math.h>

using namespace std;


double calc_or(double x1, double y1, double x2, double y2){
        double m,c;
        m = (y2-y1)/(x2-x1);
        c = y2 - x2*m;
        return c;
}

int main(){
    int n;
    cin >> n;
    double m = 1000;
    while(n--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        if ( 0 <= max(y1,y2) && (min(x1,x2) <= 0 && 0 <= max(x1,x2))){
            double val = calc_or(x1,y1,x2,y2);
            if ( m > val && val >= 0){
                m = calc_or(x1,y1,x2,y2);
            }
        }
    }

    if (m >= 999.0 || m < 0){
        cout << -1.0 << "\n";
    }else{
        cout << m << "\n";
    }
    return 0;
}

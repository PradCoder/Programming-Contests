#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
    int a,b,c;
    int a1,b1,c1;
    a1 = b1 = c1 = 0;
    while(n--){
        cin >> a >> b >> c;
        a1 += a, b1+= b, c1+= c;
    }
    if(!(a1 || b1 || c1)){
        cout << "YES\n";
    }else{
	    printf("NO\n");
    }
	return 0;	
}

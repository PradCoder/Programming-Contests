#include <stdio.h>

#define IN 1
#define OUT 0

main(){
int c, state;

while((c = getchar()) != EOF){
     if(!(c==' '|| c=='\n'|| c=='\t'))
         printf("#");
     if(c==' '|| c=='\n'|| c=='\t'){
        state = OUT;
        printf("\n");
     }
     else if((state==OUT) && !(c==' '|| c=='\n'|| c=='\t')) {
         state = IN;
     }
 }
}